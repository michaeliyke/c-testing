#include "common.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *pass = malloc(sizeof(char) * 5); /* make space */
	char c[5] = {'H', 'o', 'l', 4, '\0'};  /* c = "Hol4"; */
	char run[100];
	/*above is array of size 100 */
	int i;

	/* for each char in c like 'H', 'o', 'l', 4 */
	for (i = 0; c[i]; i++)
		pass[i] = c[i]; /* copy it to pass */

	pass[i] = '\0'; /* null-terminate pass */
	/* copy string: "echo Hol\4 > 101-password" to run */
	sprintf(run, "echo %s > 101-password", pass);
	/* execute the string inside run ont the commandline */
	system(run);
	/* "echo Hol\4 > 101-password" */

	/***
	 * NOTES ABOUT \4
	 * \4 mean EOT - End Of Transmission
	 * It is not a literal '4' which would be '0'+4 or just '4'
	 * Brea that in mind
	 */
	return (0);
}
