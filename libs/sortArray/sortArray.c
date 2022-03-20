#include "sortArray.h"

void selectionSort(int *a, size_t n) {
    for (size_t index = 0; index < n; index++) {
        size_t minIndex = index;
        for (size_t indexCheck = index + 1; indexCheck < n; indexCheck++)
            if (a[minIndex] > a[indexCheck])
                minIndex = indexCheck;
        swapInts(&a[minIndex], &a[index]);
    }
}

void insertionSort(int *a, size_t n) {
    for (size_t index = 1; index < n; index++)
        for (size_t indexCheck = index; indexCheck > 0 && a[indexCheck] < a[indexCheck - 1]; indexCheck--)
            swapInts(&a[indexCheck], &a[indexCheck - 1]);
}