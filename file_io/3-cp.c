#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * validate_args - Ensures the correct number of arguments is provided.
 * @argc: Argument count.
 */
void validate_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_source_file - Opens the source file for reading.
 * @filename: Name of the source file.
 * Return: File descriptor for the source file.
 */
int open_source_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest_file - Opens or creates the destination file for writing.
 * @filename: Name of the destination file.
 * Return: File descriptor for the destination file.
 */
int open_dest_file(const char *filename)
{
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_content - Copies content from one file descriptor to another.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 */
void copy_content(int fd_from, int fd_to)
{
	ssize_t r, w;
	char buffer[1024];

	while ((r = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		exit(98);
	}
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
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
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	validate_args(argc);

	fd_from = open_source_file(argv[1]);
	fd_to = open_dest_file(argv[2]);

	copy_content(fd_from, fd_to);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
