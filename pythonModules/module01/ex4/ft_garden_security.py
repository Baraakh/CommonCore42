class Plant:
    def __init__(self, name: str, height: float, age: int,
                 growth_rate: float = 0.8):
        self.name = name
        self._height = height
        self._age_in_days = age
        self.growth_rate = growth_rate

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_in_days

    def set_height(self, height: float) -> bool:
        if (height < 0):
            print(f"{self.name}: Error, height can't be negative")
            return False
        self._height = height
        return True

    def set_age(self, age: int) -> bool:
        if (age < 0):
            print(f"{self.name}: Error, age can't be negative")
            return False
        self._age_in_days = age
        return True

    def grow(self) -> None:
        self._height += self.growth_rate

    def age(self) -> None:
        self._age_in_days += 1

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {round(self._height, 1)}cm, " +
              f"{self._age_in_days} days old")


if __name__ == "__main__":
    plant = Plant("Rose", 15.0, 10)
    print("=== Garden Security System ===")
    print("Plant created: ", end="")
    plant.show()
    print("")

    def update(new_height: float, new_age: int) -> None:
        if plant.set_height(new_height):
            print(f"Height updated: {plant.get_height()}cm")
        else:
            print("Height update rejected")

        if plant.set_age(new_age):
            print(f"Age updated: {plant.get_age()} days")
        else:
            print("Age update rejected")
        print("")

    update(25.0, 30)
    update(-5, -30)
    print("Current state: ", end="")
    plant.show()
