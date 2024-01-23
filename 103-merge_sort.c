#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the top-down Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
int *temp;

if (array == NULL || size < 2)
return;

/* Allocate temporary array for merging */
temp = malloc(size * sizeof(int));
if (temp == NULL)
return;

/* Call the recursive merge sort function */
recursive_merge_sort(array, 0, size - 1, temp);

/* Free the temporary array */
free(temp);
}

/**
 * recursive_merge_sort - Recursively sorts an array using Merge Sort.
 * @array: The array to be sorted.
 * @left: The left index of the current sub-array.
 * @right: The right index of the current sub-array.
 * @temp: Temporary array for merging.
 */
void recursive_merge_sort(int *array, int left, int right, int *temp)
{
if (left < right)
{
int mid = left + (right - left) / 2;

/* Recursively sort the left and right halves */
recursive_merge_sort(array, left, mid, temp);
recursive_merge_sort(array, mid + 1, right, temp);

/* Merge the sorted halves */
merge(array, left, mid, right, temp);
}
}

/**
 * merge - Merges two sub-arrays into a single sorted array.
 * @array: The array containing the two sub-arrays.
 * @left: The left index of the first sub-array.
 * @mid: The right index of the first sub-array
 *  and the left index of the second sub-array.
 * @right: The right index of the second sub-array.
 * @temp: Temporary array for merging.
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
int i = left, j = mid + 1, k = 0;

printf("Merging...\n[left]: ");
print_array(array + left, mid - left + 1);
printf("[right]: ");
print_array(array + mid + 1, right - mid);

while (i <= mid && j <= right)
{
if (array[i] <= array[j])
temp[k++] = array[i++];
else
temp[k++] = array[j++];
}

while (i <= mid)
temp[k++] = array[i++];

while (j <= right)
temp[k++] = array[j++];

for (i = 0; i < k; i++)
array[left + i] = temp[i];

printf("[Done]: ");
print_array(array + left, right - left + 1);
}
