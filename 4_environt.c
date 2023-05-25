#include "shell.h"


/**
 * shoutenvrt - this routine prints the envt
 * @info: struct that contains potential args
 *
 * Return: returns 0
 */

int shoutenvrt(info_tracker *info)
{
	strhprintflist(info->environt);
	return (0);
}


/**
 * getenvrt - get value of environ variable
 * @info: struct with potential args
 * @name: environt var name
 *
 * Return: returns NULL
 */

char *getenvrt(info_tracker *info, const char *name)
{
	lst_tracker *node = info->environt;

	char *p;

	for (; node != NULL; node = node->next)
	{
		p = startwith(node->strh, name);
		if (p && *p)
		{
			return (p);
		}
	}

		return (NULL);
}


/**
 * shoutsetenvrt - new env var init or modify previous one
 * @info: struct with potential args
 *
 *  Return: returns 1
 */

int shoutsetenvrt(info_tracker *info)
{
	if (info->argc != 3)
	{
		_puterr("Wrong Argument Number\n");
		return (1);
	}

	if (setenvrt(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}

	return (1);
}


/**
 * shoutunsetenvrt - rem env variable
 * @info: struct with potential args
 *
 * Return: returns 0
 */

int shoutunsetenvrt(info_tracker *info)
{
	int b;

	if (info->argc == 1)
	{
		_puterr("Few Arguments.\n");
		return (1);
	}

	for (b = 1; b <= info->argc; b++)
	{
		unsetevnrt(info, info->argv[b]);
	}

	return (0);
}


/**
 * shoutpopuenvrtlist - populates environt linked list
 * @info: struct with potential args
 *
 * Return: returns 0
 */

int shoutpopuenvrtlist(info_tracker *info)
{
	size_t t;

	lst_tracker *node = NULL;

	t = 0;
	while (environ[t])
	{
		node_endadd(&node, environ[t], 0);
		t++;
	}

	info->environt = node;
	return (0);
}
