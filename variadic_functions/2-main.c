#include <stddef.h>  /* Include this for NULL */
#include "variadic_functions.h"

/**
 * main - Check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_strings(", ", 2, "Jay", "Django");
    print_strings("; ", 3, "Hello", NULL, "World");
    print_strings(NULL, 2, "Alice", "Bob");
    print_strings(", ", 1, "Only one");
    print_strings(", ", 0);
    return (0);
}
