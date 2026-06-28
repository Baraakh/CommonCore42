import random


def main() -> None:
    print("=== Game Data Alchemist ===")
    names: list[str] = [
        "Alice", "bob", "Charlie", "dylan", "Emma",
        "Gregory", "john", "kevin", "Liam",
    ]
    print(f"\nInitial list of players: {names}")
    all_capitalized: list[str] = [name.capitalize() for name in names]
    print(f"New list with all names capitalized: {all_capitalized}")
    already_capitalized: list[str] = [
        name for name in names if name == name.capitalize()
    ]
    print(f"New list of capitalized names only: {already_capitalized}\n")
    scores: dict[str, int] = {
        name: random.randint(1, 1000) for name in all_capitalized
    }
    print(f"Score dict: {scores}")
    average = round(sum(scores.values()) / len(scores), 2)
    print(f"Score average is {average}")
    high_scores: dict[str, int] = {
        k: v for k, v in scores.items() if v > average
    }
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()
