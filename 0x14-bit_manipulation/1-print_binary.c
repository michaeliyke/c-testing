#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: a postine interger input
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	if (n == 0 || n == 1)
	{
		_putchar('0' + n);
		return;
	}
	print_binary(n >> 1);
	_putchar('0' + (n & 1));
}

/**
 * get_bits2 - gets the bits of a number in form or a string
 * @n: an integer number
 *
 * Return: string representation of the bits of n
 */
char *get_bits2(int n)
{
	char bits[65];
	int i;

	for (i = 0; n; i++, n >>= 1)
	{
		bits[i] = n & 1;
	}
	bits[i] = '\0';
	return (bits);
}
