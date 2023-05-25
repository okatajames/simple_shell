#include "shell.h"
/**
 * _lenstrh - for string length
 * @g: checking for length of the string
 * Return: string length in integers
 */
int _lenstrh(char *g)
{
int a = 0;
if (!g)
return (0);
while (*g++)
a++;
return (a);
}
/**
 * _comparestrh - lexicogarphic comparisons o 2 strngz.
 * @g1: 1st strng
 * @g2: 2nd strng
 * Return: -ve for g1 < g2, +ve for g1 > g2, 0 for g1 == g2
 */
int _comparestrh(char *g1, char *g2)
{
while (*g1 && *g2)
{
if (*g1 != *g2)
return (*g1 - *g2);
g1++;
g2++;
}
if (*g1 == *g2)
return (0);
else
return (*g1 < *g2 ? -1 : 1);
}
/**
 * startwith - does nidle begin with haystack
 * @haystack: search string
 * @needle: search substring
 * Return: nxt in line hystck address otherwise NULL
 */
char *startwith(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
 * _concatstrh - cat two strngs
 * @dest: final destinatn bufferrfer
 * @src: parent bufferrfer
 * Return: destintn bufferrfer pointer
 */
char *_concatstrh(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
