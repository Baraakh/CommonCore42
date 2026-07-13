from ex0 import Creature
from ex1 import (
    HealCapability,
    HealingCreatureFactory,
    TransformCapability,
    TransformCreatureFactory,
)


def test_healing(creature: Creature) -> None:
    print(creature.describe())
    print(creature.attack())
    if isinstance(creature, HealCapability):
        print(creature.heal())


def test_transform(creature: Creature) -> None:
    print(creature.describe())
    print(creature.attack())
    if isinstance(creature, TransformCapability):
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())


def main() -> None:
    try:
        heal_factory = HealingCreatureFactory()
        transform_factory = TransformCreatureFactory()

        print("Testing Creature with healing capability")
        print(" base:")
        test_healing(heal_factory.create_base())
        print(" evolved:")
        test_healing(heal_factory.create_evolved())
        print()

        print("Testing Creature with transform capability")
        print(" base:")
        test_transform(transform_factory.create_base())
        print(" evolved:")
        test_transform(transform_factory.create_evolved())
    except Exception as e:
        print(f"Capacitor error: {e}")


if __name__ == "__main__":
    main()
