from functools import reduce, partial, lru_cache, singledispatch
import operator
from typing import Callable, Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0

    op_func: Callable[[int, int], int]
    if operation == "add":
        op_func = operator.add
    elif operation == "multiply":
        op_func = operator.mul
    elif operation == "max":
        op_func = max
    elif operation == "min":
        op_func = min
    else:
        return 0

    return reduce(op_func, spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    fire = partial(base_enchantment, 50, "fire")
    ice = partial(base_enchantment, 50, "ice")
    lightning = partial(base_enchantment, 50, "lightning")

    return {
        "fire": fire,
        "ice": ice,
        "lightning": lightning
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n <= 1:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


@singledispatch
def spell_dispatcher(value: Any) -> str:
    return "Unknown spell type"


@spell_dispatcher.register
def _(value: int) -> str:
    return f"Damage spell: {value} damage"


@spell_dispatcher.register
def _(value: str) -> str:
    return f"Enchantment: {value}"


@spell_dispatcher.register
def _(value: list) -> str:
    return f"Multi-cast: {len(value)} spells"


if __name__ == "__main__":

    print("Testing spell reducer...")

    spells = [10, 20, 30, 40]

    print("Sum:", spell_reducer(spells, "add"))
    print("Product:", spell_reducer(spells, "multiply"))
    print("Max:", spell_reducer(spells, "max"))

    print("\nTesting memoized fibonacci...")
    print("Fib(0):", memoized_fibonacci(0))
    print("Fib(1):", memoized_fibonacci(1))
    print("Fib(10):", memoized_fibonacci(10))
    print("Fib(15):", memoized_fibonacci(15))

    print("\nTesting spell dispatcher...")
    print(spell_dispatcher(42))
    print(spell_dispatcher("fireball"))
    print(spell_dispatcher([1, 2, 3]))
    print(spell_dispatcher({"unknown": "type"}))
