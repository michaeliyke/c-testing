#include "main.h"

/**
 * get_bit - returns the bit value corresponding to an index from a given int
 * @n: a long unsigned int input value
 * @index: the index of returned bit
 *
 * Return: the bit value at index
 *
 * Bit here simply means one of the binary values of the input integer value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	bity_t *head = make_bits(n);
	bity_t *node = get_node(head, index);

	/* list_bity(head); */
	if (node == NULL)
		return (-1);
	return (node->ch - '0');
}

/**
 * add_node - add node at the begining of list
 * @head: pointer to the pointer to the head of list
 * @index: index property for the new node
 * @ch: ch property for the new node
 *
 * Return: pointer to new bity node
 */
bity_t *add_node(bity_t **head, char ch, int index)
{
	bity_t *ptr = malloc(sizeof(*ptr));

	if (ptr == NULL)
		return (NULL);
	ptr->ch = ch;
	ptr->index = index;
	ptr->next = *head;
	*head = ptr;
	return (*head);
}

/**
 * get_node - returns the node at index;
 * @head: pointer to the head of the linked list
 * @index: the index of node to retrieve
 *
 * Return: Node at index or NULL if not found
 */
bity_t *get_node(bity_t *head, int index)
{
	bity_t *ptr;
	int i;

	for (ptr = head, i = 0; ptr != NULL && i <= index; i++)
	{
		if (i == index)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

/**
 * binarize - populates a bity_t list the binary representation of a number
 * @n: an unsigned interger input
 * @head: double pointer to the head of bity_t linked list to popilate
 *
 * Return: void
 */
void binarize(unsigned long int n, bity_t **head)
{
	if (n == 0 || n == 1)
	{
		add_node(head, ('0' + (n & 1)), 0);
		return;
	}
	binarize((n >> 1), head);
	add_node(head, '0' + (n & 1), 0);
}

/**
 * make_bits - converts an int to bin and creates a linked list with the data
 * @num: the int to be converted to binary
 *
 * Return: the head of a bity linked list where each binary digit is a node
 */
bity_t *make_bits(unsigned long int num)
{
	bity_t **head = malloc(sizeof(**head));

	binarize(num, head);
	return (*head);
}
