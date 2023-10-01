#include "sort.h"
/**
 * mover - this will move all the contents of the array into the right and left subarrays
 * @array: this will be the source of the array
 * @left: this will be the left subarray
 * @right: this will be the right subarray
 * @l_size: this will be the left subarrays size
 * @r_size: this will be the right subarrays size
 * @low: this will be the low index
 * @middle: this will be the middle index
 */
void mover(int *array, int *left, int *right, int l_size, int r_size,
		int low, int middle)
{
	int i;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < l_size; i++)
	{
		left[i] = array[low + i];
		printf("%d", left[i]);
		if (i < l_size - 1)
			printf(", ");
		else
			printf("\n");
	}
	printf("[right]: ");
	for (i = 0; i < r_size; i++)
	{
		right[i] = array[middle + 1 + i];
		printf("%d", right[i]);
		if (i < r_size - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * merger - this will sort out and merge the left subarray with the right subarray
 * @array: this is the array which needs to be sorted
 * @low: this is the low index
 * @middle: this is the middle index
 * @high: this is the high index
 */
void merger(int *array, int low, int middle, int high)
{
	int i, j, k;
	int *left, *right, *subarr;
	int l_size = middle - low + 1;
	int r_size = high - middle;

	subarr = malloc(sizeof(int) * (high - low + 1));
	left = subarr;
	right = subarr + (middle - low + 1);
	mover(array, left, right, l_size, r_size, low, middle);
	for (i = 0, j = 0, k = low; i < l_size && j < r_size; k++)
	{
		if (left[i] <= right[j])
			array[k] = left[i], i++;
		else
			array[k] = right[j], j++;
	}


	while (i < l_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < r_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	for (i = low; i < k; i++)
	{
		printf("%d", array[i]);
		if (i < k - 1)
			printf(", ");
		else
			printf("\n");
	}
	free(subarr);
}

/**
 * splitter - this will recursively split the array
 * @array: this is the array which needs to be split
 * @low: this is the low index
 * @high: this is the high index
 */
void splitter(int *array, int low, int high)
{
	int middle;

	if (low >= high)
		return;
	middle = low + (high - low) / 2;
	if (middle - low >= high - middle)
		middle--;
	splitter(array, low, middle);
	splitter(array, middle + 1, high);
	merger(array, low, middle, high);
}

/**
 * merge_sort -  this will use the merge sort algorithm, 
 * to sort out an array of integers in ascending order
 * @array: this is the array which needs to be sorted
 * @size: this is the arrays size
 */
void merge_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	splitter(array, 0, size - 1);
}
