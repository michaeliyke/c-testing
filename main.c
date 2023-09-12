#include "main.h"

/**
 * Display bits example
 * @value: int which bits is to be displayed
 *
 * Return: void
 */
void display_bits(unsigned int value)
{
	unsigned msk = 1 << 31;
	printf("%u", msk);
}

/**
 * main - main function
 *
 * Return: Always 0
 */
int main(void)
{
	display_bits(65000);
	return (0);
}
