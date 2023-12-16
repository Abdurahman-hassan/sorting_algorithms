#include "sort.h"

/**
 * swap - swap 2 elements
 *
 * @f: 1st element
 * @s: 2nd element
 */
void swap(int *f, int *s)
{
	int tmp = *s;

	*s = *f;
	*f = tmp;
}

/**
 * partition - swap 2 elements
 *
 * @arr: the array to be sorted
 * @start: the first element of the partition
 * @end: the last element of the partition
 * @sz: size of array
 *
 * Return: the index of the pivot
 */
ssize_t partition(int *arr, ssize_t start, ssize_t end, size_t sz)
{
	ssize_t pivot = end, first_swap = start - 1;

	for (; start < end; ++start)
	{
		if (arr[start] < arr[end])
		{
			swap(&arr[start], &arr[++first_swap]);
			if (start != first_swap)
				print_array(arr, sz);
		}
	}
	if (end != (first_swap + 1))
	{
		swap(&arr[start], &arr[first_swap + 1]);
		print_array(arr, sz);
	}
	pivot = first_swap + 1;
	return (pivot);
}

/**
 * real_quick - implementation of the quick algo
 *
 * @arr: the array to be sorted
 * @lo: the first element of the partition
 * @hi: the last element of the partition
 * @sz: size of array
 */
void real_quick(int *arr, ssize_t lo, ssize_t hi, size_t sz)
{
	ssize_t pivot;

	if (lo >= hi)
		return;
	pivot = partition(arr, lo, hi, sz);
	real_quick(arr, lo, pivot - 1, sz);
	real_quick(arr, pivot + 1, hi, sz);
}

/**
 * quick_sort - implementation of the quick algo
 *
 * @arr: the array to be sorted
 * @size: size of array
 */
void quick_sort(int *arr, size_t size)
{
	ssize_t lo = 0, hi = (ssize_t)size - 1;

	if (!arr || !size || size < 2)
		return;
	real_quick(arr, lo, hi, size);
}
