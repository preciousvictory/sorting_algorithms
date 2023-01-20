#include "sort.h"

/**
 * quick_sort -  a function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t i, j;
	int pivot = array[size - 1], temp;

	/**
	 * Lomuto partition scheme
	 * this scheme chooses as the pivot the last element in the array.
	 */
	i = -1;
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_index(i, j, array);
		}
	}
	/**
	 * i after the loop end becomes the pivot correct position
	 * swapping arr[i] and pivot to pivot in it correct position
	 */
	i++;
	swap(i, size - 1, array);

	quick_sort(array[:i], i);
	quick_sort(array[(i + 1):], size - 1 - i);
}

/**
 * swap_index - swap to index value in an arry
 * @i: first index
 * @j: second index
 * @array: array to be swapped
 */
void swap_index(size_t i, size_t j, int *array)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
