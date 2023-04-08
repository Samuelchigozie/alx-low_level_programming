#include "main.h"

/**
  * _strlen - function that calculates length of a string.
  * @s: input string
  * Return: length of the string.
**/
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
	{
		len++;
	}
	return (len);
}

/**
* create_file - Create a function that creates a file and writes content to it.
* @filename: name of file to be created.
* @text_content: string to be written into the file.
* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
	ssize_t nletters;
	int fd;

	if (!filename)
		return (1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		nletters = write(fd, text_content, _strlen(text_content));
		if (nletters == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
