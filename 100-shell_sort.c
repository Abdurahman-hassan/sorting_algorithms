#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Shell sort algorithm */
	while (gap > 0)
	{
		/*moving (advance)*/
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j > gap - 1 && array[j - gap] >= tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		/*decrease the gap to be 0*/
		/*in order to terminat the program*/
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
