import sys
import typing


def read_file(filename: str) -> str | None:
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")
    f: typing.IO[str]
    try:
        f = open(filename)
    except OSError as e:
        sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        return None
    lines: list[str] = []
    read_ok: bool = False
    try:
        print("---")
        print()
        line: str = f.readline()
        while line:
            print(line, end="")
            lines.append(line)
            line = f.readline()
        print()
        print("---")
        read_ok = True
    except OSError as e:
        sys.stderr.write(
            f"[STDERR] Error reading file '{filename}': {e}\n"
        )
    finally:
        f.close()
        print(f"File '{filename}' closed.")
    return "".join(lines) if read_ok else None


def transform(content: str) -> str:
    parts: list[str] = content.split("\n")
    tagged: list[str] = [p + "#" if p else p for p in parts]
    return "\n".join(tagged)


def write_file(filename: str, content: str) -> None:
    print(f"Saving data to '{filename}'")
    f: typing.IO[str]
    try:
        f = open(filename, "w")
    except OSError as e:
        sys.stderr.write(
            f"[STDERR] Error opening file '{filename}': {e}\n"
        )
        print("Data not saved.")
        return
    write_ok: bool = False
    try:
        f.write(content)
        write_ok = True
    except OSError as e:
        sys.stderr.write(
            f"[STDERR] Error writing file '{filename}': {e}\n"
        )
    finally:
        f.close()
    if write_ok:
        print(f"Data saved in file '{filename}'.")
    else:
        print("Data not saved.")


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_stream_management.py <file>")
        return
    content: str | None = read_file(sys.argv[1])
    if content is None:
        return
    transformed: str = transform(content)
    print()
    print("Transform data:")
    print("---")
    print()
    print(transformed, end="")
    print()
    print("---")
    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()
    name: str = sys.stdin.readline().rstrip("\n")
    if not name:
        print("Not saving data.")
        return
    write_file(name, transformed)


if __name__ == "__main__":
    main()
