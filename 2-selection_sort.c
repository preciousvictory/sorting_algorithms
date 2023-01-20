#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: the array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, n;
	int temp;

	for (i = 0; i < size; i++)
	{
		n = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[n])
			{
				n = j;
			}
		}

		if (n != i)
		{
			temp = array[n];
			array[n] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
