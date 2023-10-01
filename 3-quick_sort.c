#include "sort.h"

/**
 * swap - this will swap the values within x with the values within y
 * @x: this is the value which needs to be swapped
 * @y: this is also the value which needs to be swapped
*/
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * split - this will break the array into two parts
 * @array: this is the array which needs to be split
 * @low: this will be the low index
 * @high: this will be the high index
 * @size: this will be the arrays size
 * Return: this will be the pivots index
*/
int split(int *array, int low, int high, size_t size)
{
	int index = array[high], i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < index && array[++i] != array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[++i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * recursion - this will use recursion to sort out the array
 * @array: this is the array which needs to be sorted
 * @low: this will be the low index
 * @high: this will be the high index
 * @size: this will be the arrays size
*/
void recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int index = split(array, low, high, size);

		recursion(array, low, index - 1, size);
		recursion(array, index + 1, high, size);
	}
}

/**
 * quick_sort - this will use the quick sort algorithm to sort out an array
 * @array: this will be the array which needs to be sorted
 * @size: this will be the arrays size
*/
void quick_sort(int *array, size_t size)
{
	recursion(array, 0, (int)size - 1, size);
}
