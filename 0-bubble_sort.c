#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int swapped = 1;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1 && swapped; i++)
{
swapped = 0;
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
swap(&array[j], &array[j + 1]);
swapped = 1;
print_array(array, size);
}
}
}
}

/**
 * swap - Swaps two integers
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
