#include "shell.h"
/**
 * lenlistl - linked list length determination
 * @b: first node pointer
 * Return: list size
 */

size_t lenlistl(const lst_tracker *b)
{
	size_t a = 0;

	for (; b; b = b->next, a++)
	{
	}

	return (a);
}

/**
 * listltostrh - returning an array of strings for lists to strh
 * @head: first node's pointer
 * Return: an array of strings
 */

char **listltostrh(lst_tracker *head)
{
	lst_tracker *node = head;
	size_t a = lenlistl(head), k;
	char *strh;
	char **strh2;

	if (!head || !a)
	return (NULL);
	strh2 = malloc(sizeof(char *) * (a + 1));
	if (!strh2)
	return (NULL);

a = 0;
while (node)
{
strh = malloc(_lenstrh(node->strh) + 1);
if (!strh)
{
for (k = 0; k < a; k++)
free(strh2[k]);
free(strh2);
return (NULL);
}
strh = _copystrh(strh, node->strh);
strh2[a] = strh;
node = node->next;
a++;
}

	strh2[a] = NULL;
	return (strh2);
}

/**
 * printflistl - lst_tracker elements printing
 * @b: first node pointer
 * Return: size of the list
 */

size_t printflistl(const lst_tracker *b)
{
size_t a = 0;


for (; b; b = b->next)
{
_strhputt(num_conv(b->integ, 10, 0));
charput(':');
charput(' ');
_strhputt(b->strh ? b->strh : "(nil)");
_strhputt("\n");
a++;
}

return (a);
}


/**
 * node_starterwith - nodes whose string starts with a prefix are reflected
 * @node: list head pointer
 * @prefix: match strng
 * @r: character following prefix to match
 * Return: mtch node or ()null
 */

lst_tracker *node_starterwith(lst_tracker *node, char *prefix, char r)
{
char *m = NULL;

for (; node; node = node->next)
{
m = startwith(node->strh, prefix);
if (m && ((r == -1) || (*m == r)))
{
return (node);
}
}


return (NULL);
}
/**
 * node_indexcapt - capturing a node for the index
 * @head: list head pointer
 * @node: node pointer
 * Return: node to index or -1(fail)
 */
ssize_t node_indexcapt(lst_tracker *head, lst_tracker *node)
{
size_t a = 0;

for (a = 0; head; head = head->next, a++)
{
if (head == node)
{
return (a);
}
}

return (-1);
}
