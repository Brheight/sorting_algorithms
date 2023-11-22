#include <stddef.h>
#include <stdio.h>

#include "sort.h"

void print_array(const int *array, size_t size);

void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

void print_array(const int *array, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void quick_sort(int *array, size_t size) {
    quick_sort_recursive(array, 0, size - 1, size);
}

void quick_sort_recursive(int *array, int low, int high, size_t size) {
    if (low < high) {
        int partition_index = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, partition_index - 1, size);
        quick_sort_recursive(array, partition_index + 1, high, size);
    }
}

int lomuto_partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return (i + 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
