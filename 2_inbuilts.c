#include "shell.h"
/**
 * _shoutexit - Shell out exit
 * @info: Contains Struct for argnull to const prototype
 *
 * Return: Returns "exit" If user inputs exit, then exit
 */

int _shoutexit(info_tracker *info)
{
	int trackexit;

	if (info->argv[1])
	{
		trackexit = _errhtointi(info->argv[1]);
		if (trackexit == -1)
		{
			info->status = 2;
			printferr(info, "Invalid Integer: ");
			_puterr(info->argv[1]);
			_putcharrherr('\n');
			return (1);
		}
		info->error_numb = _errhtointi(info->argv[1]);
		return (-2);
	}
	info->error_numb = -1;

	return (-2);
}


/**
* _shoutchangedir - change the cwd
* @info: strut with args
*
* Return: Returns 0
*/


int _shoutchangedir(info_tracker *info)
{
	int retur_valcd;
	char *c;
	char bufferrfer[1024];
	char *fold;

	c = getcwd(bufferrfer, 1024);
	if (!c)
	_strhputt("TODO: >>printf failed error msg<<\n");
	if (!info->argv[1])
	{
		fold = getenvrt(info, "HOME=");
		if (!fold)
			chdir((fold = getenvrt(info, "PWD=")) ? fold : "/");
		else
			retur_valcd = chdir(fold);
	}
	else if (_comparestrh(info->argv[1], "-") == 0)
	{
		if (!getenvrt(info, "PLDPRE="))
		{
			_strhputt(c);
			charput('\n');
			return (1);
		}
		_strhputt(getenvrt(info, "PLDPRE=")), charput('\n');
		chdir((fold = getenvrt(info, "PLDPRE=")) ? fold : "/");
	}
	else
	retur_valcd = chdir(info->argv[1]);
	if (retur_valcd == -1)
	{
		printferr(info, "cannot cd ");
		_puterr(info->argv[1]), _putcharrherr('\n');
	}
	else
	{
		setenvrt(info, "PLDPRE", getenvrt(info, "PWD="));
		setenvrt(info, "PWD", getcwd(bufferrfer, 1024));
	}
		return (0);
}


/**
* _shoutmanhlp - change the cwd
* @info: strut with args
*
* Return: Returns 0
*/

int _shoutmanhlp(info_tracker *info)
{
	char **contro_arr;

	contro_arr = info->argv;

	_strhputt("Func call working \n");
	if (0)
	_strhputt(*contro_arr);
	return (0);
}
