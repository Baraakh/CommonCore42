def ft_harvest_total() -> None:
    total_harvest: int = int(0)
    Day: int = 0
    while Day < 3:
        harvest: int = int(input(f"Day {Day + 1} harvest: "))
        total_harvest += harvest
        Day += 1
    print(f"Total harvest: {total_harvest}")
