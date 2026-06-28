import random

ALL_ACHIEVEMENTS: list[str] = [
    "Crafting Genius",
    "Strategist",
    "World Savior",
    "Speed Runner",
    "Survivor",
    "Master Explorer",
    "Treasure Hunter",
    "Unstoppable",
    "First Steps",
    "Collector Supreme",
    "Untouchable",
    "Boss Slayer",
    "Sharp Mind",
    "Hidden Path Finder",
]


def gen_player_achievements() -> set[str]:
    count = random.randint(4, len(ALL_ACHIEVEMENTS) - 2)
    return set(random.sample(ALL_ACHIEVEMENTS, count))


def main() -> None:
    print("=== Achievement Tracker System ===")
    players: dict[str, set[str]] = {
        "Alice": gen_player_achievements(),
        "Bob": gen_player_achievements(),
        "Charlie": gen_player_achievements(),
        "Dylan": gen_player_achievements(),
    }
    for name, achievements in players.items():
        print(f"Player {name}: {achievements}")
    all_achievements: set[str] = set()
    for ach in players.values():
        all_achievements = all_achievements.union(ach)
    print(f"\nAll distinct achievements: {all_achievements}")
    common: set[str] = set(ALL_ACHIEVEMENTS)
    for ach in players.values():
        common = common.intersection(ach)
    print(f"\nCommon achievements: {common}")
    print()
    for name, achievements in players.items():
        others: set[str] = set()
        for other_name, other_ach in players.items():
            if other_name != name:
                others = others.union(other_ach)
        unique = achievements.difference(others)
        print(f"Only {name} has: {unique}")
    print()
    for name, achievements in players.items():
        missing = all_achievements.difference(achievements)
        print(f"{name} is missing: {missing}")


if __name__ == "__main__":
    main()
