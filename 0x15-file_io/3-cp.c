#include "main.h"

/**
 * main - copies contents of one file to another.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t  bytes_read = 1024, bytes_written, close_ret;
	char buffer[1024];

	/* Check the number of arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (-1);
	}

	/* Open the source file */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (-1);
	}

	/* Create the destination file */
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		return (-1);
	}

	/* Copy the contents of source to destination */
	while (bytes_read == 1024)
	{
		bytes_read = read(fd_from, buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close(fd_from);
			close(fd_to);
			return (-1);
		}

		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			return (-1);
		}
	}

	/* Close both files */
	close_ret = close(fd_from);
	if (close_ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %s\n", argv[1]);
		return (-1);
	}

	close_ret = close(fd_to);
	if (close_ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %s\n", argv[2]);
		return (-1);
	}

	return (0);
}
