#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <main.h>
/**
 * check_args - Validates the number of arguments.
 * @ac: Argument count.
 */
void check_args(int ac)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_file - Opens a file and returns its descriptor.
 * @filename: The name of the file.
 * @flags: The flags to use with open().
 * @mode: The mode for creation (if applicable).
 * @err_code: The code to exit with on failure.
 * Return: The file descriptor.
 */
int open_file(const char *filename, int flags, mode_t mode, int err_code)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		if (err_code == 98)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		else if (err_code == 99)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(err_code);
	}
	return (fd);
}

/**
 * close_file - Closes a file descriptor, exiting on failure.
 * @fd: The file descriptor.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of one file to another.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, exits with codes 97 to 100 on failure.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[1024];

	check_args(ac);

	fd_from = open_file(av[1], O_RDONLY, 0, 98);
	fd_to = open_file(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664, 99);

	while ((r = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			close_file(fd_from);
			close_file(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}

	if (r == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	close_file(fd_from);
	close_file(fd_to);
	return (0);
}
