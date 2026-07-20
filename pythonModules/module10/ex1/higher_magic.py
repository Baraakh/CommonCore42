from typing import Callable


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    return lambda target, power: (spell1(target, power), spell2(target, power))


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    return lambda target, power: base_spell(target, power * multiplier)


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    return lambda target, power: (
        spell(target, power) if condition(target, power) else "Spell fizzled"
    )


def spell_sequence(spells: list[Callable]) -> Callable:
    return lambda target, power: [spell(target, power) for spell in spells]


if __name__ == "__main__":

    def fireball(target: str, power: int) -> str:
        return f"Fireball hits {target} for {power} damage"

    def heal(target: str, power: int) -> str:
        return f"Heal {target} for {power} HP"

    def is_powerful(target: str, power: int) -> bool:
        return power > 10

    print("Testing spell combiner...")
    combo = spell_combiner(fireball, heal)
    result = combo("Dragon", 10)
    print(f"Combined spell result: {result[0]}, {result[1]}")

    print("\nTesting power amplifier...")
    mega_fireball = power_amplifier(fireball, 3)
    original = fireball("Goblin", 10)
    amplified = mega_fireball("Goblin", 10)
    print(f"Original: {original}, Amplified: {amplified}")

    print("\nTesting conditional caster...")
    safe_spell = conditional_caster(is_powerful, fireball)
    print(safe_spell("Dragon", 5))
    print(safe_spell("Dragon", 20))

    print("\nTesting spell sequence...")
    sequence = spell_sequence([fireball, heal])
    results = sequence("Demon", 20)
    for res in results:
        print(res)
