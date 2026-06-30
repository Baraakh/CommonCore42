import sys
import typing


def read_file(filename: str) -> str | None:
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")
    f: typing.TextIO
    try:
        f = open(filename, "r", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return None
    content: str = ""
    read_ok: bool = False
    try:
        content = f.read()
        print("---\n")
        print(content, end="")
        print("\n---")
        read_ok = True
    except OSError as e:
        print(f"\nError reading file '{filename}': {e}")
    finally:
        f.close()
        print(f"File '{filename}' closed.")
    return content if read_ok else None


def transform(content: str) -> str:
    lines: list[str] = content.split("\n")
    tagged: list[str] = [line + "#" if line else line for line in lines]
    return "\n".join(tagged)


def write_file(filename: str, content: str) -> None:
    print(f"Saving data to '{filename}'")
    f: typing.TextIO
    try:
        f = open(filename, "w", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return
    write_ok: bool = False
    try:
        f.write(content)
        write_ok = True
    except OSError as e:
        print(f"\nError writing file '{filename}': {e}")
    finally:
        f.close()
    if write_ok:
        print(f"Data saved in file '{filename}'.")


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
        return
    content: str | None = read_file(sys.argv[1])
    if content is None:
        return
    transformed: str = transform(content)
    print("\nTransform data:")
    print("---\n")
    print(transformed, end="")
    print("\n---")
    name: str = input("Enter new file name (or empty): ").strip()
    if not name:
        print("Not saving data.")
        return
    write_file(name, transformed)


if __name__ == "__main__":
    main()
