#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: a path to read file contents from
 * @letters: letters is the number of letters it should read and print
 *
 * Return:  actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *str = malloc(sizeof(*str) * letters);
	ssize_t num_read, num_written;
	int fd;

	if (filename == NULL || str == NULL)
		return (0);

	fd = open(filename, O_RDONLY); /* open */
	if (fd == -1)
		return (0);

	num_read = read(fd, str, letters); /* read */
	if (num_read == -1)
		return (0);

	num_written = write(STDOUT_FILENO, str, num_read); /* write */
	if (num_written < num_read)
		return (0);
	close(fd);
	free(str);
	return (num_written);
}
