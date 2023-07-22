#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);


void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
