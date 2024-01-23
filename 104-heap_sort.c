#include "sort.h"


/**
 * heap_sort - Sort an integer in ascending order using
 *              Heap Sort algorithm.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void heap_sort(int *array, size_t size)
{
int i;
if (array == NULL || size < 2)
return;

build_heap(array, size);

for (i = size - 1; i > 0; i--)
{
swap(&array[0], &array[i]);

heapify(array, i, 0);
}
}

/**
 * build_heap - Build a max heap from the array.
 * @array: the array to be transformed into a max heap.
 * @size: the size of the array.
 */
void build_heap(int *array, size_t size)
{
int i;
for (i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i);
}

/**
 * heapify - Maintains the heap property by recursively
 * adjusting elements.
 * @array: the array to be heapified.
 * @size: the size of the array.
 * @i: the index of the current root.
 */
void heapify(int *array, size_t size, int i)
{
int largest = i;
size_t left = 2 * i + 1;
size_t right = 2 * i + 2;

if (left < size && array[left] > array[largest])
largest = left;

if (right < size && array[right] > array[largest])
largest = right;

if (largest != i)
{
swap(&array[i], &array[largest]);
heapify(array, size, largest);
}
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{

int temp = *a;
*a = *b;
*b = temp;
}
