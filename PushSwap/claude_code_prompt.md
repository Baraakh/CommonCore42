# Claude Code Prompt — push_swap (Radix Sort, 42 Norm)

Build a complete `push_swap` project in C following the 42 School subject requirements
and strict Norminette coding style. Use Radix Sort as the sorting algorithm.

---

## Project structure

```
push_swap/
├── Makefile
├── push_swap.h
├── srcs/
│   ├── main.c
│   ├── parse.c
│   ├── stack_utils.c
│   ├── operations_a.c
│   ├── operations_b.c
│   ├── operations_both.c
│   ├── sort_small.c
│   └── sort_radix.c
```

---

## 42 Norminette rules — enforce ALL of these strictly

- Max **25 lines per function** (closing brace counts, blank lines count)
- Max **5 functions per .c file**
- Max **4 parameters per function**
- Max **80 columns per line**
- **No for loops** — use only `while`
- **No do...while**
- **No switch/case**
- **No ternary operators** (`? :`)
- **No multiple assignments on one line** (`a = b = 0` is forbidden)
- **All variable declarations at the top of the function block**, before any instruction
- **No variable declaration after the first non-declaration line**
- **One instruction per line**
- **Tabs for indentation** (not spaces)
- **No trailing whitespace**
- **No more than 1 blank line between functions**
- **No blank line at end of file**
- **No global variables**
- **Typedef structs** must be declared in the header
- Header files must have **include guards** using `# ifndef / # define / # endif`
- Function return type is always on its **own line** above the function name
- Opening brace `{` of a function is on its **own line**
- Local variable names and function names use **snake_case**
- **No unused variables or functions**
- **No implicit function return types**
- Each `.c` file includes only its own header — no chained includes in `.c` files

### Example of correct 42 norm style:

```c
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
```

Key points in that example:
- Return type on same line as function name, tab between type and name
- Opening brace on its own line
- Tab-indented body
- Variable declared at top before any instruction
- Single instruction per line
- `return` uses parentheses

---

## Data structures (declare in push_swap.h)

```c
typedef struct s_node
{
	int				val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;
```

---

## push_swap.h requirements

- Include guards: `# ifndef PUSH_SWAP_H` / `# define PUSH_SWAP_H` / `# endif`
- Include only: `<unistd.h>`, `<stdlib.h>`, `<limits.h>`
- All typedefs and struct definitions
- All function prototypes
- No function definitions in the header

---

## Makefile requirements

Rules: `$(NAME)`, `all`, `clean`, `fclean`, `re`
- `NAME = push_swap`
- Compile flags: `-Wall -Wextra -Werror`
- Compiler: `cc`
- Must not relink (use `.o` object files with dependency tracking)
- `clean` removes `.o` files only
- `fclean` removes `.o` files and the binary

---

## Operations to implement

Each operation function must:
1. Perform the stack manipulation
2. Print its name followed by `\n` to stdout using `write()`

Implement all 11 operations split across files:

**operations_a.c** — `op_sa`, `op_ra`, `op_rra`, `op_pa`, `op_pb`
**operations_b.c** — `op_sb`, `op_rb`, `op_rrb`
**operations_both.c** — `op_ss`, `op_rr`, `op_rrr`

Operation definitions:
- `sa` — swap top 2 elements of a (do nothing if size < 2)
- `sb` — swap top 2 elements of b (do nothing if size < 2)
- `ss` — sa and sb simultaneously (print "ss", not "sa\nsb")
- `pa` — pop top of b, push to top of a (do nothing if b empty)
- `pb` — pop top of a, push to top of b (do nothing if a empty)
- `ra` — rotate a: top element goes to bottom
- `rb` — rotate b: top element goes to bottom
- `rr` — ra and rb simultaneously
- `rra` — reverse rotate a: bottom element goes to top
- `rrb` — reverse rotate b: bottom element goes to top
- `rrr` — rra and rrb simultaneously

Important: `op_ss`, `op_rr`, `op_rrr` must call the single-stack helpers internally
but print only the combined instruction name (not two separate names).
Implement internal helpers `do_swap`, `do_rotate`, `do_rev_rotate` that manipulate
the stack silently (no print), then the public `op_*` functions call these helpers
and print once.

---

## parse.c — argument parsing

Function `parse_args(char **argv)` must:
- Accept `argv + 1` from main
- Handle the case where all args are passed as a single quoted string
  e.g. `./push_swap "3 1 2"` — split on spaces
- Validate each argument:
  - Must be a valid integer (only digits, optional leading `-` or `+`)
  - Must not exceed INT_MAX or go below INT_MIN (check before `atoi`)
  - Must have no duplicates
- On any error: write `"Error\n"` to stderr using `write(2, ...)` and exit
- Return a populated `t_stack *a` with values in order (first arg = top of stack)

---

## stack_utils.c

Implement these helpers:
- `t_stack	*new_stack(void)` — malloc and init an empty stack
- `void		push_node(t_stack *s, int val)` — push value to top
- `int		pop_node(t_stack *s)` — pop and return top value (free the node)
- `int		is_sorted(t_stack *a)` — return 1 if sorted ascending, 0 otherwise
- `void		free_stack(t_stack *s)` — free all nodes and the stack struct

---

## sort_small.c — hardcoded small sorts

- `void	sort_two(t_stack *a)` — if top > second, `op_sa`
- `void	sort_three(t_stack *a)` — hardcoded all 6 permutations, max 2 ops
- For sort_three, use `if/else if` chains comparing top 3 values — no recursion

---

## sort_radix.c — the main algorithm

### normalize function
`void	normalize(t_stack *a)`
- Build an int array of all values in stack order
- Create a sorted copy using a simple selection sort
- Walk the stack again, replacing each `node->val` with its rank (0 to n-1)
- Free both arrays

### radix_sort function
`void	radix_sort(t_stack *a, t_stack *b)`
1. Call `normalize(a)`
2. Calculate `max_bits`: smallest int where `(1 << max_bits) >= a->size`
3. For each bit from 0 to max_bits - 1:
   - Save current `a->size` as `size` before the pass
   - Loop `size` times:
     - If `(a->top->val >> bit) & 1` is 1 → `op_ra(a)`
     - If it is 0 → `op_pb(a, b)`
   - Push all of b back to a with `op_pa` until b is empty
4. Stack a is now sorted

---

## main.c

```
int	main(int argc, char **argv)
```
- If `argc < 2`, return 0 immediately (print nothing)
- Call `parse_args` to build and validate stack a
- Create empty stack b with `new_stack()`
- If already sorted (`is_sorted(a)`), free both stacks and return 0
- Branch on `a->size`:
  - size 1: do nothing
  - size 2: `sort_two(a)`
  - size 3: `sort_three(a)`
  - otherwise: `radix_sort(a, b)`
- Free both stacks
- Return 0

---

## Error handling rules

- All `malloc` calls must be checked — if NULL, free everything allocated so far,
  write `"Error\n"` to stderr, and exit
- Use `write(2, "Error\n", 6)` for stderr output — do not use `printf` or `ft_printf`
  unless you have implemented your own `ft_printf`
- `exit(1)` on error after cleanup

---

## What NOT to use

- No `printf` (use `write` directly or your own `ft_printf`)
- No `string.h` functions — implement what you need
- No global variables
- No `for` loops anywhere in the project
- No `goto`

---

## Deliverable checklist

Before finishing, verify:
- [ ] `make` compiles without warnings
- [ ] `make fclean && make` works (no relink issues)
- [ ] `./push_swap 3 1 2` outputs correct instructions
- [ ] `./push_swap` outputs nothing
- [ ] `./push_swap 0 one 2` outputs `Error` to stderr
- [ ] `./push_swap 1 1 2` outputs `Error` (duplicate)
- [ ] `./push_swap 2147483648` outputs `Error` (overflow)
- [ ] `ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l` outputs < 1100
- [ ] `ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l` outputs < 8500
- [ ] `./push_swap $ARG | ./checker_OS $ARG` outputs `OK`
- [ ] Run norminette on all `.c` and `.h` files — zero errors
