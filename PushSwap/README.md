*This project has been created as part of the 42 curriculum by bkhilo.*

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (a and b) and a limited set of operations, while minimizing the total number of operations used.

The program reads a list of integers, builds them into stack `a`, and outputs the sequence of operations to sort the stack in ascending order (smallest on top). Stack `b` is used as a temporary buffer.

**Available operations:**
- `sa` / `sb` / `ss` — swap top two elements of stack a / b / both
- `pa` / `pb` — push top element from b to a / from a to b
- `ra` / `rb` / `rr` — rotate stack a / b / both (top → bottom)
- `rra` / `rrb` / `rrr` — reverse rotate stack a / b / both (bottom → top)

**Algorithm used:** Radix Sort with index normalization for large inputs, with hand-optimized routines for 2, 3, and 5 elements.

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
# or
./push_swap "<space-separated integers>"
```

### Examples

```bash
./push_swap 3 1 2         # outputs: ra
./push_swap "5 3 1 4 2"   # outputs operations to sort

# Count operations for 100 numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

# Verify correctness with checker
ARG="3 2 1"
./push_swap $ARG | ./checker_OS $ARG
```

### Makefile targets

| Target   | Description                        |
|----------|------------------------------------|
| `make`   | Compile the binary                 |
| `make clean` | Remove object files           |
| `make fclean` | Remove objects and binary    |
| `make re` | Full recompile                    |

### Error cases

The program writes `Error` to stderr and exits with code 1 on:
- Non-numeric arguments
- Integers outside `[INT_MIN, INT_MAX]`
- Duplicate values

## Resources

- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/131674/en.subject.pdf)
- [Radix sort explanation — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Linked list data structure — GeeksForGeeks](https://www.geeksforgeeks.org/linked-list-data-structure/)
- [42 Norminette](https://github.com/42School/norminette)

### AI Usage

This project was implemented with assistance from **Claude (Anthropic)** via Claude Code CLI.

AI was used for:
- **Project structure design** — deciding how to split functions across files to comply with the 42 Norminette (≤5 functions per file, ≤25 lines per function)
- **Algorithm implementation** — radix sort with normalization, small-case sorts (2, 3, 5 elements), and all 11 stack operations
- **Error handling** — integer overflow detection, duplicate checking, and single-string argument parsing
- **Testing and validation** — running the evaluation checklist, checking move counts against the grade thresholds, and verifying sort correctness with a Python simulator

The core algorithm choices (radix sort, the `sort_five` rotation approach) and all code were generated and verified with AI assistance. Final understanding and any evaluation adjustments remain the student's responsibility.
