#include "main.h"

/**
 * binary_to_uint - entry handler for binary to unsigned int conversion
 * @b: binary string which is to be converted to unsigned int
 *
 * Return: returns the resulting unsigned integer
 */
unsigned int binary_to_uint(const char *b)
{
	char *cpy = malloc(sizeof(*cpy) * _strlen((char *)b)), *_, ch;
	int i, j, len, total = 0;
	bity_t *head = NULL, *ptr;

	(void)_; /* throw-away var to avoid compiler warning */
	_ = _strcpy(cpy, (char *)b);
	_strrev(cpy);
	len = _strlen(cpy);
	if (cpy == NULL)
		return (0);
	/*  build the the bity linked list with binary string */
	for (i = 0, j = 1; i < len; i++, j <<= 1)
	{
		ch = cpy[i];
		if (ch != '0' && ch != '1')
			return (0);
		head = add_node_(head, j, ch);
	}

	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->ch == '1')
			total += ptr->index;
	}
	return (total);
}

/**
 * add_node_ - add node at the begining of list
 * @head: pointer to the pointer to the head of list
 * @index: index property for the new node
 * @ch: ch property for the new node
 *
 * Return: pointer to new bity node
 */
bity_t *add_node_(bity_t *head, int index, char ch)
{
	bity_t *ptr = malloc(sizeof(*ptr));

	if (ptr == NULL)
		return (NULL);
	ptr->ch = ch;
	ptr->index = index;
	ptr->next = head;
	head = ptr;
	return (ptr);
}

/**
 * _strlen - returns length of a string
 * @string: input string whose length is needed
 *
 * Return: length of string
 */
int _strlen(char *string)
{
	char *pointer = string;

	if (string == NULL || *string == '\0')
		return (0);
	while (*string != '\0')
		++string;
	return ((string - pointer));
}

/**
 * _strcpy - copies *src, including the \0 char,to dest
 * @dest: the destination of copy operation
 * @src: the source of copy operation
 *
 * Return: pointer to str
 */
char *_strcpy(char *dest, char *src)
{
	int i = _strlen(src);
	char *ptr = dest;

	while (i > 0 && *src != '\0')
	{
		*dest++ = *src++;
		i--;
	}
	*dest++ = '\0';
	return (ptr);
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
