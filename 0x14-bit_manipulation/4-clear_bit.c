/**
 * clear_bit - Sets the value of a bit at a given index to 0.
 * @n: A pointer to the bit.
 * @index: The index where the value needs to be set to 0.
 *
 * Return: If an error occurred, it returns -1. Otherwise, it returns 1.
 */
int clear_bit(unsigned long int *num, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*num &= ~(1 << index);

	return (1);
}
