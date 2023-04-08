#include "main.h"
#include <string.h>

/**
 * append_content_to_file - appends content to a file
 * @filename: the name of the file to append content to
 * @content: the content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_content_to_file(const char *filename, char *content)
{
	int fd, num_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	num_written = write(fd, content, strlen(content));
	close(fd);

	if (num_written == -1)
		return (-1);

	return (1);
}

/**
 * create_file - creates a file and writes content to it
 * @filename: the name of the file to create
 * @content: the content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *content)
{
	int fd, num_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	num_written = write(fd, content, strlen(content));
	close(fd);

	if (num_written == -1)
		return (-1);

	return (1);
}
