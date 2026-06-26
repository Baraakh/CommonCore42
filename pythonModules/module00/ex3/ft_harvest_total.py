def ft_harvest_total() -> None:
    total_harvest: int = 0
    day: int = 0
    while day < 3:
        harvest: int = int(input(f"Day {day + 1} harvest: "))
        total_harvest += harvest
        day += 1
    print(f"Total harvest: {total_harvest}")
