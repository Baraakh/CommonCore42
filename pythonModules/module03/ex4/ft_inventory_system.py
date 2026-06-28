import sys


def parse_inventory(args: list[str]) -> dict[str, int]:
    inventory: dict[str, int] = {}
    for arg in args:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue
        parts = arg.split(":")
        if len(parts) != 2 or not parts[0] or not parts[1]:
            print(f"Error - invalid parameter '{arg}'")
            continue
        key, value = parts[0], parts[1]
        if key in inventory:
            print(f"Redundant item '{key}' - discarding")
            continue
        try:
            inventory[key] = int(value)
        except ValueError as e:
            print(f"Quantity error for '{key}': {e}")
    return inventory


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory = parse_inventory(sys.argv[1:])
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    total = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total}")
    for item, qty in inventory.items():
        pct = round(qty / total * 100, 1)
        print(f"Item {item} represents {pct}%")
    if inventory:
        most = max(inventory.keys(), key=lambda k: inventory[k])
        least = min(inventory.keys(), key=lambda k: inventory[k])
        print(
            f"Item most abundant: {most} with quantity {inventory[most]}"
        )
        print(
            f"Item least abundant: {least} with quantity {inventory[least]}"
        )
    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


main()
