#include "main.h"

char *increase_mem(char *buffer, int buffer_size);

/**
 * main - entry point
 *
 * Return: 0 always
 * 59-10
 */
int main(void)
{
	FILE *stream = stdin;
	size_t size = 0;
	char *line = NULL;

	_getline(&line, &size, stream);
	printf("%s", line);
	return (0);
}

/**
 * _getline - reads a whole line from an input stream
 * @lineptr: variable to store the address of the line string
 * @size: the size of strinmg read
 * @stream: the file stream to read from
 *
 * Return: the number of bytes read or -1 in the case of error
 * ---------- INFO About The Read syscall ------------------------------
 * Read function return details
 * if read returns 0, its EOF condition
 * if read returns -1, read encountered an error
 * if read returns +1 or higher, its the number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *size, FILE *stream)
{
	int fd = fileno(stream); /* Get the file description of the stream */
	ssize_t bytes_rd;	 /* Set after reading loop completes */
	size_t bytes = 64;	 /* chars read to read at once */
	/*bytes*16 = 1024 = 1KB */
	size_t buffer_size = bytes << 4;
	char *buffer = malloc(sizeof(char) * buffer_size);
	size_t len = 0; /* overall buffer string length */

	while ((bytes_rd = read(fd, buffer + len, bytes)) != -1)
	{
		len += bytes_rd;
		if (len >= buffer_size)
		{ /* if remaining buffer is low */
			/* increase and copy over the existing data */
			buffer_size += (bytes << 1); /* bytes*2 */
			buffer = increase_mem(buffer, buffer_size);
			if (buffer == NULL)
				return (-1);
		}
		if (buffer[len - 1] == '\n')
			break; /* break after newline char*/
	}
	if (bytes_rd == -1)
		return (-1);
	buffer[len] = '\0';
	*size = len, *lineptr = buffer; /* Update lineptr and size */
	/* bytes_rd and len are 0 if it's EOF, return -1 in that case60-22 */
	/* otherwise, return legth of string read */
	if (bytes_rd == 0 && len == 0)
		return (-1);
	return (len);
}

/**
 * increase_mem - increase buffer size and copy data over
 * @buffer: buffer to increase
 * @buffer_size: new buffer size
 *
 * Return: new buffer of size buffer_size with the all data present
 */
char *increase_mem(char *buffer, int buffer_size)
{
	char *new_buffer = malloc(sizeof(char) * buffer_size);

	if (new_buffer == NULL)
		return (NULL);
	strcpy(new_buffer, buffer);
	return (new_buffer);
}
