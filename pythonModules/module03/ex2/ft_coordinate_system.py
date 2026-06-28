import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        raw = input("Enter new coordinates as floats in format 'x,y,z': ")
        parts = raw.split(",")
        if len(parts) != 3:
            print("Invalid syntax")
            continue
        coords: list[float] = []
        valid = True
        for part in parts:
            try:
                coords.append(float(part.strip()))
            except ValueError:
                print(
                    f"Error on parameter '{part.strip()}':"
                    f" could not convert string to float: '{part.strip()}'"
                )
                valid = False
                break
        if valid:
            return (coords[0], coords[1], coords[2])


def distance(
    p1: tuple[float, float, float],
    p2: tuple[float, float, float]
) -> float:
    return round(
        math.sqrt(
            (p2[0] - p1[0]) ** 2
            + (p2[1] - p1[1]) ** 2
            + (p2[2] - p1[2]) ** 2
        ),
        4,
    )


def main() -> None:
    print("=== Game Coordinate System ===")
    print("\nGet a first set of coordinates")
    pos1 = get_player_pos()
    print(f"Got a first tuple: {pos1}")
    print(f"It includes: X={pos1[0]}, Y={pos1[1]}, Z={pos1[2]}")
    print(f"Distance to center: {distance((0.0, 0.0, 0.0), pos1)}")
    print("\nGet a second set of coordinates")
    pos2 = get_player_pos()
    print("Distance between the 2 sets of coordinates: "
          f"{distance(pos1, pos2)}")


if __name__ == "__main__":
    main()
