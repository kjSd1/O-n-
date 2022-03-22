#include "sortArray.h"

void bubbleSort(int *a, size_t n) {
    for (size_t index = n; index > 0; index--)
        for (size_t indexCheck = 1; indexCheck < index; indexCheck++)
            if (a[indexCheck - 1] > a[indexCheck])
                swapInts(&a[indexCheck], &a[indexCheck - 1]);
}

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

void combSort(int *a, size_t n) {
    double factor = 1.2473309;
    for (int step = n - 1; step >= 1; step /= factor)
        for (int index = 0, indexStep = step; indexStep < n; index++, indexStep++)
            if (a[index] > a[indexStep])
                swapInts(&a[index], &a[indexStep]);
    size_t indexLeft = 0;
    while (indexLeft + 1 < n) {
        if (a[indexLeft] > a[indexLeft + 1]) {
            swapInts(&a[indexLeft + 1], &a[indexLeft]);
            indexLeft -= indexLeft != 0;
        } else
            indexLeft++;
    }
}

void shellSort(int *a, size_t n) {
    for (int step = n / 2; step > 0; step /= 2) {
        for (int indexRight = step; indexRight < n; indexRight++) {
            int indexLeft = indexRight - step;
            if (a[indexLeft] > a[indexRight]) {
                swapInts(&a[indexLeft], &a[indexRight]);
                for (int indexRightSwap = indexLeft; indexRightSwap - step >= 0 && a[indexRightSwap - step] > a[indexRightSwap]; indexRightSwap -= step)
                    swapInts(&a[indexRightSwap], &a[indexRightSwap - step]);
            }
        }
    }
}

void digitalSort(int *a, size_t n) {
    size_t *thisDigitTotal = (size_t *)calloc(256, sizeof(size_t));
    int *copyArray = (int *)calloc(n, sizeof(int));

    int checkByte = 255;
    for (size_t indexBite = 0; indexBite < 4; indexBite++, checkByte <<= 8) {
        copyArray_(a, copyArray, n);

        for (size_t index = 0; index < 256; index++)
            thisDigitTotal[index] = 0;

        for (size_t index = 0; index < n; index++)
            thisDigitTotal[(a[index] & checkByte) >> 8 * indexBite]++;

        size_t thisStartPos = 0;
        for (size_t index = 0; index < 256; index++) {
            if (thisDigitTotal[index] > 0) {
                size_t buffer = thisDigitTotal[index];
                thisDigitTotal[index] = thisStartPos;
                thisStartPos += buffer;
            }
        }

        for (size_t index = 0; index < n; index++)
            a[thisDigitTotal[(copyArray[index] & checkByte) >> 8 * indexBite]++] = copyArray[index];
    }
    free(copyArray);
    free(thisDigitTotal);
}