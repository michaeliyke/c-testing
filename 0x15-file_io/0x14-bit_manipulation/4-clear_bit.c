#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: input integer
 * @index: is the index, starting from 0 of the bit you want to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= 64)
		return (-1);
	/* maks has all bits set to 1 except bit at index */
	mask = ~(1 << index);
	*n &= mask;

	return (1);
}
