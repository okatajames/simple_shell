#include "shell.h"

/**
 * *_stringhcopy - routine that copies a string
 * @orig2: the string destination
 * @orig1: the string source
 * @n: number of chars to be copied
 *
 * Return: returns stringh in concatenated format
 */

char *_stringhcopy(char *orig2, char *orig1, int n)
{
	int p, q;

	char *k = orig2;

	p = 0;

	while (orig1[p] != '\0' && p < n - 1)
	{
		orig2[p] = orig1[p];
		p++;
	}
	if (p < n)
	{
		q = p;
		while (q < n)
		{
			/*orig2[q] = '\0'; look into this later */
			q++;
		}
	}
	return (k);
}


/**
 **_stringhconcat - routine that concats 2 stringsh
 *@orig2: stringh1
 *@orig1: stringh2
 *@n: memory in bytes allcoated to handle this
 *
 *Return: returns concat stringh
 */

char *_stringhconcat(char *orig2, char *orig1, int n)
{
	int p, q;

	char *k = orig2;

	p = 0;
	q = 0;


	for (p = 0; orig2[p] != '\0'; p++)
	{

	}

	for (q = 0; orig1[q] != '\0' && q < n; q++)
	{
		orig2[p] = orig1[q];
		p++;
	}


	if (q < n)
	{
		orig2[p] = '\0';
	}
	return (k);
}


/**
 **_stringhchar - routine that locates char in stringh
 *@k: strh to be given to routine
 *@c: var to store char
 *
 *Return: returns (k), ptr to memory area of k
 */

char *_stringhchar(char *k, char c)
{
	while (*k != '\0')
	{
		if (*k == c)
		{
			return (k);
		}
		k++;
	}
	return (NULL);
}
