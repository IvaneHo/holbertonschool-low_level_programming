#include <stdio.h>
#include <stdlib.h>

/**
* is_number - Checks if a string consists only of digits
* @str: The string to check
*
* Return: 1 if the string is a number, 0 otherwise
*/
int is_number(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] < '0' || str[i] > '9')
return (0);
}
return (1);
}

/**
* main - Adds positive numbers
* @argc: Number of arguments
* @argv: Array of arguments
*
* Return: 0 on success, 1 if error
*/
int main(int argc, char *argv[])
{
int i, sum = 0;

if (argc == 1)
{
printf("0\n");
return (0);
}

for (i = 1; i < argc; i++)
{
if (!is_number(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}

printf("%d\n", sum);
return (0);
}
