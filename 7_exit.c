#include "shell.h"

/**
 * *_stringhcopy - routine that copies a string
 * @dest: the string destination
 * @src: the string source
 * @n: number of chars to be copied
 *
 * Return: returns stringh in concatenated format
 */

char *_stringhcopy(char *dest, char *src, int n)
{
	int p, q;

	char *k = dest;

	p = 0;

	while (src[p] != '\0' && p < n - 1)
	{
		dest[p] = src[p];
		p++;
	}
	if (p < n)
	{
		q = p;
		while (q < n)
		{
			/*dest[q] = '\0'; look into this later */
			q++;
		}
	}
	return (k);
}


/**
 **_stringhconcat - routine that concats 2 stringsh
 *@dest: stringh1
 *@src: stringh2
 *@n: memory in bytes allcoated to handle this
 *
 *Return: returns concat stringh
 */

char *_stringhconcat(char *dest, char *src, int n)
{
	int p, q;

	char *k = dest;

	p = 0;
	q = 0;


	for (p = 0; dest[p] != '\0'; p++)
	{

	}

	for (q = 0; src[q] != '\0' && q < n; q++)
	{
		dest[p] = src[q];
		p++;
	}


	if (q < n)
	{
		dest[p] = '\0';
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
