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
* Return: Always 0
*/


int _shoutchangedir(info_tracker *info)
{
	char *s, *dir, bufferrfer[1024];
	int retur_valcd;

	s = getcwd(bufferrfer, 1024);
	if (!s)
	_strhputt("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = getenvrt(info, "HOME=");
		if (!dir)
			chdir((dir = getenvrt(info, "PWD=")) ? dir : "/");
		else
			retur_valcd = chdir(dir);
	}
	else if (_comparestrh(info->argv[1], "-") == 0)
	{
		if (!getenvrt(info, "OLDPWD="))
		{
			_strhputt(s);
			charput('\n');
			return (1);
		}
		_strhputt(getenvrt(info, "OLDPWD=")), charput('\n');
		chdir((dir = getenvrt(info, "OLDPWD=")) ? dir : "/");
	}
	else
	retur_valcd = chdir(info->argv[1]);
	if (retur_valcd == -1)
	{
		printferr(info, "can't cd to ");
		_puterr(info->argv[1]), _putcharrherr('\n');
	}
	else
	{
		setenvrt(info, "OLDPWD", getenvrt(info, "PWD="));
		setenvrt(info, "PWD", getcwd(bufferrfer, 1024));
	}
		return (0);
}


/**
* _shoutmanhlp - change the cwd
* @info: strut with args
*
* Return: Always 0
*/

int _shoutmanhlp(info_tracker *info)
{
	char **contro_arr;

	contro_arr = info->argv;

	_strhputt("help call works. Function not yet implemented \n");
	if (0)
	_strhputt(*contro_arr);
	return (0);
}
