#include "shell.h"
/**
 * main - entry point
 * @ac: argnull count
 * @av: argnull vector
 * Return: 0 for success, 1 for error
 */
int main(int ac, char **av)
{
info_tracker info[] = { INITIALIZE_INFORN };
int filedesc = 2;
asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (filedesc)
: "r" (filedesc));
if (ac == 2)
{
filedesc = open(av[1], O_RDONLY);
if (filedesc == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_puterr(av[0]);
_puterr(": 0: Can't open ");
_puterr(av[1]);
_putcharrherr('\n');
_putcharrherr(bufferr_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->filereader = filedesc;
}
shoutpopuenvrtlist(info);
histo_read(info);
hsh(info, av);
return (EXIT_SUCCESS);
}
