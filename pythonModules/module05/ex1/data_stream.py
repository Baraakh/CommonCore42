from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._data_storage: list[str] = []
        self._process_rank: int = -1
        self._total_ingested: int = 0

    @property
    @abstractmethod
    def name(self) -> str:
        """Human-readable processor name used in statistics"""
        ...

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Validate input data for the data processor"""
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        """process the input data"""
        pass

    def _store(self, items: list[str]) -> None:
        self._data_storage.extend(items)
        self._total_ingested += len(items)

    def output(self) -> tuple[int, str]:
        """output ingested data"""
        try:
            data: str = self._data_storage.pop(0)
            self._process_rank += 1
            return self._process_rank, data
        except IndexError as e:
            raise IndexError("No data to output") from e

    def stats(self) -> tuple[int, int]:
        """total items ingested, remaining items in storage"""
        return self._total_ingested, len(self._data_storage)


class NumericProcessor(DataProcessor):
    @property
    def name(self) -> str:
        return "Numeric Processor"

    def validate(self, data: Any) -> bool:
        """int, float, and lists of both types (including mixed-type lists)"""
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            return all(isinstance(item, (int, float)) for item in data)
        else:
            return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, (int, float)):
            self._store([str(data)])
        elif isinstance(data, list):
            self._store([str(item) for item in data])


class TextProcessor(DataProcessor):
    @property
    def name(self) -> str:
        return "Text Processor"

    def validate(self, data: Any) -> bool:
        """str and lists of str"""
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        else:
            return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, str):
            self._store([data])
        elif isinstance(data, list):
            self._store(data)


class LogProcessor(DataProcessor):
    @property
    def name(self) -> str:
        return "Log Processor"

    def validate(self, data: Any) -> bool:
        """dict of string key-value pairs, and lists of that type"""
        if isinstance(data, dict):
            return all(
                isinstance(k, str) and isinstance(v, str)
                for k, v in data.items()
            )
        elif isinstance(data, list):
            return all(
                isinstance(item, dict)
                and all(
                    isinstance(k, str) and isinstance(v, str)
                    for k, v in item.items()
                )
                for item in data
            )
        else:
            return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, dict):
            self._store([": ".join(str(v) for v in data.values())])
        elif isinstance(data, list):
            self._store(
                [": ".join(str(v) for v in item.values()) for item in data]
            )


class DataStream:
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for element in stream:
            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    break
            else:
                print(
                    "DataStream error - Can't process element in stream: "
                    f"{element}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
            return
        for proc in self._processors:
            total, remaining = proc.stats()
            print(
                f"{proc.name}: total {total} items processed, "
                f"remaining {remaining} on processor"
            )


def main() -> None:
    print("=== Code Nexus - Data Stream ===\n")

    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()

    print("\nRegistering Numeric Processor\n")
    numeric_proc = NumericProcessor()
    stream.register_processor(numeric_proc)

    batch: list[Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead",
            },
            {"log_level": "INFO", "log_message": "User wil is connected"},
        ],
        42,
        ["Hi", "five"],
    ]
    print(f"Send first batch of data on stream: {batch}")
    stream.process_stream(batch)
    stream.print_processors_stats()

    print("\nRegistering other data processors")
    text_proc = TextProcessor()
    log_proc = LogProcessor()
    stream.register_processor(text_proc)
    stream.register_processor(log_proc)
    print("Send the same batch again")
    stream.process_stream(batch)
    stream.print_processors_stats()

    print(
        "\nConsume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )
    for _ in range(3):
        numeric_proc.output()
    for _ in range(2):
        text_proc.output()
    for _ in range(1):
        log_proc.output()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()
