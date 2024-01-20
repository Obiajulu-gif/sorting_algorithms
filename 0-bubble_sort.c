#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: array
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
for (i = 0; i < size - 1; i++)
{
for (j = 0; i < size - i - 1; i++)
{
if (array[j] > array[j + 1])
{
swap(&array[j], &array[j + 1]);
}
}

}
}

/**
 * swap - this take care of how i swap variable
 * @a: first variable to be swap
 * @b: second variable to be swap
 *
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
