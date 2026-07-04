import elements

from ..elements import create_air
from ..potions import strength_potion


def lead_to_gold() -> str:
    air = create_air()
    strength = strength_potion()
    fire = elements.create_fire()
    return (
        f"Recipe transmuting Lead to Gold: brew '{air}' and "
        f"'{strength}' mixed with '{fire}'"
    )
