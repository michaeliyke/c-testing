#include "main.h"
/**
 * get_endianness -  checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int i = 1; /* unsigned int i is 4 bytes - 0001 */

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

	if (*c == 1)
	{
		/* printf("%c\n", *c + '0'); */
		return (1);
	}
	return (0);
}
