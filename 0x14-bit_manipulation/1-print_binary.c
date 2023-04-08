#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned long int.
 * @num: The number to be printed in binary.
 */
void print_binary(unsigned long int num)
{
	if (num > 1)
		print_binary(num >> 1);

	_putchar((num & 1) + '0');
}
