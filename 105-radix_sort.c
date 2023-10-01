#include "sort.h"

/**
 * count_sort - this will use the counting sort algorithm to sort the array
 * @array: this is the array which needs to be sorted
 * @size: this is the arrays size
 * @digit: this is the significant digits number
*/
void count_sort(int *array, size_t size, int digit)
{
	int i, *a = malloc(sizeof(int) * size), *count = malloc(sizeof(int) * 10);

	if (a == NULL || count == NULL)
		return;
	for (i = 0; i < 10; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{
		count[(array[i] / digit) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = (int)size - 1; i >= 0; i--)
	{
		a[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = a[i];
	}
	free(a);
	free(count);
}
/**
 * radix_sort - this will use the radix sort algorithm to sort the array
 * @array: this is the array which needs to be sorted
 * @size: this is the arrays size
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, i;
	size_t s;

	if (size <= 1 || array == NULL)
		return;
	for (s = 0; s < size; s++)
	{
		if (array[s] > max)
			max = array[s];
	}
	for (i = 1; (max / i) > 0; i *= 10)
	{
		count_sort(array, size, i);
		print_array(array, size);
	}
}
