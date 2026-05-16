_This project has been created as part of the 42 curriculum by bkhilo._

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (a and b) and a limited set of operations, while minimizing the total number of operations used.

The program reads a list of integers, builds them into stack `a`, and outputs the sequence of operations to sort the stack in ascending order (smallest on top). Stack `b` is used as a temporary buffer.

**Available operations:**

- `sa` / `sb` — swap top two elements of stack a / b
- `pa` / `pb` — push top element from b to a / from a to b
- `ra` / `rb` — rotate stack a / b (top → bottom)
- `rra` / `rrb` — reverse rotate stack a / b (bottom → top)

**Algorithm used:** Chunk Sort for large inputs (n > 6), with a dedicated small sort for 2–6 elements.

### How the chunk sort works

1. **Index assignment** — `set_indexes()` walks the list and assigns each node a rank from `0` (smallest value) to `n-1` (largest), stored in the `index` field alongside the original `value`.

2. **Push to b in chunks** — `push_to_b()` scans stack a repeatedly. Elements whose index falls in the current chunk window are pushed to b. Very small-index elements (already "done") are pushed to b's bottom via an extra `rb`. Elements outside the window are rotated past with `ra`. This groups elements in b roughly from largest (top) to smallest (bottom).

3. **Pull max back to a** — `move_max_to_a()` finds the highest-index element in b, rotates it to the top with `rb`/`rrb` (whichever is shorter), then `pa`. Repeating this until b is empty reconstructs a in sorted order with the smallest value on top.

**Small sort (size ≤ 6):**

- Size 2: single `sa` if unsorted.
- Size 3: hardcoded comparison of the three indexes — at most 2 operations.
- Size 4–6: move the minimum to b repeatedly until 3 remain, apply the 3-element sort, then push b back with `pa`.

**Performance results:**

| Input size  | Operations     | Grade                  |
| ----------- | -------------- | ---------------------- |
| 3 numbers   | ≤ 2 ops        | —                      |
| 5 numbers   | ≤ 10 ops       | —                      |
| 100 numbers | ~560–590 ops   | **5 / 5 pts** (< 700)  |
| 500 numbers | ~5000–5300 ops | **5 / 5 pts** (< 5500) |

## Instructions

### Requirements

- `cc` compiler
- `make`

### Compilation

```bash
make
```

### Usage

```bash
./push_swap <integers>
# or with a quoted string
./push_swap "3 1 2 5 4"
```

### Examples

```bash
# Simple sort
./push_swap 3 1 2

# Count operations for 100 random numbers
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1,1001), 100))))")
./push_swap $ARG | wc -l

# Count operations for 500 random numbers
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1,10001), 500))))")
./push_swap $ARG | wc -l

# Verify correctness with the 42 checker
ARG="3 2 1"
./push_swap $ARG | ./checker_OS $ARG
```

### Makefile targets

| Target        | Description                    |
| ------------- | ------------------------------ |
| `make`        | Compile the binary             |
| `make clean`  | Remove object files            |
| `make fclean` | Remove object files and binary |
| `make re`     | Full recompile                 |

### Error cases

The program writes `Error` to stderr and exits with code 1 on:

- Non-numeric arguments (e.g. `./push_swap 1 abc 3`)
- Integers outside `[INT_MIN, INT_MAX]` (e.g. `./push_swap 2147483648`)
- Duplicate values (e.g. `./push_swap 1 2 1`)

No output and exit 0 when called with no arguments.

## Resources

- 42 push_swap subject
- [Linked list data structure — GeeksForGeeks](https://www.geeksforgeeks.org/linked-list-data-structure/)
- [42 Norminette](https://github.com/42School/norminette)

## AI Usage

- I have used AI to test my code on different cases, to make sure there is no memory leaks problems or runtime bugs.
- Used it also for formatting the README file.
