class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age_in_days = age

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {self.height}cm, " +
              f"{self.age_in_days} days old")


if __name__ == "__main__":
    plants: list[Plant] = [
        Plant("Rose", 25, 30),
        Plant("Sunflower", 80, 45),
        Plant("Cactus", 15, 120)
    ]
    print("=== Garden Plant Registry ===")
    for plant in plants:
        plant.show()
