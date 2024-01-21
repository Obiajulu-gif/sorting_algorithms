#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using Quick Sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @low: the lower index of the partition
 * @high: the higher index of the partition
 * @size: the size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = lomuto_partition(array, low, high, size);
quicksort(array, low, pivot_index - 1, size);
quicksort(array, pivot_index + 1, high, size);
}
}
/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: the array to be sorted
 * @low: the lower index of the partition
 * @high: the higher index of the partition
 * @size: the size of the array
 * Return: the index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j, temp;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;

if (i != j)
print_array(array, size);

}
}
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;

if (i + 1 != high)
print_array(array, size);

return (i + 1);
}
