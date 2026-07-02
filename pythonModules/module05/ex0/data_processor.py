from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._data_storage: list[str] = []
        self._process_rank: int = -1

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Validate input data for the data processor"""
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        """process the input data"""
        pass

    def output(self) -> tuple[int, str]:
        """output ingested data"""
        try:
            data: str = self._data_storage.pop(0)
            self._process_rank += 1
            return self._process_rank, data
        except IndexError as e:
            raise IndexError("No data to output") from e


class NumericProcessor(DataProcessor):
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
            self._data_storage.append(str(data))
        elif isinstance(data, list):
            self._data_storage.extend(str(item) for item in data)


class TextProcessor(DataProcessor):
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
            self._data_storage.append(data)
        elif isinstance(data, list):
            self._data_storage.extend(data)


class LogProcessor(DataProcessor):
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
            self._data_storage.append(": ".join(str(v) for v in data.values()))
        elif isinstance(data, list):
            self._data_storage.extend(
                ": ".join(str(v) for v in item.values()) for item in data
            )


def main() -> None:
    print("=== Code Nexus - Data Processor ===\n")
    print("Testing Numeric Processor...")
    numeric_processor = NumericProcessor()
    print(f" Trying to validate input '42': {numeric_processor.validate(42)}")
    print(
        f" Trying to validate input 'Hello': \
{numeric_processor.validate('Hello')}"
    )
    try:
        print(
            " Test invalid ingestion of string 'foo' without prior validation:"
        )
        numeric_processor.ingest("foo")
    except ValueError as e:
        print(f" Got exception: {e}")
    print(" Processing data: [1, 2, 3, 4, 5]")
    numeric_processor.ingest([1, 2, 3, 4, 5])
    print(" Extracting 3 values...")
    for _ in range(3):
        output = numeric_processor.output()
        print(f" Numeric value {output[0]}: {output[1]}")

    print("\nTesting Text Processor...")
    text_processor = TextProcessor()
    print(f" Trying to validate input '42': {text_processor.validate(42)}")
    print(" Processing data: ['Hello', 'Nexus', 'World']")
    text_processor.ingest(["Hello", "Nexus", "World"])
    print(" Extracting 1 values...")
    for _ in range(1):
        output = text_processor.output()
        print(f" Text value {output[0]}: {output[1]}")

    print("\nTesting Log Processor...")
    log_processor = LogProcessor()
    print(
        f" Trying to validate input 'Hello': \
{log_processor.validate('Hello')}"
    )
    print(
        " Processing data: ["
        "{'log_level': 'NOTICE', 'log_message': 'Connection to server'}, "
        "{'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]"
    )
    log_processor.ingest(
        [
            {"log_level": "NOTICE", "log_message": "Connection to server"},
            {"log_level": "ERROR", "log_message": "Unauthorized access!!"},
        ]
    )
    print(" Extracting 2 values...")
    for _ in range(2):
        output = log_processor.output()
        print(f" Log entry {output[0]}: {output[1]}")


if __name__ == "__main__":
    main()
