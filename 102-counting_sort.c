#include "sort.h"


/**
 * counting_sort - algorithm for sortimg an array of integer
 * in ascending order 
 * @array: array of integer
 * @size: size of the integer 
 */
void counting_sort(int *array, size_t size)
{
    int max = array[0];
    int *count, *output;
    size_t i;
    int x;

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

    for (x = 1; x <= max; x++)
        count[x] += count[x - 1];

    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    for (x = size - 1; x >= 0; x--)
    {
        output[count[array[x]] - 1] = array[x];
        count[array[x]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
