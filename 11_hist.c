#include "shell.h"

/**
 * histo_open - opens the history file
 * @info: struct for program and information
 *
 * Return: returns stringh with hist file
 */

char *histo_open(info_tracker *info)
{
	char *bufferr, *fold;

	fold = getenvrt(info, "HOME=");

	if (!fold)
	return (NULL);

	bufferr = malloc(sizeof(char) *
	(_lenstrh(fold) + _lenstrh(HISTRY_DB) + 2));

	if (!bufferr)
	return (NULL);

	bufferr[0] = 0;
	_copystrh(bufferr, fold);
	_concatstrh(bufferr, "/");
	_concatstrh(bufferr, HISTRY_DB);

	return (bufferr);
}


/**
 * histo_write - creates file, or appends to existing file
 * @info: the struct for program and information
 * Return: 1 on success, else -1
 */

int histo_write(info_tracker *info)
{
	ssize_t descrfile;

	char *filename = histo_open(info);

	lst_tracker *node = NULL;

	if (!filename)
	return (-1);

	descrfile = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	if (descrfile == -1)
	return (-1);

	for (node = info->hist; node; node = node->next)
	{
		_putssfiled(node->strh, descrfile);
		_putfiled('\n', descrfile);
	}
	_putfiled(bufferr_FLUSH, descrfile);
	close(descrfile);

	return (1);
}


/**
 * histo_read - routine that reads hitory from the hist file
 * @info: the struct for program and information
 *
 * Return: returns history on success else 0
 */

int histo_read(info_tracker *info)
{
	int q, last = 0, countliner = 0;
	ssize_t descrfile, rdlen, fsize = 0;
	struct stat st;

	char *bufferr = NULL, *filename = histo_open(info);

	if (!filename)
	return (0);
	descrfile = open(filename, O_RDONLY);
	free(filename);
	if (descrfile == -1)
	return (0);
	if (!fstat(descrfile, &st))
	fsize = st.st_size;
	if (fsize < 2)
	return (0);
	bufferr = malloc(sizeof(char) * (fsize + 1));
	if (!bufferr)
	return (0);
	rdlen = read(descrfile, bufferr, fsize);
	bufferr[fsize] = 0;
	if (rdlen <= 0)
	return (free(bufferr), 0);
	close(descrfile);
	for (q = 0; q < fsize; q++)
	if (bufferr[q] == '\n')
	{
		bufferr[q] = 0;
		histo_buildlist(info, bufferr + last, countliner++);
		last = q + 1;
	}
	if (last != q)
	histo_buildlist(info, bufferr + last, countliner++);
	free(bufferr);
	info->counterhistory = countliner;
	while (info->counterhistory-- >= HISTRY_MAXVAL)
	node_enddelete(&(info->hist), 0);
	histo_numbering(info);

	return (info->counterhistory);
}


/**
 * histo_buildlist - routine that adds entry to a hist
 * @info: the struct for program and information
 * @bufferr: variable for buffer
 * @countliner: counts the lines in history
 *
 * Return: returns 0
 */

int histo_buildlist(info_tracker *info, char *bufferr, int countliner)
{
	lst_tracker *node = NULL;

	if (info->hist)
	{
		node = info->hist;
	}
	node_endadd(&node, bufferr, countliner);
	if (!info->hist)
	{
		info->hist = node;
	}

	return (0);
}


/**
 * histo_numbering - routine that renumbers the linked list
 * after factoring in the changes made to it
 * @info: Structure containing potential arguments.
 *
 * Return: returns the new number for the history counted
 */

int histo_numbering(info_tracker *info)
{
	lst_tracker *node = info->hist;

	int a = 0;

	for (; node; node = node->next)
	{
		node->integ = a++;
		}

	return (info->counterhistory = a);
}
