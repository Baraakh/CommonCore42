from ex0 import AquaFactory, CreatureFactory, FlameFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    AggressiveStrategy,
    BattleStrategy,
    DefensiveStrategy,
    InvalidStrategyError,
    NormalStrategy,
)

Opponent = tuple[CreatureFactory, BattleStrategy]


def battle(opponents: list[Opponent]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print()
    for i in range(len(opponents)):
        for j in range(i + 1, len(opponents)):
            factory_a, strategy_a = opponents[i]
            factory_b, strategy_b = opponents[j]
            creature_a = factory_a.create_base()
            creature_b = factory_b.create_base()
            print("* Battle *")
            print(creature_a.describe())
            print(" vs.")
            print(creature_b.describe())
            print(" now fight!")
            try:
                lines_a = strategy_a.act(creature_a)
                lines_b = strategy_b.act(creature_b)
            except InvalidStrategyError as e:
                print(f"Battle error, aborting tournament: {e}")
                print()
                return
            for line in lines_a:
                print(line)
            for line in lines_b:
                print(line)
            print()


def main() -> None:
    try:
        flame_factory = FlameFactory()
        aqua_factory = AquaFactory()
        heal_factory = HealingCreatureFactory()
        transform_factory = TransformCreatureFactory()
        normal = NormalStrategy()
        aggressive = AggressiveStrategy()
        defensive = DefensiveStrategy()

        print("Tournament 0 (basic)")
        print(" [ (Flameling+Normal), (Healing+Defensive) ]")
        battle([(flame_factory, normal), (heal_factory, defensive)])

        print("Tournament 1 (error)")
        print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")
        battle([(flame_factory, aggressive), (heal_factory, defensive)])

        print("Tournament 2 (multiple)")
        print(
            " [ (Aquabub+Normal), (Healing+Defensive), "
            "(Transform+Aggressive) ]"
        )
        battle(
            [
                (aqua_factory, normal),
                (heal_factory, defensive),
                (transform_factory, aggressive),
            ]
        )
    except Exception as e:
        print(f"Tournament error: {e}")


if __name__ == "__main__":
    main()
