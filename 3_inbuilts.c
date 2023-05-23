#include "shell.h"
/**
 * _shouthist - show the history list, one comd per line starting from index 0
 * @info: struct with our args linked to const prototype
 *
 *  Return: Returns 0
 */

int _shouthist(info_tracker *info)
{
	printflistl(info->hist);
	return (0);
}


/**
 * unset_alias - set the alias to stringh
 * @info: struct param
 * @strh: stringh alias
 *
 * Return: return 1 = success, 0 = error
 */

int unset_alias(info_tracker *info, char *strh)
{
	char *p, c;
	int ret;

	p = _stringhchar(strh, '=');

	if (!p)
	{
		return (1);
	}

	c = *p;
	*p = 0;
	ret = node_enddelete(&(info->alias),
	node_indexcapt(info->alias, node_starterwith(info->alias, strh, -1)));
	*p = c;

	return (ret);
}


/**
 * set_alias - set the alias to stringh
 * @info: struct param
 * @strh: stringh alias
 *
 * Return: return 1 = success, 0 = error
 */

int set_alias(info_tracker *info, char *strh)
{
	char *p;

	p = _stringhchar(strh, '=');

	if (!p)
	{
		return (1);
	}

	if (!*++p)
	{
		return (unset_alias(info, strh));
	}
	unset_alias(info, strh);

	return (node_endadd(
		&(info->alias), strh, 0) == 0);  /* Change last 0 to NULL if error */
}


/**
 * print_alias - print alias stringh
 * @node: alias node
 *
 * Return: return 1 = success, 0 = error
 */

int print_alias(lst_tracker *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _stringhchar(node->strh, '=');

		for (a = node->strh; a <= p; a++)
		{
			charput(*a);
		}
		charput('\'');
		_strhputt(p + 1);
		_strhputt("'\n");
		return (0);
	}

	return (1);
}


/**
 * _shoutalias - mimics the alias bult_ins (man alias)
 * @info: struct with our args linked to const prototype
 *
 *  Return: Returns 0
 */

int _shoutalias(info_tracker *info)
{
	int x = 0;
	char *p = NULL;
	lst_tracker *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (x = 1; info->argv[x]; x++)
	{
		p = _stringhchar(info->argv[x], '=');
		if (p)
		{
			set_alias(info, info->argv[x]);
		}

		else
		{
			print_alias(node_starterwith(info->alias, info->argv[x], '='));
		}
	}
	return (0);
}
