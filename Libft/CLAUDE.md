# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is the **Libft project** from 42 School's Common Core curriculum. It involves reimplementing standard C library functions from scratch to understand low-level memory manipulation and string operations.

The library is built as a static library (`libft.a`) that can be linked with other 42 projects.

## Build System

**Build the library:**
```bash
make
```

**Clean object files:**
```bash
make clean
```

**Clean everything (objects + library):**
```bash
make fclean
```

**Rebuild from scratch:**
```bash
make re
```

**Compiler flags:** `-Wall -Wextra -Werror` (all warnings enabled and treated as errors)

## Code Architecture

### Structure
- **Header file:** `libft.h` - Contains all function prototypes and required includes
- **Source files:** Individual `.c` files for each function (e.g., `ft_strlen.c`, `ft_memcpy.c`)
- **Naming convention:** All functions prefixed with `ft_` (e.g., `ft_strlen`, `ft_isalpha`)

### Function Categories

**Part 1 - Libc Functions:**
Reimplementations of standard C library functions including:
- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- String operations: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`
- Memory operations: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Character conversion: `ft_toupper`, `ft_tolower`
- String conversion: `ft_atoi`

### 42 Header Format
All files use the standard 42 header comment block with author information and timestamps. Maintain this format when creating new files.

## Development Guidelines

### Adding New Functions
1. Create a new `.c` file with the function implementation
2. Add the function prototype to `libft.h`
3. Add the source file to the `SRCS` variable in the Makefile
4. Rebuild with `make re`

### Memory Safety
This is a low-level C library - pay close attention to:
- Buffer overflows and proper bounds checking
- NULL pointer validation
- Memory allocation/deallocation (ensure no leaks)
- Proper handling of edge cases (empty strings, size 0, etc.)

### Testing
There is no built-in test suite. When implementing or modifying functions, create manual test programs or use external testers like:
- francinette
- libft-unit-test
- libftTester

Test programs should be compiled separately and linked against `libft.a`.
