#include "sort.h"

/**
 * selection_sort - selection sorting algorthim using c
 * @array: the array used to be sorted out
 * @size: the size of the array
 * Return: the return is void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp, swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				swap = 1;
			}
		}
		if (swap)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
