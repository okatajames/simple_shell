#include "shell.h"
/**
 * checkcmd - if the file an executable comnd or
 * @info: struct of the information
 * @loca: file loca
 * Return: 1 (yes), 0 (no)
 */
int checkcmd(info_tracker *info, char *loca)
{
struct stat st;
(void)info;
if (!loca || stat(loca, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
/**
 * checkdups - xter duplication
 * @varparth: string loca
 * @beginn: index for starting
 * @endn: index for finishing
 * Return: fresh bufferrfer's pnter
 */
char *checkdups(char *varparth, int beginn, int endn)
{
static char bufferr[1024];
int a = 0, f = 0;
for (f = 0, a = beginn; a < endn; a++)
if (varparth[a] != ':')
bufferr[f++] = varparth[a];
bufferr[f] = 0;
return (bufferr);
}

/**
 * pathlookup - identifying string loca
 * @info: struct of information
 * @varparth: string loca
 * @cmd: command line for search
 * Return: complete commandline loca or null
 */

char *pathlookup(info_tracker *info, char *varparth, char *cmd)
{
int a = 0, curr_pos = 0;
char *loca;
if (!varparth)
return (NULL);
if ((_lenstrh(cmd) > 2) && startwith(cmd, "./"))
{
if (checkcmd(info, cmd))
return (cmd);
}
while (1)
{
if (!varparth[a] || varparth[a] == ':')
{
loca = checkdups(varparth, curr_pos, a);
if (!*loca)
_concatstrh(loca, cmd);
else
{
_concatstrh(loca, "/");
_concatstrh(loca, cmd);
}
if (checkcmd(info, loca))
return (loca);
if (!varparth[a])
break;
curr_pos = a;
}
a++;
}
return (NULL);
}
