#include "sort.h"

/**
 * counting_sort - implementation of counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *output_arr, max = 0, i = 0, j = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	/* create an array of size max + 1 and initialize it with 0 */
	count_arr = malloc(sizeof(int) * (max + 1));
	if (!count_arr)
		return;

	/* count the number of times each element appears in the array */
	for (i = 0; i < (int)size; i++)
		count_arr[array[i]]++;

	/* modify the count array so that each element stores the sum of previous */
	for (i = 1; i <= max; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, max + 1);
	/* create the output array */
	output_arr = malloc(sizeof(int) * size);
	if (!output_arr)
	{
		free(count_arr);
		return;
	}
	/* build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	/* copy the output array to the original array */
	for (j = 0; j < (int)size; j++)
		array[j] = output_arr[j];
	free(count_arr);
	free(output_arr);
}
