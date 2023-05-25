#include "shell.h"
/**
 * _setmemory - occupying persistent bytes in the memory
 * @g: mmry location pointer
 * @d: persistent byte used
 * @q: total of byte to be filled
 * Return: mmry location pnter(g)
 */
char *_setmemory(char *g, char d, unsigned int q)
{
unsigned int a;
for (a = 0; a < q; a++)
g[a] = d;
return (g);
}
/**
 * freememory - releasing trngs' trng
 * @zz: strngs' strng
 */
void freememory(char **zz)
{
char **e = zz;
if (!zz)
return;
while (*zz)
free(*zz++);
free(e);
}
/**
 * _memoryrealloc - reassigning a piece of memory
 * @ptr: malloc block pnter
 * @old_size: byt syze of the block before
 * @new_size: fresh block byt syze
 * Return: oldblck name pnter.
 */
void *_memoryrealloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *m;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
m = malloc(new_size);
if (!m)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
m[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (m);
}
