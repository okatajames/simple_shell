#include "shell.h"
/**
 * _copystrh - cp string
 * @dest: destntn
 * @src: srce
 * Return: destntn pnter
 */
char *_copystrh(char *dest, char *src)
{
int a = 0;
if (dest == src || src == 0)
return (dest);
while (src[a])
{
dest[a] = src[a];
a++;
}
dest[a] = 0;
return (dest);
}
/**
 * _duplicstrh - dplcate string
 * @strh: dplicatn string
 * Return: duplicated string pnter
 */
char *_duplicstrh(const char *strh)
{
int length = 0;
char *ret;
if (strh == NULL)
return (NULL);
while (*strh++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--strh;
return (ret);
}
/**
 * _strhputt - fprintf input strng
 * @strh: strng for prntng
 * Return: null
 */
void _strhputt(char *strh)
{
int a = 0;
if (!strh)
return;
while (strh[a] != '\0')
{
charput(strh[a]);
a++;
}
}
/**
 * charput - input char r to stdout
 * @r: char for output
 * Return: 1 (success)
 * err, -1 (err), othwise set errno
 */
int charput(char r)
{
static int a;
static char bufferr[WRITE_bufferrFER_SIZE];
if (r == bufferr_FLUSH || a >= WRITE_bufferrFER_SIZE)
{
write(1, bufferr, a);
a = 0;
}
if (r != bufferr_FLUSH)
bufferr[a++] = r;
return (1);
}
