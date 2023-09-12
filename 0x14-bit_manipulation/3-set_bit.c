#include "main.h"

/**
 * set_bit - sets the nth bit of an integer to 1
 * @n: pointer to unsigned long interger input
 * @index: index is the index, starting from 0 of the bit you want to set
 *
 * Return: 1 if success and -1 if fails
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 64)
		return (-1);
	*n |= (1 << index);

	return (1);
}
