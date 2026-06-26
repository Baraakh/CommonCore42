class Plant:
    def __init__(self, name: str, height: float, age: int,
                 growth_rate: float = 0.8):
        self.name = name
        self.height = height
        self.age_in_days = age
        self.growth_rate = growth_rate

    def grow(self) -> None:
        self.height += self.growth_rate

    def age(self) -> None:
        self.age_in_days += 1

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {round(self.height, 1)}cm, " +
              f"{self.age_in_days} days old")


if __name__ == "__main__":
    plants = [
        Plant("Rose", 25.0, 30, 0.8),
        Plant("Oak", 200.0, 365, 0.5),
        Plant("Cactus", 5.0, 90, 1.2),
        Plant("Sunflower", 80.0, 45, 1.0),
        Plant("Fern", 15.0, 120, 0.9)
    ]
    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created: ", end="")
        plant.show()
