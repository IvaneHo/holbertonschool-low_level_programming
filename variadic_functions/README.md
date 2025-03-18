variadic functionssssssssssssssapkdpojzfpajdpizafipaj


# 0x10. C - Variadic Functions

## Description

This project explores **variadic functions** in C, which allow passing a variable number of arguments to a function. You'll learn how to use the `stdarg.h` library to manipulate these arguments efficiently.

## Learning Objectives

- What are variadic functions?
- How to use `va_start`, `va_arg`, and `va_end`
- Why and how to use the `const` keyword
- How to handle different argument types dynamically

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Compilation: `gcc -Wall -pedantic -Werror -Wextra -std=gnu89`
- Code must follow the **Betty style**
- No `for`, `goto`, `ternary operator`, `else`, `do ... while`
- Maximum of:
  - 2 `while` loops
  - 2 `if` statements
  - 9 variables per function

---

## Files & Functions

| File                  | Description |
|----------------------|-------------|
| `0-sum_them_all.c`  | Function that returns the sum of all its parameters |
| `1-print_numbers.c` | Function that prints numbers with a separator |
| `2-print_strings.c` | Function that prints strings, handling `NULL` values |
| `3-print_all.c`     | Function that prints anything based on a format specifier |
| `variadic_functions.h` | Header file with all function prototypes |

---

## Function Prototypes (in `variadic_functions.h`)

```c
#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stddef.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */

Compilation

To compile all the files:

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o main

To compile and check for memory leaks:

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

Usage
0. sum_them_all

Function to sum all given arguments.
Example

#include <stdio.h>
#include "variadic_functions.h"

int main(void)
{
    int sum;

    sum = sum_them_all(4, 10, 20, 30, 40);
    printf("Sum: %d\n", sum);
    return (0);
}

Output

Sum: 100

1. print_numbers

Function to print numbers with a separator.
Example

print_numbers(", ", 3, 1, 2, 3);

Output

1, 2, 3

2. print_strings

Function to print strings, replacing NULL with (nil).
Example

print_strings("; ", 3, "Hello", NULL, "World");

Output

Hello; (nil); World

3. print_all

Function to print various data types based on a format string.
Example

print_all("ceis", 'A', 123, 3.14, "Hello");

Output

A, 123, 3.140000, Hello