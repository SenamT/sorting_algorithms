#include "sort.h"

/**
 * shell_sort - this will use the shell sort algorithm to sort out the array
 * @array: this is the array which needs to be sorted
 * @size: this will be the arrays size
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (size <= 1)
		return;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; (j >= gap && array[j - gap] > tmp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
