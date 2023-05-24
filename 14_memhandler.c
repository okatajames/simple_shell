#include "shell.h"

/**
 * freebatch - pnter freedom and adrss nullification
 * @ptr: pnter's adrss to be freed
 * Return: 1 (freedom), or else 0.
 */
int freebatch(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
