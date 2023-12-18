#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* Selection sort algorithm */
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		/* Find the minimum element in unsorted array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		/* Swap the found minimum element with the first element */
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
