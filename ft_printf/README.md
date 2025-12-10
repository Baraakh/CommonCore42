*This project has been created as part of the 42 curriculum by bkhilo*

# ft_printf

## Description

The `ft_printf` project aims to **recode the standard C library function `printf()`**. The goal is to build a function, `ft_printf()`, that mimics the original's behavior of displaying text and variables on the standard output using a format string.

### Core Learning Objectives
* Discovering and implementing **variadic functions** in C. This is key to building a function that accepts a variable number of arguments.
* How to work with binary data and display it into different representations.

### Implemented Conversions
The `ft_printf` function handles the following conversion specifiers:

| Conversion | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a `void *` argument in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number (integer). |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a literal percent sign. |

---

## Algorithms and Data Structures

A detailed explanation and justification of the chosen algorithm and data structure is required. 
### Variadic Function Implementation (`va_...` macros)
The core challenge is handling an unknown number of arguments. This is achieved using the `<stdarg.h>` header file and its associated macros:
* `va_list`: A type used to store information needed by the macros that handle variable argument lists.
* `va_start`: Initializes the `va_list` object.
* `va_arg`: Retrieves the next argument in the list.
* `va_end`: Performs cleanup for the `va_list` object.

### Control Flow (The Dispatcher)
The `ft_printf` function iterates over the format string. When a percent sign (`%`) is encountered, a **dispatcher** or **handler** pattern is used:
1.  **Parsing:** The character immediately following the `%` (the conversion specifier) is read.
2.  **Dispatch:** This character is used to select the appropriate helper function (e.g., `ft_putstr` for `%s`, `ft_puthex` for `%x`, etc.) that knows how to process the argument retrieved via `va_arg` and print the result.
3.  **Recursion:** For printing different bases (like `%d`, `%u`, `%x`), a recursive division algorithm is used to convert the number into its string representation for output.

---

## Instructions

### Compilation and Installation

1.  **Clone the Repository:** Download the project source files from the remote Git repository:
    ```bash
    git clone <repository_url> <local_directory_name>
    ```
2.  **Navigate to the Directory:**
    ```bash
    cd <local_directory_name>
    ```
3.  **Compile the Library:** Use the provided Makefile to compile the source code and create the static library `libftprintf.a`:
    ```bash
    make
    ```
    This command will also create the necessary object files (`.o`).
    (Optional: You can use `make clean` afterward to remove the object files.)

### Usage and Execution

To use the `ft_printf` library in your own C code:

1.  **Create a main file (e.g., `main.c`):** Ensure you include the necessary header file at the top of your program:
    ```c
    #include "ft_printf.h"
    // ... your main function with calls to ft_printf ...
    ```
2.  **Compile Your Program:** You must link your program with the static library (`libftprintf.a`) and include the directory where the header file is located.

    ```bash
    cc -Wall -Wextra -Werror main.c -L. -lftprintf -o <file_name>
    ```
    * `-L.` tells the compiler to look for libraries in the current directory.
    * `-lftprintf` links against `libftprintf.a`.

3.  **Execute the Program:**
    ```bash
    ./<file_name>
    ```

---

## Resources

### Classic References
* **man page:** The classic documentation for the original function:
    ```bash
    man printf
    ```
* **Variadic Functions in C:** A helpful resource for understanding `va_start`, `va_arg`, and `va_end`:
    * https://www.geeksforgeeks.org/c/variadic-functions-in-c/ 

### AI Usage Policy and Description

 *AI was used to review and clean up the README.md file. No project source code was generated or modified by AI.*

---