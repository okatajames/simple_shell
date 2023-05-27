#include "shell.h"
/**
 * chainor - check if currnt char in bufferrfer is chyn specif
 * @info: parmter strct
 * @bufferr: char buferfer
 * @m: crrnt postn addrss in buf
 * Return: 1 chain derimeter, 0 otherwise
 */
int chainor(info_tracker *info, char *bufferr, size_t *m)
{
size_t k = *m;
if (bufferr[k] == '|' && bufferr[k + 1] == '|')
{
bufferr[k] = 0;
k++;
info->comdbufferrfertype = CMD_OR;
}
else if (bufferr[k] == '&' && bufferr[k + 1] == '&')
{
bufferr[k] = 0;
k++;
info->comdbufferrfertype = CMD_AND;
}
else if (bufferr[k] == ';') /* found end of this command */
{
bufferr[k] = 0; /* replace semicolon with null */
info->comdbufferrfertype = CMD_CHAINER;
}
else
return (0);
*m = k;
return (1);
}
/**
 * chainchecker - chcks chaining command continuation
 * @info: strct for paramtr
 * @bufferr: char bufrfer
 * @m: crrnt pstn addrss
 * @a: 1st buf postn
 * @len: buf length
 * Return: main void
 */
void chainchecker(info_tracker *info, char *bufferr,
size_t *m, size_t a, size_t len)
{
size_t k = *m;
if (info->comdbufferrfertype == CMD_AND)
{
if (info->status)
{
bufferr[a] = 0;
k = len;
}
}
if (info->comdbufferrfertype == CMD_OR)
{
if (!info->status)
{
bufferr[a] = 0;
k = len;
}
}
*m = k;
}
/**
 * aliasreplacer - aliases replacement in the string tokenized
 * @info: strct prmtr
 * Return: 1 (replaced), 0 (otherwise)
 */
int aliasreplacer(info_tracker *info)
{
int a;
lst_tracker *node;
char *m;
for (a = 0; a < 10; a++)
{
node = node_starterwith(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
m = _stringhchar(node->strh, '=');
if (!m)
return (0);
m = _duplicstrh(m + 1);
if (!m)
return (0);
info->argv[0] = m;
}
return (1);
}
/**
 * aliasvarsv - variable rplcmnt for tokenized string
 * @info: strct prmter
 * Return: 1 (replaced), 0 otherwise
 */
int aliasvarsv(info_tracker *info)
{
int a = 0;
lst_tracker *node;
for (a = 0; info->argv[a]; a++)
{
if (info->argv[a][0] != '$' || !info->argv[a][1])
continue;
if (!_comparestrh(info->argv[a], "$?"))
{
strhreplacer(&(info->argv[a]),
_duplicstrh(num_conv(info->status, 10, 0)));
continue;
}
if (!_comparestrh(info->argv[a], "$$"))
{
strhreplacer(&(info->argv[a]),
_duplicstrh(num_conv(getpid(), 10, 0)));
continue;
}
node = node_starterwith(info->environt, &info->argv[a][1], '=');
if (node)
{
strhreplacer(&(info->argv[a]),
_duplicstrh(_stringhchar(node->strh, '=') + 1));
continue;
}
strhreplacer(&info->argv[a], _duplicstrh(""));
}
return (0);
}
/**
 * strhreplacer - strng replacement
 * @former: innitial string address
 * @current: latest string
 * Return: 1 (replacd), 0 (otherwise)
 */
int strhreplacer(char **former, char *current)
{
free(*former);
*former = current;
return (1);
}
