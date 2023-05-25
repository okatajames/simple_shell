#include "shell.h"

/**
 * _errhtointi - routine that convs an int to strh
 * @s: strh converted
 *
 * Return: returns 0 if string lacks integ, conv integ otherwise, -1 else
 */

int _errhtointi(char *s)
{
	unsigned long int outputt = 0;
	int t = 0;

	if (*s == '+')
	{
		s++;
	}

	t = 0;
	do {
		if (s[t] >= '0' && s[t] <= '9')
		{
			outputt *= 10;
			outputt += (s[t] - '0');

			if (outputt > INT_MAX)
			{
				return (-1);
			}
		} else
		{
			return (-1);
		}
		t++;
	} while (s[t] != '\0');


	return (outputt);
}


/**
 * printferr - function to print err messages
 * @info: Param return and informaton struct
 * @estr: gets parsed the specified errtype
 *
 * Return: returns 0 if string lacks integ, conv integ otherwise, -1 else
 */

void printferr(info_tracker *info, char *estr)
{
	_puterr(info->filenamef);
	_puterr(": ");
	printf_delim(info->couter_lin, STDERR_FILENO);
	_puterr(": ");
	_puterr(info->argv[0]);
	_puterr(": ");
	_puterr(estr);
}


/**
 * printf_delim - routine that prints int in base 10
 * @input:  routine input
 * @filedesc: the description parsed
 * Return: returns tracker of chars
 */

int printf_delim(int input, int filedesc)
{
	unsigned int _abs_, presentval;
	int (*__putchar)(char) = charput;
	int q;
	int tracker = 0;

	if (filedesc == STDERR_FILENO)
	{
		__putchar = _putcharrherr;
	}
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		tracker++;
	}
	else
	{
		_abs_ = input;
	}
	presentval = _abs_;

	q = 1000000000;
	while (q > 1)
	{
		if (_abs_ / q)
		{
			__putchar('0' + presentval / q);
			tracker++;
		}
		presentval %= q;
		q /= 10;
	}

	__putchar('0' + presentval);
	tracker++;
	return (tracker);
}


/**
 * num_conv - converts q to t
 * @integ: numb handler
 * @base: base handler
 * @flags: flag argnull
 *
 * Return: returns strh
 */

char *num_conv(long int integ, int base, int flags)
{
	char sign = 0;
	char *ptr;
	unsigned long u = integ;
	static char *array;
	static char bufferrfer[50];


	if (!(flags & CONV_UNSIGN) && integ < 0)
	{
		u = -integ;
		sign = '-';
	}
	array = flags & CONV_LOWERCHAR ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &bufferrfer[49];
	*ptr = '\0';


	for (; u != 0; u /= base)
	{
		*--ptr = array[u % base];
	}

		if (sign)
		*--ptr = sign;
		return (ptr);
}


/**
 * comet_rem - replaces instance of '#' with '\0'
 * @bufferr: strh address to modify
 *
 * Return: returns 0;
 */

void comet_rem(char *bufferr)
{
	int q;

	q = 0;
	while (bufferr[q] != '\0')
	{
		if (bufferr[q] == '#' && (!q || bufferr[q - 1] == ' '))
		{
			bufferr[q] = '\0';
			break;
		}
		q++;
	}


}
