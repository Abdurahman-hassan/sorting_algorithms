#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* Bubble sort algorithm */
	for (i = 0; i < size - 1; i++)
	{
		/* Last i elements are already in place */
		for (j = 1; j < size - i; j++)
		{
			/* Swap if the element found is */
			/* greater than the next element */
			if (array[j - 1] > array[j])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
