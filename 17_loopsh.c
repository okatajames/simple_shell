#include "shell.h"
/**
 * hsh - loop for myn chell
 * @info: struct information prmeter and return value
 * @mv: argmnt vec frm meyn()
 * Return: 0 (success), 1 (error), or error cde
 */
int hsh(info_tracker *info, char **mv)
{
ssize_t v = 0;
int builtin_ret = 0;
while (v != -1 && builtin_ret != -2)
{
clear_all(info);
if (mode_interactive(info))
_strhputt("$ ");
_putcharrherr(bufferr_FLUSH);
v = captinput(info);
if (v != -1)
{
setall(info, mv);
builtin_ret = cap_bltin(info);
if (builtin_ret == -1)
comd_finde(info);
}
else if (mode_interactive(info))
charput('\n');
freeall(info, 0);
}
histo_write(info);
freeall(info, 1);
if (!mode_interactive(info) && info->status)
exit(info->status);
if (builtin_ret == -2)
{
if (info->error_numb == -1)
exit(info->status);
exit(info->error_numb);
}
return (builtin_ret);
}
/**
 * cap_bltin - identifying comnd inbuilt
 * @info: rtrn struct inform and parmeter
 * Return: -1 unidentified,
 * 0 successfully found,
 * 1 identified but not sccssfl,
 * 2 terminated prematurely
 */
int cap_bltin(info_tracker *info)
{
int a, built_in_ret = -1;
bult_ins_tracker builtintbl[] = {
{"exit", _shoutexit},
{"environt", shoutenvrt},
{"help", _shoutmanhlp},
{"hist", _shouthist},
{"setenv", shoutsetenvrt},
{"unsetenv", shoutunsetenvrt},
{"cd", _shoutchangedir},
{"alias", _shoutalias},
{NULL, NULL}
};
for (a = 0; builtintbl[a].cmdflag; a++)
if (_comparestrh(info->argv[0], builtintbl[a].cmdflag) == 0)
{
info->couter_lin++;
built_in_ret = builtintbl[a].routine(info);
break;
}
return (built_in_ret);
}
/**
 * comd_finde - identification of cmnd in a pth
 * @info: prmter and rtn of struct information
 * Return: main()
 */
void comd_finde(info_tracker *info)
{
char *loca = NULL;
int a, f;
info->loca = info->argv[0];
if (info->flag_linehcter == 1)
{
info->couter_lin++;
info->flag_linehcter = 0;
}
for (a = 0, f = 0; info->argnull[a]; a++)
if (!delmi_ter(info->argnull[a], " \t\n"))
f++;
if (!f)
return;
loca = pathlookup(info, getenvrt(info, "PATH="), info->argv[0]);
if (loca)
{
info->loca = loca;
comd_folk(info);
}
else
{
if ((mode_interactive(info) || getenvrt(info, "PATH=")
|| info->argv[0][0] == '/') && checkcmd(info, info->argv[0]))
comd_folk(info);
else if (*(info->argnull) != '\n')
{
info->status = 127;
printferr(info, "not found\n");
}
}
}
/**
 * comd_folk - prompt running a command by execs
 * @info: prmtr and struct inrmtn rtn
 * Return: main()
 */
void comd_folk(info_tracker *info)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
/* TODO: insert ERR FUNC */
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->loca, info->argv, getenvrtt(info)) == -1)
{
freeall(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}

}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
printferr(info, "Permission denied\n");
}
}
}
