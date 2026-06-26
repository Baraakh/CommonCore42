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


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 color: str, growth_rate: float = 0.8):
        self.color = color
        self.is_blooming = False
        super().__init__(name, height, age, growth_rate)

    def bloom(self) -> None:
        self.is_blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.is_blooming:
            print(f" {self.name.capitalize()} is blooming beautifully!")
        else:
            print(f" {self.name.capitalize()} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float, growth_rate: float = 0.8):
        self.trunk_diameter = trunk_diameter
        super().__init__(name, height, age, growth_rate)

    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of " +
              f"{super().get_height()}cm long " +
              f"and {self.trunk_diameter}cm wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str,  nutritional_value: int,
                 growth_rate: float = 0.8):
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
        super().__init__(name, height, age, growth_rate)

    def grow(self) -> None:
        super().grow()
        self.nutritional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower = Flower("Rose", 15.0, 10, "red")
    flower.show()
    print("[asking the rose to bloom]")
    flower.bloom()
    flower.show()

    print("\n=== Tree")
    tree = Tree("Oak", 200.0, 365, 5.0)
    tree.show()
    print("[asking the oak to produce shade]")
    tree.produce_shade()

    print("\n=== Vegetable")
    vegetable = Vegetable("Tomato", 5.0, 10, "April", 0, 2.1)
    vegetable.show()
    print("[make tomato grow and age for 20 days]")
    for _ in range(20):
        vegetable.grow()
        vegetable.age()
    vegetable.show()
