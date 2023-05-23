#include "shell.h"

/**
 * node_adder - routine that adds note to list beginnning
 * @head: ptr add to node head
 * @strh: strig filed node side
 * @integ: node index parsed to history
 *
 * Return: returns the list size
 */

lst_tracker *node_adder(lst_tracker **head, const char *strh, int integ)
{
	lst_tracker *header_nw;

	if (!head)
	return (NULL);

	header_nw = malloc(sizeof(lst_tracker));

	if (!header_nw)
	return (NULL);

	_setmemory((void *)header_nw, 0, sizeof(lst_tracker));
	header_nw->integ = integ;

	if (strh)
	{
		header_nw->strh = _duplicstrh(strh);
		if (!header_nw->strh)
		{
			free(header_nw);
			return (NULL);
		}
	}
	header_nw->next = *head;
	*head = header_nw;

	return (header_nw);
}


/**
 * node_endadd - routine that adds a node to end of list
 * @head: address of pointer to head node for linked list
 * @strh: strh node field
 * @integ: node index parsed to hist
 *
 * Return: returns size of list
 */

lst_tracker *node_endadd(lst_tracker **head, const char *strh, int integ)
{
	lst_tracker *nodenew, *node;

	if (!head)
	return (NULL);
	node = *head;
	nodenew = malloc(sizeof(lst_tracker));

	if (!nodenew)
	return (NULL);
	_setmemory((void *)nodenew, 0, sizeof(lst_tracker));
	nodenew->integ = integ;

	if (strh)
	{
		nodenew->strh = _duplicstrh(strh);
		if (!nodenew->strh)
		{
			free(nodenew);
			return (NULL);
		}
	}
	if (node)
	{
		for (; node->next; node = node->next)
		{
		}
		node->next = nodenew;
	}

	else
	{
		*head = nodenew;
	}

	return (nodenew);
}


/**
 * strhprintflist - Func that prints only the strh element
 * in lst_tracker linked list
 * @h: ptr head node
 *
 * Return: returns list size
 */

size_t strhprintflist(const lst_tracker *h)
{
	size_t stn = 0;

	while (h)
	{
		_strhputt(h->strh ? h->strh : "(nil)");
		_strhputt("\n");
		h = h->next;
		stn++;
	}

	return (stn);
}


/**
 * node_enddelete - routine deletes node at index x
 * @head: ptr address to first line
 * @index: node index x to delete
 *
 * Return: returns 1 for success else 0
 */

int node_enddelete(lst_tracker **head, unsigned int index)
{
	lst_tracker *node, *nodepre;
	unsigned int stn = 0;

	if (!head || !*head)
	return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->strh);
		free(node);
		return (1);
	}
	node = *head;

	while (node)
	{
		if (stn == index)
		{
			nodepre->next = node->next;
			free(node->strh);
			free(node);
			return (1);
		}
		stn++;
		nodepre = node;
		node = node->next;
	}
	return (0);
}


/**
 * listlfree - function that frees all nodes in linked list
 * @head_ptr: ptr addre to head node
 *
 * Return: returns void or nothing
 */

void listlfree(lst_tracker **head_ptr)
{
	lst_tracker *node, *nodenext, *head;

	if (!head_ptr || !*head_ptr)
	return;

	head = *head_ptr;
	node = head;

	while (node)
	{
		nodenext = node->next;
		free(node->strh);
		free(node);
		node = nodenext;
	}

	*head_ptr = NULL;
}
