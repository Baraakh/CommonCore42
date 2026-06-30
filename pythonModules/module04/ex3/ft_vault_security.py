def secure_archive(
    filename: str, mode: str = "r", content: str = ""
) -> tuple[bool, str]:
    try:
        with open(filename, mode) as f:
            if mode == "r":
                return (True, f.read())
            f.write(content)
            return (True, "Content successfully written to file")
    except OSError as e:
        return (False, str(e))


def main() -> None:
    print("=== Cyber Archives Security ===\n")

    print("Using 'secure_archive' to read from a nonexistent file:")
    result: tuple[bool, str] = secure_archive("/not/existing/file")
    print(result)
    print()

    print("Using 'secure_archive' to read from an inaccessible file:")
    result = secure_archive("/etc/master.passwd")
    print(result)
    print()

    print("Using 'secure_archive' to read from a regular file:")
    result = secure_archive("ancient_fragment.txt")
    print(result)
    print()

    print("Using 'secure_archive' to write previous content to a new file:")
    result = secure_archive("restored_vault.txt", "w", result[1])
    print(result)


if __name__ == "__main__":
    main()
