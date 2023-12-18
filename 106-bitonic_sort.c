#include "sort.h"

/**
 * print_stage - print the current stage of the array
 *
 * @array: the array to be printed
 * @size: the size of the array
 * @full_size: the full size of the array
 * @up: 1 if the array is sorted in ascending order, 0 otherwise
 */
void print_stage(int *array, size_t size,
		size_t full_size, int up)
{
	printf("Merging [%lu/%lu] (%s):\n",
			size, full_size, up ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_merge - merge 2 arrays
 *
 * @array: the array to be sorted
 * @size: size of the array
 * @up: 1 if the array is sorted in ascending order, 0 otherwise
 */
void bitonic_merge(int *array, size_t size, int up)
{
	int i, tmp;

	if (size > 1)
	{
		for (i = 0; i < (int)size / 2; i++)
		{
			if (up == (array[i] > array[i + (int)size / 2]))
			{
				tmp = array[i];
				array[i] = array[i + (int)size / 2];
				array[i + (int)size / 2] = tmp;
			}
		}
		bitonic_merge(array, size / 2, up);
		bitonic_merge(array + size / 2, size / 2, up);
	}
}

/**
 * bitonic_sort_rec - recursive function for bitonic sort
 *
 * @array: the array to be sorted
 * @size: size of the array
 * @full_size: the full size of the array
 * @up: 1 if the array is sorted in ascending order, 0 otherwise
 */
void bitonic_sort_rec(int *array, size_t size, size_t full_size, int up)
{
	if (size > 1)
	{
		print_stage(array, size, full_size, up);

		/* Sort first half in ascending order */
		bitonic_sort_rec(array, size / 2, full_size, 1);

		/* Sort second half in descending order */
		bitonic_sort_rec(array + size / 2, size / 2, full_size, 0);

		/* Merge whole sequence */
		bitonic_merge(array, size, up);

		printf("Result [%lu/%lu] (%s):\n", size, full_size, up ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;

	if (!array || size < 2)
		return;

	bitonic_sort_rec(array, size, size, up);
}
