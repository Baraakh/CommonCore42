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
    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dylan = gen_player_achievements()
    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")
    all_achievements = alice.union(bob).union(charlie).union(dylan)
    print(f"\nAll distinct achievements: {all_achievements}")
    common = alice.intersection(bob).intersection(charlie).intersection(dylan)
    print(f"\nCommon achievements: {common}")
    print()
    only_alice = alice.difference(bob.union(charlie).union(dylan))
    only_bob = bob.difference(alice.union(charlie).union(dylan))
    only_charlie = charlie.difference(alice.union(bob).union(dylan))
    only_dylan = dylan.difference(alice.union(bob).union(charlie))
    print(f"Only Alice has: {only_alice}")
    print(f"Only Bob has: {only_bob}")
    print(f"Only Charlie has: {only_charlie}")
    print(f"Only Dylan has: {only_dylan}")
    print()
    print(f"Alice is missing: {all_achievements.difference(alice)}")
    print(f"Bob is missing: {all_achievements.difference(bob)}")
    print(f"Charlie is missing: {all_achievements.difference(charlie)}")
    print(f"Dylan is missing: {all_achievements.difference(dylan)}")


if __name__ == "__main__":
    main()
