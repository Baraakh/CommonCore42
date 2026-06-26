def ft_count_harvest_recursive() -> None:
    def count_days(day: int, total_days: int) -> None:
        if day < total_days:
            print(f"Day {day + 1}")
            count_days(day + 1, total_days)
        else:
            print("Harvest time!")

    days_until_harvest: int = int(input("Days until harvest: "))
    count_days(0, days_until_harvest)
