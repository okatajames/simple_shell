#include "shell.h"

/**
 * strinhtoken2 - words extracted from strings. delims reptd are foregone
 * @strh: strng input
 * @x: strng specif
 * Return: an arry of strngs' pointr, otherwise NULL (fail)
 */

char **strinhtoken2(char *strh, char *x)
{
int a, k, f, t, numwords = 0;
char **g;
if (strh == NULL || strh[0] == 0)
return (NULL);
if (!x)
x = " ";
for (a = 0; strh[a] != '\0'; a++)
if (!delmi_ter(strh[a], x) && (delmi_ter(strh[a + 1], x) || !strh[a + 1]))
numwords++;
if (numwords == 0)
return (NULL);
g = malloc((1 + numwords) *sizeof(char *));
if (!g)
return (NULL);
for (a = 0, k = 0; k < numwords; k++)
{
while (delmi_ter(strh[a], x))
a++;
f = 0;
while (!delmi_ter(strh[a + f], x) && strh[a + f])
f++;
g[k] = malloc((f + 1) * sizeof(char));
if (!g[k])
{
for (f = 0; f < k; f++)
free(g[f]);
free(g);
return (NULL);
}
for (t = 0; t < f; t++)
g[k][t] = strh[a++];
g[k][t] = 0;
}
g[k] = NULL;
return (g);
}
/**
 * **strinhtoken3 - extract wrds 4m strng
 * @strh: strng for stdin
 * @x: specif
 * Return: strings array pnter
 */
char **strinhtoken3(char *strh, char x)
{
int a, k, f, t, numwords = 0;
char **g;
if (strh == NULL || strh[0] == 0)
return (NULL);
for (a = 0; strh[a] != '\0'; a++)
if ((strh[a] != x && strh[a + 1] == x) ||
(strh[a] != x && !strh[a + 1]) || strh[a + 1] == x)
numwords++;
if (numwords == 0)
return (NULL);
g = malloc((1 + numwords) *sizeof(char *));
if (!g)
return (NULL);
for (a = 0, k = 0; k < numwords; k++)
{
while (strh[a] == x && strh[a] != x)
a++;
f = 0;
while (strh[a + f] != x && strh[a + f] && strh[a + f] != x)
f++;
g[k] = malloc((f + 1) * sizeof(char));
if (!g[k])
{
for (f = 0; f < k; f++)
free(g[f]);
free(g);
return (NULL);
}
for (t = 0; t < f; t++)
g[k][t] = strh[a++];
g[k][t] = 0;
}
g[k] = NULL;
return (g);
}
