class Plant:
    def __init__(self, name: str, height: float, age: int, growth_rate: float):
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
    plant = Plant("Rose", 25.0, 30, 0.8)
    print("=== Garden Plant Growth ===")
    plant.show()
    initial_height = plant.height
    for day in range(1, 8):
        plant.grow()
        plant.age()
        print(f"=== Day {day} ===")
        plant.show()
    print(f"Growth this week: {round(plant.height - initial_height, 1)}cm")
