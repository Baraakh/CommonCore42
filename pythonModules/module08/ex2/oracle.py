import os
from dataclasses import dataclass

from dotenv import load_dotenv

_DEFAULTS: dict[str, str] = {
    "MATRIX_MODE": "development",
    "DATABASE_URL": "sqlite:///local_matrix.db",
    "API_KEY": "",
    "LOG_LEVEL": "INFO",
    "ZION_ENDPOINT": "http://localhost:8000",
}
_VALID_MODES = {"development", "production"}


class ConfigError(Exception):
    """Raised when configuration values are present but invalid."""


@dataclass(frozen=True)
class Config:
    matrix_mode: str
    database_url: str
    api_key: str
    log_level: str
    zion_endpoint: str


def load_config() -> tuple[Config, list[str]]:
    load_dotenv(override=False)

    used_defaults: list[str] = []
    values: dict[str, str] = {}
    for key, default in _DEFAULTS.items():
        raw_value = os.environ.get(key)
        if raw_value is None or raw_value == "":
            values[key] = default
            used_defaults.append(key)
        else:
            values[key] = raw_value

    mode = values["MATRIX_MODE"].lower()
    if mode not in _VALID_MODES:
        raise ConfigError(
            f"MATRIX_MODE must be one of {sorted(_VALID_MODES)}, got {mode!r}"
        )

    config = Config(
        matrix_mode=mode,
        database_url=values["DATABASE_URL"],
        api_key=values["API_KEY"],
        log_level=values["LOG_LEVEL"],
        zion_endpoint=values["ZION_ENDPOINT"],
    )
    return config, used_defaults


def mask_secret(value: str, visible: int = 4) -> str:
    if not value:
        return "(not set)"
    if len(value) <= visible:
        return "*" * len(value)
    return "*" * (len(value) - visible) + value[-visible:]


def describe_database(config: Config) -> str:
    if config.matrix_mode == "production":
        masked = mask_secret(config.database_url)
        return f"Connected to production instance ({masked})"
    return f"Connected to local instance ({config.database_url})"


def describe_api_access(config: Config) -> str:
    if not config.api_key:
        return "Not authenticated (API_KEY missing)"
    if config.matrix_mode == "production":
        return f"Authenticated (key: {mask_secret(config.api_key)})"
    return "Authenticated"


def run_security_check(
    config: Config, used_defaults: list[str], env_file_found: bool
) -> list[str]:
    lines: list[str] = []
    if config.api_key and config.api_key not in _DEFAULTS.values():
        lines.append("[OK] No hardcoded secrets detected")
    else:
        lines.append("[WARNING] API_KEY is missing or using a default value")

    if env_file_found:
        lines.append("[OK] .env file properly configured")
    else:
        lines.append("[WARNING] No .env file found - using env/defaults")

    if config.matrix_mode == "production":
        lines.append("[OK] Production overrides active")
    else:
        lines.append(
            "[OK] Production overrides available (set MATRIX_MODE=production)"
        )

    return lines


def print_mode_banner(config: Config) -> None:
    if config.matrix_mode == "development":
        print("\nDebug mode: showing full configuration.")
    else:
        print("\nProduction mode: sensitive values are masked in output.")


def main() -> None:
    print("ORACLE STATUS: Reading the Matrix...\n")

    env_file_found = os.path.isfile(".env")

    try:
        config, used_defaults = load_config()
    except ConfigError as error:
        print(f"ERROR: {error}")
        return

    if used_defaults:
        print("WARNING: Using default values for: " + ", ".join(used_defaults))

    print("Configuration loaded:")
    print(f"Mode: {config.matrix_mode}")
    print(f"Database: {describe_database(config)}")
    print(f"API Access: {describe_api_access(config)}")
    print(f"Log Level: {config.log_level}")
    print(f"Zion Network: {'Online' if config.zion_endpoint else 'Offline'}")

    print_mode_banner(config)

    print("\nEnvironment security check:")
    for line in run_security_check(config, used_defaults, env_file_found):
        print(line)

    print("\nThe Oracle sees all configurations.")


if __name__ == "__main__":
    main()
