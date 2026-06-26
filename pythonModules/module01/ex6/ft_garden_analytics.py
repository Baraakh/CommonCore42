class Plant:
    class Statistics:
        def __init__(self) -> None:
            self._grow_count: int = 0
            self._age_count: int = 0
            self._show_count: int = 0

        def record_grow(self) -> None:
            self._grow_count += 1

        def record_age(self) -> None:
            self._age_count += 1

        def record_show(self) -> None:
            self._show_count += 1

        def display(self) -> None:
            print(
                f"Stats: {self._grow_count} grow, "
                f"{self._age_count} age, {self._show_count} show"
            )

    def __init__(self, name: str, height: float, age: int,
                 growth_rate: float = 0.8) -> None:
        self.name = name
        self._height = height
        self._age_in_days = age
        self.growth_rate = growth_rate
        self._stats: Plant.Statistics = Plant.Statistics()

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_in_days

    def set_height(self, height: float) -> bool:
        if height < 0:
            print(f"{self.name.capitalize()}: Error, height can't be negative")
            return False
        self._height = height
        return True

    def set_age(self, age: int) -> bool:
        if age < 0:
            print(f"{self.name.capitalize()}: Error, age can't be negative")
            return False
        self._age_in_days = age
        return True

    def grow(self) -> None:
        self._height += self.growth_rate
        self._stats.record_grow()

    def age(self) -> None:
        self._age_in_days += 1
        self._stats.record_age()

    def show(self) -> None:
        print(
            f"{self.name.capitalize()}: {round(self._height, 1)}cm, "
            f"{self._age_in_days} days old"
        )
        self._stats.record_show()

    @staticmethod
    def is_older_than_year(age: int) -> bool:
        return age > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 color: str, growth_rate: float = 0.8) -> None:
        super().__init__(name, height, age, growth_rate)
        self.color = color
        self._blooming: bool = False

    def bloom(self) -> None:
        self._blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self._blooming:
            print(f" {self.name.capitalize()} is blooming beautifully!")
        else:
            print(f" {self.name.capitalize()} has not bloomed yet")


class Tree(Plant):
    class TreeStatistics(Plant.Statistics):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count: int = 0

        def record_shade(self) -> None:
            self._shade_count += 1

        def display(self) -> None:
            super().display()
            print(f" {self._shade_count} shade")

    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float, growth_rate: float = 0.8) -> None:
        super().__init__(name, height, age, growth_rate)
        self.trunk_diameter = trunk_diameter
        self._tree_stats: Tree.TreeStatistics = Tree.TreeStatistics()
        self._stats = self._tree_stats

    def produce_shade(self) -> None:
        print(
            f"Tree {self.name.capitalize()} now produces a shade of "
            f"{round(self._height, 1)}cm long "
            f"and {self.trunk_diameter}cm wide."
        )
        self._tree_stats.record_shade()

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, nutritional_value: int = 0,
                 growth_rate: float = 0.8) -> None:
        super().__init__(name, height, age, growth_rate)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def grow(self) -> None:
        super().grow()
        self.nutritional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int,
                 color: str, seed_count: int = 0,
                 growth_rate: float = 0.8) -> None:
        super().__init__(name, height, age, color, growth_rate)
        self._seed_count: int = seed_count
        self._seeds: int = 0

    def bloom(self) -> None:
        super().bloom()
        self._seeds = self._seed_count

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self._seeds}")


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name.capitalize()}]")
    plant._stats.display()


if __name__ == "__main__":
    print("=== Garden statistics ===")

    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red", 8.0)
    rose.show()
    display_statistics(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    display_statistics(rose)

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_statistics(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_statistics(oak)

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow", 42, 30.0)
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age()
    sunflower.bloom()
    sunflower.show()
    display_statistics(sunflower)

    print("\n=== Anonymous")
    anon = Plant.create_anonymous()
    anon.show()
    display_statistics(anon)
