#include "sort.h"

/**
 * node_swapper - this will exchange the two nodes of the doubly linked list
 * @node1: this is the first node
 * @node2: this is the second node
 * @list: this is the list that contains all the nodes
 */
void node_swapper(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - this will use the cocktail shaker sort algorithm 
 * to sort out a doubly list which contains integers in ascending order
 * @list: this is the list which needs to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *node, *tail;

	if (!list || !*list || !(*list)->next)
		return;
	while (!sorted)
	{
		sorted = 1;
		for (node = (*list)->next; node; node = node->next)
		{
			if (node->n < node->prev->n)
			{
				node_swapper(node->prev, node, list);
				print_list(*list);
				sorted = 0;
			}
			tail = node;
		}
		if (sorted)
			break;
		for (node = tail->prev; node; node = node->prev)
		{
			if (node->n > node->next->n)
			{
				node_swapper(node, node->next, list);
				print_list(*list);
				sorted = 0;
			}

		}
	}
}
