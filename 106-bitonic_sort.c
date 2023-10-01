#include "sort.h"

/**
 * merger - this will merge the different parts
 * @array: this is the array which needs to be sorted
 * @low: this is the low index
 * @n: this will be the number of components
 * @dir: this will be the direction of the merge
 */
void merger(int *array, int low, int n, int dir)
{
	int mid, i, tmp;

	if (n <= 1)
		return;
	mid = n / 2;
	for (i = low; i < low + mid; i++)
	{
		if (dir == (array[i] > array[i + mid]))
		{
			tmp = array[i];
			array[i] = array[i + mid];
			array[i + mid] = tmp;
		}
	}
	merger(array, low, mid, dir);
	merger(array, low + mid, mid, dir);
}

/**
 * sorter - this will split and sort an array
 * @array: this is the array which needs to be sorted
 * @low: this is the low index
 * @n: this will be the number of components
 * @dir: this will be the direction of the merge
 * @size: this will be the arrays size
 */
void sorter(int *array, int low, int n, int dir, size_t size)
{
	int mid;
	char *direction;

	if (n <= 1)
		return;

	if (dir > 0)
		direction = "UP";
	else
		direction = "DOWN";
	printf("Merging [%d/%ld] (%s):\n", n, size, direction);
	print_array(&array[low], n);
	mid = n / 2;
	sorter(array, low, mid, 1, size);
	sorter(array, low + mid, mid, 0, size);
	merger(array, low, n, dir);
	printf("Result [%d/%ld] (%s):\n", n, size, direction);
	print_array(&array[low], n);
}

/**
 * bitonic_sort - this will use the bitonic sort algorithm, 
 * to sort out an array of integers in ascending order
 * @array: this is the array which needs to be sorted
 * @size: this is the arrays size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	sorter(array, 0, size, 1, size);
}
