#include "sort.h"


/**
 * shell_sort- the is a function that sort an array of integer
 * in ascending order using the shell sort algorithm
 * @array: a list to be sorted
 * @size: the size of the list
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;
int temp;

if (array == NULL || size < 2)
return;

gap = 1;
while (gap < size / 3)
gap = gap * 3 + 1;

while (gap > 0)
{
for (i = gap; i < size; i++)
{
temp = array[i];
j = i;

while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = temp;
}
print_array(array, size);

gap /= 3;
}

}
