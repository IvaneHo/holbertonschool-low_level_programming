🔢 0x10. C - Variadic Functions


📌 Variadic functions allow us to pass a variable number of arguments to a function. This project teaches how to use them in C.
🎯 Learning Objectives

✅ What are variadic functions?
✅ How to use va_start, va_arg, and va_end
✅ Why and how to use the const keyword
✅ Handling different argument types dynamically
📁 Project Files & Functions
📂 File	🔍 Description
0-sum_them_all.c	Returns the sum of all parameters
1-print_numbers.c	Prints numbers with a separator
2-print_strings.c	Prints strings, handling NULL values
3-print_all.c	Prints anything based on a format string
variadic_functions.h	Header file containing all function prototypes
🛠 Function Prototypes

#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stddef.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */

⚙️ Compilation

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o main

Run with:

./main

Check for memory leaks using Valgrind:

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

🚀 Usage & Examples
🔢 0. sum_them_all - Sum of all parameters

Prototype:

int sum_them_all(const unsigned int n, ...);

📌 This function returns the sum of all passed arguments.
Example

#include <stdio.h>
#include "variadic_functions.h"

int main(void)
{
    int sum = sum_them_all(4, 10, 20, 30, 40);
    printf("Sum: %d\n", sum);
    return (0);
}

✅ Output:

Sum: 100

🖨 1. print_numbers - Print numbers with a separator

Prototype:

void print_numbers(const char *separator, const unsigned int n, ...);

📌 Prints numbers, separated by a given string.
Example

print_numbers(", ", 3, 1, 2, 3);

✅ Output:

1, 2, 3

📝 2. print_strings - Print strings (Handles NULL values)

Prototype:

void print_strings(const char *separator, const unsigned int n, ...);

📌 Prints strings, handling NULL values by printing (nil).
Example

print_strings("; ", 3, "Hello", NULL, "World");

✅ Output:

Hello; (nil); World

🔀 3. print_all - Print Anything

Prototype:

void print_all(const char * const format, ...);

📌 Prints various data types based on a format string (c, i, f, s).
Example

print_all("ceis", 'A', 123, 3.14, "Hello");

✅ Output:

A, 123, 3.140000, Hello