#include "sort.h"

/**
 * merge - merge two subarrays
 * This function merges two subarrays of @array.
 * @array: array to sort
 * @size: size of array
 * @mid: middle index
 * @tmp: temp array
 */
void merge(int *array, size_t size, int mid, int *tmp)
{
	int i = 0, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	/* merge two arrays into tmp[] */
	while (i < mid && j < (int)size)
	{
		if (array[i] < array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	/* Copy data to temp arrays L[] and R[] */
	/* Copy the remaining elements of left subarray */
	while (i < mid)
		tmp[k++] = array[i++];

	/* Copy the remaining elements of right subarray */
	while (j < (int)size)
		tmp[k++] = array[j++];

	/* Copy the merged elements back to array[] */
	for (i = 0; i < (int)size; i++)
		array[i] = tmp[i];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort_rec - merge sort recursive function
 * This function sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 * @tmp: temp array
 */
void merge_sort_rec(int *array, size_t size, int *tmp)
{
	int mid;

	if (size < 2)
		return;
	mid = size / 2;
	merge_sort_rec(array, mid, tmp);
	merge_sort_rec(array + mid,  size - mid, tmp);
	merge(array, size, mid, tmp);
}

/**
 * merge_sort - merge sort function
 * This function sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	merge_sort_rec(array, size, tmp);
	free(tmp);
}
