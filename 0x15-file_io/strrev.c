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

