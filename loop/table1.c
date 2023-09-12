#include <stdio.h>
#include <stdlib.h>
unsigned int count_bits(unsigned long int x);
char *get_bits2(int n);
char *get_bits3(unsigned int n);
void _strrev(char *a);
int get_endianness(void);

/**
 * main - entry point
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	unsigned int x = 10;
	int c;
	(void)x;

	if (argc == 2)
		x = atoi(argv[1]);
	c = get_endianness();
	printf("%d\n", c);
	return (0);
}

/**
 * get_bits2 - gets the bits of a number in form or a string
 * @n: an integer number
 *
 * Return: string representation of the bits of n
 */
char *get_bits2(int n)
{
	char *bits = malloc(sizeof(int) * 65);
	int i;

	for (i = 0; n; i++, n >>= 1)
	{
		bits[i] = (n & 1) + '0';
	}
	bits[i] = '\0';
	_strrev(bits);
	return (bits);
}

char *get_bits3(unsigned int n)
{
	char *bits = malloc(sizeof(int) * 65);
	int i;
	char *ch = (char *)&n;

	for (i = 0; ch[i]; i++)
	{
		printf("Character is %c\n", ch[i] + '0');
		bits[i] = ch[i] + '0';
	}
	bits[i] = '\0';
	_strrev(bits);
	return (bits);
}

/**
 * _strrev -  reverses a string.
 * @a: pointer to string to reverse
 *
 * Return: void
 */
void _strrev(char *a)
{
	char *b = a;
	char temp;

	while (*a != '\0')
	{
		a++;
	}
	a--;
	while (a > b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		a--;
		b++;
	}
}

int get_endianness(void)
{
	unsigned int i = 15; /* unsigned int i is 4 bytes - 0001 */

	/**
	 * Get the address of i into a pointer.
	 * This gives you access to the underlying storage of i in memory
	 * So c is now a string pointing to the entire value of i in memory
	 * i.e c = "0001" #Big Endian
	 * c == 0 #Big Endian
	 * OR
	 * c = "1000" #Little Endian
	 * c === 1 #Little Endian
	 */

	char *c = (char *)&i;

	(void)c;
	/* printf("%c\n", *c + '0'); */
	/* if (*c == 1)
	{
		return (1);
	} */

	for (i = 0; c[i]; i++)
		printf("%c\n", c[i]);

	return (0);
}
