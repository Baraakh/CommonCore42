import os
import site
import sys


def is_in_virtualenv() -> bool:
    in_venv = sys.base_prefix != sys.prefix
    return in_venv or "VIRTUAL_ENV" in os.environ


def get_venv_name() -> str | None:
    venv_path = os.environ.get("VIRTUAL_ENV")
    if venv_path:
        return os.path.basename(venv_path)
    if is_in_virtualenv():
        return os.path.basename(sys.prefix)
    return None


def get_site_packages_path() -> str:
    try:
        return site.getsitepackages()[0]
    except (AttributeError, IndexError):
        version = f"python{sys.version_info.major}.{sys.version_info.minor}"
        return os.path.join(sys.prefix, "lib", version, "site-packages")


def print_outside_venv_report() -> None:
    print("MATRIX STATUS: You're still plugged in\n")
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected\n")
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.\n")
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate  # On Unix")
    print("matrix_env\\Scripts\\activate     # On Windows\n")
    print("Then run this program again.")


def print_inside_venv_report() -> None:
    venv_name = get_venv_name()
    print("MATRIX STATUS: Welcome to the construct\n")
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {venv_name}")
    print(f"Environment Path: {sys.prefix}\n")
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting")
    print("the global system.\n")
    print("Package installation path:")
    print(get_site_packages_path())


def main() -> None:
    try:
        if is_in_virtualenv():
            print_inside_venv_report()
        else:
            print_outside_venv_report()
    except OSError as error:
        print(f"ERROR: Could not inspect the environment: {error}")


if __name__ == "__main__":
    main()
