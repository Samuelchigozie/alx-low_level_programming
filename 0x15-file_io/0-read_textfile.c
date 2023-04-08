#include "main.h"

/**
 * read_file_content - reads a file and writes its content to stdout
 * @filename: the name of the file to read
 * @bytes: the number of bytes to read and write
 * Return: the number of bytes printed to stdout or 0 on failure
 */
ssize_t read_file_content(const char *filename, size_t bytes)
{
    ssize_t bytes_read, bytes_written;
    int file_descriptor;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * bytes + 1);
    if (buffer == NULL)
        return (0);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
    {
        free(buffer);
        return (0);
    }

    bytes_read = read(file_descriptor, buffer, sizeof(char) * bytes);
    if (bytes_read == -1)
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1)
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    free(buffer);
    close(file_descriptor);
    return (bytes_written);
}
