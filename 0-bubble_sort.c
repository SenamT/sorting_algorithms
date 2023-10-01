#include "sort.h"

/**
 * bubble_sort - this will use the bubble algorithm to sort an array
 * @array: this is the array which needs to be sorted
 * @size: this will be the arrays size
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
