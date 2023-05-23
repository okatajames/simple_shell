#include "shell.h"

/**
 * clear_all - routine that inits info tracker
 * @info: struct info
 *
 */

void clear_all(info_tracker *info)
{
	info->argnull = NULL;
	info->argv = NULL;
	info->loca = NULL;
	info->argc = 0;
}


/**
 * setall - init info_tracker
 * @info: struct for the routine
 * @av: args
 */

void setall(info_tracker *info, char **av)
{
	int e = 0;

	info->filenamef = av[0];

	if (info->argnull)
	{
		info->argv = strinhtoken2(info->argnull, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _duplicstrh(info->argnull);
				info->argv[1] = NULL;
			}
		}

		for (e = 0; info->argv && info->argv[e]; e++)
		;
		{
			info->argc = e;
		}
		aliasreplacer(info);
		aliasvarsv(info);
	}
}


/**
 * freeall - info_tracker struct field is freed
 * @info: address of struct
 * @all: true if freeing fields
 */

void freeall(info_tracker *info, int all)
{
	freememory(info->argv);
	info->argv = NULL;
	info->loca = NULL;

	if (all)
	{
		/*if (!info->comdbufferrfer)*/
		/*free(info->argnull);*/
		if (info->environt)
		listlfree(&(info->environt));
		if (info->hist)
		listlfree(&(info->hist));
		if (info->alias)
		listlfree(&(info->alias));
		freememory(info->environ);
		info->environ = NULL;
		freebatch((void **)info->comdbufferrfer);
		if (info->filereader > 2)
		close(info->filereader);
		charput(bufferr_FLUSH);
	}
}
