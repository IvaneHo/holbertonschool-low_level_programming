#include "main.h"

/**
 * open_file_from - opens source file for reading
 * @filename: source file name
 * Return: file descriptor
 */
int open_file_from(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_file_to - opens dest file for writing
 * @filename: destination file name
 * Return: file descriptor
 */
int open_file_to(const char *filename)
{
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * close_fd - closes file descriptor
 * @fd: file descriptor
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies file_from to file_to
 * @fd_from: source file descriptor
 * @fd_to: dest file descriptor
 * @file_to: dest file name (for error msg)
 */
void copy_file(int fd_from, int fd_to, const char *file_to)
{
	ssize_t r, w;
	char buffer[1024];

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			dprintf(2, "Error: Can't write to %s\n", file_to);
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(2, "Error: Can't read from file\n");
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}
}

/**
 * main - entry point, copies content of file_from to file_to
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(av[1]);
	fd_to = open_file_to(av[2]);
	copy_file(fd_from, fd_to, av[2]);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
