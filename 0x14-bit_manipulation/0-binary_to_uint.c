#include "main.h"

/**
 * binary_to_uint - converts a binary string to an unsigned int
 * @binary_str: pointer to binary string
 *
 * Return: unsigned int value of binary string, or 0 if invalid binary string
 */
unsigned int binary_to_uint(const char *binary_str)
{
    unsigned int decimal = 0;

    /* Check for null pointer input */
    if (!binary_str)
        return (0);

    /* Traverse binary string, converting binary digits to decimal */
    while (binary_str && *binary_str)
    {
        /* Check for invalid binary digit */
        if (*binary_str < '0' || *binary_str > '1')
            return (0);

        /* Convert binary digit to decimal and add to total */
        decimal = decimal * 2 + *binary_str - '0';
        binary_str++;
    }

    /* Return the resulting decimal value */
    return (decimal);
}
