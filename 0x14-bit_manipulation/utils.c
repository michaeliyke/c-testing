#include "main.h"

/**
 * list_bity - function to list all the indexes of a bity list
 * @h: the head of the list
 *
 * Return: void
 */
void list_bity(bity_t *h)
{
	bity_t *b = h;
	int index;

	if (h == NULL)
		return;

	for (index = 0; b != NULL; index++)
	{
		printf("%d: %c\n", index, b->ch);
		b = b->next;
	}
}

/**
 * get_bits - builds the the bity linked list with binary string
 * @chars: the binary string which is to be converted to to unsigned decimal
 *
 * Return: returns a bity linked list
 */
bity_t *get_bits(char *chars)
{
	int i, j, len = _strlen(chars); /* counter */
	char ch;
	bity_t *head = NULL;

	for (i = 0, j = 1; i < len; i++, j <<= 1)
	{
		ch = chars[i];
		if (ch != '0' && ch != '1')
			return (0);
		head = add_node_(head, j, ch);
	}
	return (head);
}
