# push_swap — Evaluation Tests Compliance Prompt

Make sure the push_swap project passes every test listed below.
These are extracted directly from the official 42 evaluation sheet.
After building the project, run each test and fix any failure before finishing.

---

## 1. README.md Compliance

The repository root must contain a `README.md` that includes ALL of the following:

- [ ] First line is italicized and reads exactly:
  `*This project has been created as part of the 42 curriculum by <login1>.*`
- [ ] A **"Description"** section explaining the project's purpose and a brief overview
- [ ] An **"Instructions"** section with compilation, installation, and/or execution details
- [ ] A **"Resources"** section listing references (documentation, tutorials, etc.)
  AND explaining how AI was used — specifying which tasks and which parts of the project

---

## 2. Memory Leaks

All heap-allocated memory must be properly freed.
The evaluator will run `push_swap` under `valgrind` or monitor with `top`.

- [ ] Zero memory leaks on any input
- [ ] Any single leak causes the final grade to be 0

---

## 3. Error Management

**All 4 of these must pass — if even one fails, 0 points for this section.**

```bash
# Test 1: non-numeric parameter → must print "Error\n" on stderr
./push_swap 0 one 2 3

# Test 2: duplicate numeric parameter → must print "Error\n" on stderr
./push_swap 1 2 3 1

# Test 3: parameter greater than INT_MAX → must print "Error\n" on stderr
./push_swap 2147483648

# Test 4: no parameters → must print nothing and return to prompt
./push_swap
```

Expected: tests 1–3 output `Error` to stderr, test 4 outputs nothing.

---

## 4. Identity Test (already sorted input)

**All of these must output 0 instructions — if even one fails, 0 points for this section.**

```bash
./push_swap 42
./push_swap 2 3
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
ARG="<between 0 and 9 randomly chosen already-sorted values>"
./push_swap $ARG
```

Expected: all produce no output (zero instructions printed).

---

## 5. Simple Version (2–3 numbers)

**Both must pass — if one fails, 0 points for this section.**

```bash
# Test 1: exactly 3 numbers
ARG="2 1 0"
./push_swap $ARG | ./checker_OS $ARG
# checker must display "OK"
# instruction count must be exactly 2 OR 3

# Test 2: between 0 and 3 random values
ARG="<between 0 and 3 random values>"
./push_swap $ARG | ./checker_OS $ARG
# checker must display "OK"
# instruction count must be between 0 and 3 (inclusive)
```

---

## 6. Another Simple Version (5 numbers)

**Both must pass — if one fails, 0 points for this section.**

```bash
# Test 1: fixed input
ARG="1 5 2 4 3"
./push_swap $ARG | ./checker_OS $ARG
# checker must display "OK"
# instruction count must NOT exceed 12
# (kudos / bonus consideration if count is only 8)

# Test 2: 5 random values
ARG="<5 random valid values>"
./push_swap $ARG | ./checker_OS $ARG
# checker must display "OK"
# instruction count must NOT exceed 12
# repeat multiple times with different permutations
```

---

## 7. Middle Version — 100 numbers (scored 0–5)

```bash
ARG="<100 random values>"
./push_swap $ARG | ./checker_OS $ARG
# checker must display "OK"
```

Points awarded based on instruction count:

| Instructions | Points |
|---|---|
| less than 700 | 5 |
| less than 900 | 4 |
| less than 1100 | 3 |
| less than 1300 | 2 |
| less than 1500 | 1 |
| 1500 or more | 0 |

Repeat multiple times with different permutations before validating.

**Target for Radix Sort: stay under 1100 (3 points minimum).**

---

## 8. Advanced Version — 500 numbers (scored 0–5)

```bash
ARG="<500 random values>"
./push_swap $ARG | ./checker_OS $ARG
# checker must display "OK"
```

Points awarded based on instruction count:

| Instructions | Points |
|---|---|
| less than 5500 | 5 |
| less than 7000 | 4 |
| less than 8500 | 3 |
| less than 10000 | 2 |
| less than 11500 | 1 |
| 11500 or more | 0 |

Repeat multiple times with different permutations before validating.

**Target for Radix Sort: stay under 8500 (3 points minimum).**

---

## Quick test commands to run after building

```bash
# Compile
make

# Error management
./push_swap 0 one 2 3
./push_swap 1 2 3 1
./push_swap 2147483648
./push_swap

# Identity (should print nothing)
./push_swap 42
./push_swap 2 3
./push_swap 0 1 2 3

# Simple sort correctness
ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG

# 5 numbers
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG

# 100 numbers benchmark
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_OS $ARG

# 500 numbers benchmark
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_OS $ARG

# Memory leaks
valgrind --leak-check=full ./push_swap 3 1 2 5 4
```

---

## Critical notes

- The evaluator will run the 100 and 500 number tests **multiple times** with
  different permutations. A solution that only works on one specific input will fail.
- Any segfault, crash, or uncontrolled exit during the defense sets the **entire grade to 0**.
- The `checker_OS` binary is provided by 42 in the project intranet attachments.
  Make sure it is present before running tests.
