#include "shell.h"

/**
 * getenvrtt - routine that copes env and returns it as an an arr
 * @info: struct to store args
 *
 * Return: Returns
 */

char **getenvrtt(info_tracker *info)
{
	if (!info->environ || info->changedenvt)
	{
		info->environ = listltostrh(info->environt);
		info->changedenvt = 0;
	}
	return (info->environ);
}


/**
 * unsetevnrt - routine that unsets env varh
 * @info: struct to store args
 * @var: string environt var property
 *
 *  Return: returns 1 for success, 0 otherwise
 */

int unsetevnrt(info_tracker *info, char *var)
{
	size_t si = 0;
	char *ch;
	lst_tracker *node = info->environt;


	if (!node || !var)
	return (0);


for (node = info->environt; node; node = node->next, si++)
{
    ch = startwith(node->strh, var);
    if (ch && *ch == '=')
    {
        info->changedenvt = node_enddelete(&(info->environt), si);
        si = 0;
        node = info->environt;
        continue;
    }
}

	return (info->changedenvt);
}


/**
 * setenvrt - routine to init env var & modify existing env
 * @info: struct to assign dand store data
 * @var: the current state of the env var
 * @value: the current value of the env var
 *
 * Return: return 0 for success, else -1
 */

int setenvrt(info_tracker *info, char *var, char *value)
{
	char *bufferr = NULL;
	lst_tracker *node;
	char *ch;

	if (!var || !value)
	{
		return (0);
	}
	bufferr = malloc(_lenstrh(var) + _lenstrh(value) + 2);
	if (!bufferr)
	{
		return (1);
	}
	_copystrh(bufferr, var);
	_concatstrh(bufferr, "=");
	_concatstrh(bufferr, value);
	node = info->environt;

	while (node)
	{
		ch = startwith(node->strh, var);

		do {
		if (ch && *ch == '=')
		{
			free(node->strh);
			node->strh = bufferr;
			info->changedenvt = 1;
			return (0);
		}
		} while (0);

		node = node->next;
	}
	node_endadd(&(info->environt), bufferr, 0);
	free(bufferr);
	info->changedenvt = 1;
	return (0);
}
