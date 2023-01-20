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
	size_t l = 0;

	if (array == NULL || size <= 1)
		return;

	q_sort(array, size, l, size - 1);
}

/**
 * q_sort - sort array using quick sort
 * @array: the array to be sorted
 * @low: lower point
 * @high: pivot
 */
void q_sort(int *array, size_t size, size_t low, size_t high)
{
	int pivot;

	if (low >= high)
		return;
	
	if (low < high)
	{
		pivot = partition(array, size, low, high);
		/**
		 * sorts to the left of the pivot
		 */
		q_sort(array, size, low, pivot - 1);
	
		/**
		 * sorts to the right of the pivot
		 */
		q_sort(array, size, pivot + 1, high);
	}
}

size_t partition(int *array, size_t size, size_t low, size_t high)
{
	size_t i, j;
	int pivot = array[high], temp;

	/**
	 * Lomuto partition scheme
	 * this scheme chooses as the pivot the last element in the array.
	 */
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	
	/**
	 * i after the loop end becomes the pivot correct position
	 * swapping arr[i] and pivot to pivot in it correct position
	 */
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap_index - swap to index value in an arry
 * @i: first index
 * @j: second index
 * @array: array to be swapped
 */
void swap_index(int i, int j)
{
	int temp;

	temp = i;
	i = j;
	j = temp;
}
