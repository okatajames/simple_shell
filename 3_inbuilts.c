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
 * Return: return 1 = executed, 0 = error
 */

int unset_alias(info_tracker *info, char *strh)
{
	char h;
	int outtt;
	char *r;

	r = _stringhchar(strh, '=');

	if (!r)
	{
		return (1);
	}

	h = *r;
	*r = 0;

	outtt = node_enddelete(&(info->alias),
	node_indexcapt(info->alias,
	node_starterwith(info->alias, strh, -1)));
	*r = h;

	return (outtt);
}


/**
 * alset - set the alias to stringh
 * @info: struct param
 * @strh: stringh alias
 *
 * Return: return 1 = success, 0 = error
 */

int alset(info_tracker *info, char *strh)
{
	char *r;

	r = _stringhchar(strh, '=');

	if (!r)
	{
		return (1);
	}

	if (!*++r)
	{
		return (unset_alias(info, strh));
	}
	unset_alias(info, strh);

	return (node_endadd(
		&(info->alias), strh, 0) == 0);  /* Change last 0 to NULL if error */
}


/**
 * aliaspr - print alias stringh
 * @node: alias node
 *
 * Return: return 1 = success, 0 = error
 */

int aliaspr(lst_tracker *node)
{
	char *k = NULL;
	char *r = NULL;

	if (node)
	{
		r = _stringhchar(node->strh, '=');

		for (k = node->strh; k <= r; k++)
		{
			charput(*k);
		}
		charput('\'');
		_strhputt(r + 1);
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
	char *r = NULL;
	lst_tracker *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			aliaspr(node);
			node = node->next;
		}
		return (0);
	}

	x = 1;
	while (info->argv[x]) {
		r = _stringhchar(info->argv[x], '=');
		if (r) {
			alset(info, info->argv[x]);

		} else {
			aliaspr(node_starterwith(info->alias, info->argv[x], '='));
		}
		x++;
	}

	return (0);
}
