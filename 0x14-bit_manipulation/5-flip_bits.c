/**
 * flip_bits - Computes the number of bits required to be flipped to
 *             transform one number to another.
 * @n: The first number.
 * @m: The second number to transform the first to.
 *
 * Return: The number of bits required to flip in order to reach from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m, bit_count = 0;

	while (xor_result > 0)
	{
		bit_count += (xor_result & 1);
		xor_result >>= 1;
	}

	return (bit_count);
}
