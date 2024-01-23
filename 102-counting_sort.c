#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                  using sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
int i, j, max;
size_t i = 0;
int *count;

if (array == NULL || size < 2)
return;

max = array[0];
for (size_t i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

count = malloc((max + 1) * sizeof(int));
if (count == NULL)
return;

for (i = 0; i <= max; i++)
count[i] = 0;

for (size_t i = 0; i < size; i++)
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
