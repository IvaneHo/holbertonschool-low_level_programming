#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - copies the content of a file to another
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, exits with codes 97-100 on failure
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, c_from, c_to;
	ssize_t r, w;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", av[2]);
		close(fd_from);
		exit(99);
	}

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			dprintf(2, "Error: Can't write to %s\n", av[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	c_from = close(fd_from);
	if (c_from == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	c_to = close(fd_to);
	if (c_to == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
