#include "deck.h"

/**
 * node_swapper - this will exchange two nodes of a doubly linked list
 * @node1: this will be the first node
 * @node2: this will be the second node
 * @deck: this will be the list where nodes will be contained
 */
void node_swapper(deck_node_t *node1, deck_node_t *node2, deck_node_t **deck)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		(*deck) = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * compare - this will differentiate two nodes
 * @node: this will be the current node
 * @prev: this will be the previous node
 * @cmp: this will be the index of comparison
 * Return: either 1 or 0
 */
int compare(const card_t *node, const card_t *prev, int cmp)
{
	int value1 = 0, value2 = 0, i;
	values_t v[] = {
		{"Ace", 1},
		{"Jack", 11},
		{"Queen", 12},
		{"King", 13}
	};
	if (cmp == 0)
	{
		for (i = 0; i < 4; i++)
		{
			if (!strcmp(node->value, v[i].name))
				value1 = v[i].val;
			if (!strcmp(prev->value, v[i].name))
				value2 = v[i].val;
		}
		if (!value1)
			value1 = atoi(node->value);
		if (!value2)
			value2 = atoi(prev->value);
	}
	if (cmp == 1)
	{
		value1 = node->kind;
		value2 = prev->kind;
	}
	if (value1 < value2)
		return (1);
	return (0);
}

/**
 * bubble_sort_deck - this will use the bubble sort algorithm, 
 * to sort out a doubly list of integers in ascending order
 * @deck: this is the deck which needs to be sorted
 * @cmp: this will be the index of comparison
 */
void bubble_sort_deck(deck_node_t **deck, int cmp)
{
	int sorted = 0;
	deck_node_t *node;

	if (!deck || !*deck || !(*deck)->next)
		return;
	while (!sorted)
	{
		sorted = 1;
		for (node = (*deck)->next; node; node = node->next)
		{
			if (compare(node->card, node->prev->card, cmp))
			{
				node_swapper(node->prev, node, deck);
				sorted = 0;
			}
		}
	}
}

/**
 * sort_deck - this will sort out the deck of cards
 * @deck: this is the deck which needs to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	bubble_sort_deck(deck, 0);
	bubble_sort_deck(deck, 1);
}
