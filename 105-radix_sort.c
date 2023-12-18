#include "sort.h"

/**
 * count_sort2 - do count sort for digits in specific place
 *
 * @arr: the array to be sorted
 * @place: the place of the digit form the right
 * @sz: size of array
 */
void count_sort2(int *arr, ssize_t place, size_t sz)
{
	ssize_t *count_arr = malloc(sizeof(ssize_t) * 10), *output_arr, i;

	if (!count_arr)
		exit;
	output_arr = malloc(sizeof(ssize_t) * sz);
	if (!output_arr)
	{
		free(count_arr);
		exit;
	}
	for (i = 0; i < 10; ++i)
		count_arr[i] = 0;
	for (i = 0; i < sz; ++i)
		count_arr[(arr[i] / place) % 10]++;
	for (i = 1; i < 10; ++i)
		count_arr[i] += count_arr[i - 1];
	for (i = sz - 1; i >= 0; --i)
	{
		output_arr[count_arr[(arr[i] / place) % 10] - 1] = arr[i];
		count_arr[(arr[i] / place) % 10]--;
	}
	for (i = 0; i < sz; ++i)
		arr[i] = output_arr[i];
	free(count_arr);
	free(output_arr);
}

/**
 * radix_sort - implementation of the radix algo
 *
 * @array: the array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	ssize_t i = 0, max = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	for (i = 1; max / i > 0; i *= 10)
	{
		count_sort2(array, i, size);
		print_array(array, size);
	}
}
