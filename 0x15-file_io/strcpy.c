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

