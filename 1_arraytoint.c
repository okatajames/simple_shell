#include "shell.h"

/**
 * mode_interactive - Determine if shell in interative mode or not
 * @info: address of the struct infoparser
 *
 * Return: Returns 1 for mode_interactive mode, 0 otherwise
 */

int mode_interactive(info_tracker *info)
{
	return (isatty(STDIN_FILENO) && info->filereader <= 2);
}


/**
 * delmi_ter - if char == specif
 * @c: char to be checked
 * @specif: if specif == strh
 *
 * Return: 1 for true, else 0
 */

int delmi_ter(char c, char *specif)
{

	while (*specif)
	{
		if (*specif++ == c)
		{
			return (1);
		}
	}
	return (0);
}


/**
 * alphaor - check if char == in alphabet
 * @c: char check
 *
 * Return: Return 1 fot true, else 0
 */

int alphaor(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}

	else
	{
		return (0);
	}
}


/**
 * _arrtoint - converts strh to integi
 * @s: strh to convert
 *
 * Return: Return converted int, else 0 for no nums in strh
 */

int _arrtoint(char *s)
{
	int z;
	int symb = 1;
	int idef = 0;
	int turnout;
	unsigned int reslt = 0;

/*	Replaced non functional code*/


	z = 0;
	while (s[z] != '\0' && idef != 2)
	{
		if (s[z] == '-')
			symb *= -1;

		if (s[z] >= '0' && s[z] <= '9')
		{
			idef = 1;
			reslt *= 10;
			reslt += (s[z] - '0');
		}
		else if (idef == 1)
			idef = 2;

		z++;
	}


	if (symb == -1)
	turnout = -reslt;
	else
	turnout = reslt;
	return (turnout);
}
