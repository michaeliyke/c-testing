#include "main.h"

/**
 * flip_bits - number of bits you would need to flip to get from number A to B
 * @n:  number A
 * @m: number B
 *
 * Return: integer number of bits to be flipped
 *
 * This will computes and returns the number of bits between A to B
 * The number of bits you would need to flip to get from one number to another
 *  is also known as the Hamming distance between the two numbers.
 * It is a measure of how different two binary strings are
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int c = n ^ m;
	unsigned long int d = 0;

	/**
	 * Start clearing the set bits one at a time from the right
	 * if a bit is set, turn it to 0 until all bits are only 0s
	 * Do this while incrementing the counter to be returned
	 */
	while (c != 0)
	{
		d++;
		c &= (c - 1); /* Clear the rightmost set bit */
	}

	return (d);
}

/**
 * count_bits - get the number of bits present in an integer
 * @x: integer input
 *
 * Return: the count of the bits in x
 */
unsigned int count_bits(unsigned long int x)
{
	int bits = 0;

	while (x != 0)
	{
		bits++;
		x >>= 1;
	}
	return (bits);
}
