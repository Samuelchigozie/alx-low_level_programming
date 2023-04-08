#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @num_ptr: A pointer to the number.
 * @index: The index to set the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int set_bit(unsigned long int *num_ptr, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*num_ptr ^= (1 << index);

	return (1);
}
