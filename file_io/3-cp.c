#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * print_error - Prints an error message and exits
 * @code: The exit code
 * @msg: The format message to print
 * @arg: The argument to format into the message
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * safe_close - Closes a file descriptor and handles errors
 * @fd: The file descriptor to close
 */
void safe_close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of one file into another
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, exits with codes 97 to 100 on failure
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[BUF_SIZE];

	if (ac != 3)
		print_error(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		safe_close(fd_from), print_error(99, "Error: Can't write to %s\n", av[2]);

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
			safe_close(fd_from), safe_close(fd_to),
			print_error(99, "Error: Can't write to %s\n", av[2]);
	}
	if (r == -1)
		safe_close(fd_from), safe_close(fd_to),
		print_error(98, "Error: Can't read from file %s\n", av[1]);

	safe_close(fd_from);
	safe_close(fd_to);
	return (0);
}
