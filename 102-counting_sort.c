#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 Counting Sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max = array[0];
    size_t i = 0;
    int *count;
    int x, j;
    if (array == NULL || size < 2)
        return;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (x = 0; x <= max; x++)
        count[x] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;

    print_array(count, max + 1);

    for (j = 0; j <= max; j++)
    {
        while (count[j] > 0)
        {
            array[i++] = j;
            count[j]--;
        }
    }

    free(count);
}
