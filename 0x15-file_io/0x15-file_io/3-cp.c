#include "main.h"

/**
 * main - check the code
 * @ac: ac
 * @av: av
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int res, fd_to, fd_from;
	size_t len = 0;

	(void)res;
	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_to = open(av[2], O_CREAT | O_WRONLY | O_EXCL, 0664);
	fd_from = open(av[1], O_APPEND | O_WRONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	if (fd_to == -1)
	{
		fd_to = open(av[2], O_WRONLY);
		if (fd_to == -1 || ftruncate(fd_to, len) == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}

	f_copy(&fd_from, &fd_to, av[1], av[2]);
	return (0);
}

/**
 * f_copy - copy file contents from one fd to another
 * @fd_from: fd of the from file
 * @fd_to: fd of the to file
 * @from_pth: path name of from file
 * @to_pth: path naame of of the to file
 *
 * Return: void
 */
void f_copy(int *fd_from, int *fd_to, char *from_pth, char *to_pth)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(*fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(*fd_to, buffer, BUFFER_SIZE);
		if (bytes_written == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", to_pth);
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", from_pth);
	}
	if (close(*fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", *fd_to);
		exit(100);
	}
	if (close(*fd_from) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", *fd_from);
		exit(100);
	}
}
