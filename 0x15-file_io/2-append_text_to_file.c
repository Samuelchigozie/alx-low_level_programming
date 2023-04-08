#include "main.h"

/**
  * _strlen - Returns the length of a string.
  * @str: The input string.
  *
  * Return: The length of @str.
  */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
  * append_text_to_file - Appends text at the end of a file.
  * @filename: The name of the file to append to.
  * @text_content: The text to append to the file.
  *
  * Return: 1 on success, -1 on failure.
  */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t num_written;
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		num_written = write(fd, text_content, _strlen(text_content));
		if (num_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
