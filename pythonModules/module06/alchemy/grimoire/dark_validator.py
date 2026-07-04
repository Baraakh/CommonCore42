# Intentionally broken: real two-directional circular import (see subject).
from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed = dark_spell_allowed_ingredients()
    lowered = ingredients.lower()
    is_valid = any(item in lowered for item in allowed)
    verdict = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {verdict}"
