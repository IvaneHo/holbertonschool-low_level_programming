#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - Print error message and exit
 * @code: Exit code
 * @msg: Error message
 * @arg: Argument string (filename)
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * safe_close - Closes a file descriptor with error check
 * @fd: File descriptor to close
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
 * main - Copies contents of one file to another
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 on success, exit on failure
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[1024];

	if (ac != 3)
		print_error(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		safe_close(fd_from), print_error(99, "Error: Can't write to %s\n", av[2]);

	while ((r = read(fd_from, buffer, 1024)) > 0)
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
