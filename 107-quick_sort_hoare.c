#include "sort.h"

/**
 * partitioner - this will use the lomutos method to partition the array 
 * @array: this is the array which needs to be sorted
 * @low: this is the low index
 * @high: this is the high index
 * @size: this will be the arrays size
 * Return: pivot of the index
 */
int partitioner(int *array, int low, int high, size_t size)
{
	int pivot = array[high], temp;
	int i = low - 1;
	int j = high + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * splitter - this is a recursive function
 * @array: this is the array which needs to be sorted
 * @low: this is the low index
 * @high: this is the high index
 * @size: this will be the arrays size
 */
void splitter(int *array, int low, int high, size_t size)
{
	int p_idx;

	if (low < high)
	{
		p_idx = partitionner(array, low, high, size);
		splitter(array, low, p_idx - 1, size);
		splitter(array, p_idx, high, size);
	}
}
/**
 * quick_sort_hoare - this will use the quick sort algorithm, 
 * to sort out the array of integers in ascending order
 * @array: this is the array which needs to be sorted
 * @size: this will be the arrays size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	splitter(array, 0, size - 1, size);
}
