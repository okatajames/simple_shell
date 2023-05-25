#include "shell.h"

/**
 * _puterr - routine that prints input strh
 * @strh: strh to be printed
 * Return: returns nothing
 */

void _puterr(char *strh)
{
	int k = 0;

	if (!strh)
	{
		return;
	}

	for (k = 0; strh[k] != '\0'; k++)
	{
		_putcharrherr(strh[k]);
	}


}


/**
 * _putcharrherr - write charc to stderr
 * @c: charc to be printed
 *
 * Return: on success returns 1 else -1
 */

int _putcharrherr(char c)
{
	static char bufferr[WRITE_bufferrFER_SIZE];
	static int k;

	if (c == bufferr_FLUSH || k >= WRITE_bufferrFER_SIZE)
	{
		write(2, bufferr, k);
		k = 0;
	}

	if (c != bufferr_FLUSH)
	{
		bufferr[k++] = c;
	}
	return (1);
}


/**
 * _putfiled - routine writes the cahrc to given file desc
 * @c: character to print
 * @filedesc: filedescriptor to write to
 *
 * Return: 1 for success, else -1
 */

int _putfiled(char c, int filedesc)
{
	static char bufferr[WRITE_bufferrFER_SIZE];
	static int v;

	if (c == bufferr_FLUSH || v >= WRITE_bufferrFER_SIZE)
	{
		write(filedesc, bufferr, v);
		v = 0;
	}

	if (c != bufferr_FLUSH)
	{
		bufferr[v++] = c;
	}

	return (1);
}


/**
 * _putssfiled - printfs strh given as input
 * @strh: strh to print
 * @filedesc: our file descriptor
 *
 * Return: returns the count of chars printed
 */

int _putssfiled(char *strh, int filedesc)
{
	int k = 0;

	if (!strh)
	{
		return (0);
	}

	while (*strh)
	{
		k += _putfiled(*strh++, filedesc);
	}

	return (k);
}
