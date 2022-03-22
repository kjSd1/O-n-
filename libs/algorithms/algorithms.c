#include "algorithms.h"

void outputArray_(int *a, size_t n) {
    for (size_t index = 0; index < n; index++)
        printf("%d ", a[index]);
    printf("\n");
}

bool isOrdered(int *a, size_t n) {
    for (size_t index = 1; index < n; index++)
        if (a[index] < a[index - 1])
            return false;
    return true;
}

void generateRandomArray(int *a, size_t n) {
    srand(clock());
    for (size_t index = 0; index < n; index++)
        a[index] = 1000 - rand() % 1000;
}

void generateOrderedArray(int *a, size_t n) {
    srand(clock());
    for (size_t index = 0; index < n; index++)
        a[index] = 1000 - rand() % 1000;
    qsort(a, n, sizeof(int), compare_ints);
}

void generateOrderedBackwards(int *a, size_t n) {
    srand(clock());
    for (size_t index = 0; index < n; index++)
        a[index] = 1000 - rand() % 1000;
    qsort(a, n, sizeof(int), compare_intsReverse);
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int compare_intsReverse(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return 1;
    if (arg1 > arg2) return -1;
    return 0;
}

void swapInts(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void assertArray(int *a, size_t n, int line, const char* name) {
    if(isOrdered(a, n))
        fprintf(stderr, "%s on line %d \n\t result test: OK\n", name, line);
    else
        fprintf(stderr, "%s on line %d \n\t result test: Error\n", name, line);
}

void copyArray_(const int *data, int *beginCopy, size_t n) {
    for (size_t index = 0; index < n; index++)
        beginCopy[index] = data[index];
}
