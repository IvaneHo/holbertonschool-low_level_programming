#include <stdio.h>
#include <stdlib.h>

/**
* main - Multiplies two numbers
* @argc: Number of arguments
* @argv: Array of arguments
*
* Return: 0 on success, 1 if error
*/
int main(int argc, char *argv[])
{
int result;

if (argc != 3)
{
printf("Error\n");
return (1);
}

result = atoi(argv[1]) * atoi(argv[2]);
printf("%d\n", result);

return (0);
}
