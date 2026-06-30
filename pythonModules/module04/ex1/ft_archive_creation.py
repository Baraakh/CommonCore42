import io
import sys
import typing


def display_original(filename: str) -> bool:
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")
    f: typing.TextIO
    try:
        f = open(filename, "r", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return False
    ok: bool = False
    try:
        print("---\n")
        while chunk := f.read(io.DEFAULT_BUFFER_SIZE):
            print(chunk, end="")
        print("\n---")
        ok = True
    except OSError as e:
        print(f"\nError reading file '{filename}': {e}")
    finally:
        f.close()
        print(f"File '{filename}' closed.")
    return ok


def display_transformed(filename: str) -> bool:
    f: typing.TextIO
    try:
        f = open(filename, "r", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return False
    ok: bool = False
    try:
        print("---\n")
        for line in f:
            stripped: str = line.rstrip("\n")
            print(stripped + "#" if stripped else stripped)
        print("\n---")
        ok = True
    except OSError as e:
        print(f"\nError reading file '{filename}': {e}")
    finally:
        f.close()
    return ok


def save_transformed(filename: str, out_name: str) -> None:
    f_in: typing.TextIO
    try:
        f_in = open(filename, "r", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return
    f_out: typing.TextIO
    try:
        f_out = open(out_name, "w", encoding="utf-8")
    except OSError as e:
        print(f"Error opening file '{out_name}': {e}")
        f_in.close()
        return
    try:
        for line in f_in:
            stripped: str = line.rstrip("\n")
            f_out.write(stripped + "#\n" if stripped else "\n")
        print(f"Data saved in file '{out_name}'.")
        return
    except OSError as e:
        print(f"\nError writing file '{out_name}': {e}")
        return
    finally:
        f_out.close()
        f_in.close()


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
        return
    filename: str = sys.argv[1]
    if not display_original(filename):
        return
    print("\nTransform data:")
    if not display_transformed(filename):
        return
    try:
        name: str = input("Enter new file name (or empty): ").strip()
    except EOFError:
        print()
        name = ""
    if not name:
        print("Not saving data.")
        return
    print(f"Saving data to '{name}'")
    save_transformed(filename, name)


if __name__ == "__main__":
    main()
