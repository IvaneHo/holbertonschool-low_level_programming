#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - prints error message and exits with code
 * @code: exit code
 * @msg: format string
 * @file: file name to print
 */
void print_error(int code, const char *msg, const char *file)
{
	dprintf(STDERR_FILENO, msg, file);
	exit(code);
}

/**
 * close_file - closes file descriptor and exits on failure
 * @fd: file descriptor
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
 * open_files - opens source and destination files
 * @av: argument vector
 * @fd_from: pointer to source fd
 * @fd_to: pointer to destination fd
 */
void open_files(char **av, int *fd_from, int *fd_to)
{
	*fd_from = open(av[1], O_RDONLY);
	if (*fd_from == -1)
		print_error(98, "Error: Can't read from file %s\n", av[1]);

	*fd_to = open(av[2], O_WRONLY | O_TRUNC);
	if (*fd_to == -1)
	{
		*fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (*fd_to == -1)
		{
			close_file(*fd_from);
			print_error(99, "Error: Can't write to %s\n", av[2]);
		}
	}
}

/**
 * copy_loop - reads and writes from source to destination
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_to: destination file name (for error message)
 */
void copy_loop(int fd_from, int fd_to, const char *file_to)
{
	char buffer[1024];
	ssize_t r, w;

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			close_file(fd_from);
			close_file(fd_to);
			print_error(99, "Error: Can't write to %s\n", file_to);
		}
	}
	if (r == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		print_error(98, "Error: Can't read from file %s\n", file_to);
	}
}

/**
 * main - entry point
 * @ac: argument count
 * @av: argument values
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(av, &fd_from, &fd_to);
	copy_loop(fd_from, fd_to, av[2]);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
