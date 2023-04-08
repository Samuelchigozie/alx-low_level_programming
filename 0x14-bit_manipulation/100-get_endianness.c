#include "main.h"

/**
 * get_endianness - Determines the endianness of the system.
 *
 * Return: If big-endian - 0.
 *         If little-endian - 1.
 */
int get_endianness(void)
{
    int num = 1;
    char *endian_check = (char *)&num;

    if (*endian_check == 1)
        return (1);

    return (0);
}
