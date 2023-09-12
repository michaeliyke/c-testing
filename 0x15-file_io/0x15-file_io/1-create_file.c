#include "main.h"

/**
 * create_file -  creates a file
 * @pth: pathname of file
 * @text_content: the string to be added to the file
 * finame is the name of the file to create
 * text_content is the str to write
 * create file with permissions rw-  ---  --- => 110 000 000 0600
 * if file exists, don't change the permisions, just truncate it
 * if text_content is null create empty file
 *
 * Return: -1 on error and 1 on success
 */
int create_file(const char *pth, char *text_content)
{
	int fd, num_written;
	size_t len = _strlen(text_content);

	if (pth == NULL)
		return (-1);
	fd = open(pth, O_CREAT | O_WRONLY | O_EXCL, 0600);
	/* fails if file exists */
	if (fd == -1) /* file likely exists */
	{
		fd = open(pth, O_RDWR);
		if (fd == -1 || ftruncate(fd, len - len) == -1)
			return (-1);
	}
	if (text_content == NULL)
		return (1);
	num_written = write(fd, text_content, _strlen(text_content));
	return (num_written == -1 ? -1 : 1);
}
