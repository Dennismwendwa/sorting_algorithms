#include "sort.h"
/**
 * shell_sort - 
 * @array: list of interger
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t j, gap, n = 0, i = 0;

	while (n < size - 1 / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		int insert;
		for (gap = n; gap < size - 1; gap++)
		{
			insert = array[gap];
			j = gap;

			while (j > n - 1 && array[j - n] >= insert)
			{
				array[j] = array[j - n];
				j = j - n;
			}
			array[j] = insert;
		}
		n = (n - 1) / 3;
		print_array(array, size);
		i++;
	}
/*
	for (gap = size / 2; gap >= 1; gap /= 2)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] < array[i])
				{
					tmp = array [i];
					array[i] = array[i + gap];
					array[i + gap] = tmp;

					print_array(array, size);
				}
				else
					break;
			}
		}
	}*/
}
