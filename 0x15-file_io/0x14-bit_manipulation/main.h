#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>

/**
 * struct bity - struct to rep the info of each binary token for efficient use
 * @ch: represents the binary char token - either 1 or 0
 * @index: reprsents the heirarchy of this token during calculations
 * @next: the next bity node
 *
 * This struct contructs enough info to effectively understand the significance
 *  of the token during calculations
 */
typedef struct bity
{
	char ch;
	int index;
	struct bity *next;
} bity_t;

int _putchar(char c);
bity_t *add_node(bity_t **head, char ch, int index);
int _strlen(char *string);
bity_t *get_bits(char *chars);
unsigned int binary_to_uint(const char *b);
char *_strcpy(char *dest, char *src);
void list_bity(bity_t *h);
void _strrev(char *a);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
bity_t *make_bits(unsigned long int num);
void binarize(unsigned long int n, bity_t **head);
bity_t *get_node(bity_t *head, int index);
void list_bity(bity_t *h);
bity_t *add_node_(bity_t *head, int index, char ch);
int set_bit(unsigned long int *n, unsigned int index);
unsigned int count_bits(unsigned long int x);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int get_endianness(void);

#endif
