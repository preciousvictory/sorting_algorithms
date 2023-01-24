#include "sort.h"
/**
 * shell_sort - a function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		/* Do a gapped insertion sort for every elements in gaps */
		for (i = gap; i < size; i++)
		{
			/* save a[i] in temp and make a hole at position i */
			temp = array[i];
			/**
			 * shift earlier gap-sorted elements up until the correct
			 * location for a[i] is found
			 */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			/* put temp (the original a[i]) in its correct location */
			array[j] = temp;
		}
		print_array(array, size);
	}
}
