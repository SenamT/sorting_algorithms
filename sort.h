#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - this is the node for the  doubly linked list
 *
 * @n: this is the integer which is stored in the node
 * @prev: this will indicate the first component in the list
 * @next: this will indicate the following component of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sort algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Advanced sort algorithms */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif
