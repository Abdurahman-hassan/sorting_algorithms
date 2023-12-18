#include "sort.h"
#include "3-quick_sort.c"

/**
 * heapify - heapifies a subtree
 * @array: array to be sorted
 * @size: size of the array
 * @i: index of the subtree
 * @size2: size of the array
 */
void heapify(int *array, size_t size, int i, size_t size2)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	/*checking if left child is larger than root*/
	if (l < (int)size && array[l] > array[largest])
		largest = l;

	/*checking if right child is larger than largest so far*/
	if (r < (int)size && array[r] > array[largest])
		largest = r;

	/* If largest is not root */
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size2);
		heapify(array, size, largest, size2);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * building the heap we only need to heapify the first half of the array
 * because the rest are leaves and don't need to be heapified
 *
 * the last parent node is at index (size/2 - 1)
 * so we start at that index and go backwards, to the root node at index 0
 * and heapify each subtree to build the heap, then we swap the root node,
 * which is the largest element, with the last element in the array
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = (int)size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
