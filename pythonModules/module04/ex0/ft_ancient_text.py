import io
import sys
import typing


def display_file(filename: str) -> None:
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")
    f: typing.TextIO
    try:
        f = open(filename, "r", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return
    try:
        print("---\n")
        while chunk := f.read(io.DEFAULT_BUFFER_SIZE):
            print(chunk, end="")
        print("\n---")
    except OSError as e:
        print(f"\nError reading file '{filename}': {e}")
    finally:
        f.close()
        print(f"File '{filename}' closed.")


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return
    display_file(sys.argv[1])


if __name__ == "__main__":
    main()
