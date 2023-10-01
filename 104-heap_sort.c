#include "sort.h"

/**
 * swap - this will swap two components of an array
 * @n1: this is the first component which needs to be swapped
 * @n2: this is the second component which needs to be swapped
*/
void swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n2;
	*n2 = *n1;
	*n1 = tmp;
}

/**
 * heap_max - this is a function which is in charge of shift down
 * @base: this is the base rows index
 * @ele: this is the arrays component
 * @size: this is the arrays size
 * @array: this is the array which needs to be sorted
*/
void heap_max(int *array, size_t size, size_t base, size_t ele)
{
	size_t max = ele, left, right;

	left = 2 * ele + 1;
	right = 2 * ele + 2;

	if (left < base && array[left] > array[max])
		max = left;
	if (right < base && array[right] > array[max])
		max = right;
	if (max != ele)
	{
		swap(&array[ele], &array[max]);
		print_array(array, size);
		heap_max(array, size, base, max);
	}
}

/**
 * heap_sort - this will use the heap sort algorithm to sort an array
 * @array: this is the array which needs to be sorted
 * @size: this is the arrays size
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (size <= 1)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heap_max(array, size, size, (size_t)i);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heap_max(array, size, (size_t)i, 0);
	}
}
