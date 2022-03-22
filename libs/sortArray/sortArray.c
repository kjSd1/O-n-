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

unsigned long long bubbleSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t index = n; ++nComps && index > 0; index--)
        for (size_t indexCheck = 1; ++nComps && indexCheck < index; indexCheck++)
            if (++nComps && a[indexCheck - 1] > a[indexCheck])
                swapInts(&a[indexCheck], &a[indexCheck - 1]);
    return nComps;
}

unsigned long long selectionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t index = 0; ++nComps && index < n; index++) {
        size_t minIndex = index;
        for (size_t indexCheck = index + 1; ++nComps && indexCheck < n; indexCheck++)
            if (++nComps && a[minIndex] > a[indexCheck])
                minIndex = indexCheck;
        swapInts(&a[minIndex], &a[index]);
    }
    return nComps;
}

unsigned long long insertionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t index = 1; ++nComps && index < n; index++)
        for (size_t indexCheck = index; ++nComps && indexCheck > 0 && ++nComps && a[indexCheck] < a[indexCheck - 1]; indexCheck--)
            swapInts(&a[indexCheck], &a[indexCheck - 1]);
    return nComps;
}

unsigned long long combSortNComp(int *a, size_t n) {
    long long nComps = 0;
    double factor = 1.2473309;
    for (int step = n - 1; ++nComps && step >= 1; step /= factor)
        for (int index = 0, indexStep = step; ++nComps && indexStep < n; index++, indexStep++)
            if (nComps++ && a[index] > a[indexStep])
                swapInts(&a[index], &a[indexStep]);
    size_t indexLeft = 0;
    while (indexLeft + 1 < n) {
        if (++nComps && a[indexLeft] > a[indexLeft + 1]) {
            swapInts(&a[indexLeft + 1], &a[indexLeft]);
            indexLeft -= indexLeft != 0;
            ++nComps;
        } else
            indexLeft++;
    }
    return nComps;
}

unsigned long long shellSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (int step = n / 2; ++nComps && step > 0; step /= 2) {
        for (int indexRight = step; nComps++ && indexRight < n; indexRight++) {
            int indexLeft = indexRight - step;
            if (nComps++ && a[indexLeft] > a[indexRight]) {
                swapInts(&a[indexLeft], &a[indexRight]);
                for (int indexRightSwap = indexLeft; nComps++ && indexRightSwap - step >= 0 && nComps++ && a[indexRightSwap - step] > a[indexRightSwap]; indexRightSwap -= step)
                    swapInts(&a[indexRightSwap], &a[indexRightSwap - step]);
            }
        }
    }
    return nComps;
}

unsigned long long digitalSortNComp(int *a, size_t n) {
    long long nComps = 0;
    size_t *thisDigitTotal = (size_t *)calloc(256, sizeof(size_t));
    int *copyArray = (int *)calloc(n, sizeof(int));

    int checkByte = 255;
    for (size_t indexBite = 0; ++nComps && indexBite < 4; indexBite++, checkByte <<= 8) {
        copyArray_(a, copyArray, n);

        for (size_t index = 0; nComps++ && index < 256; index++)
            thisDigitTotal[index] = 0;

        for (size_t index = 0; nComps++ && index < n; index++)
            thisDigitTotal[(a[index] & checkByte) >> 8 * indexBite]++;

        size_t thisStartPos = 0;
        for (size_t index = 0; nComps++ && index < 256; index++) {
            if (nComps++ && thisDigitTotal[index] > 0) {
                size_t buffer = thisDigitTotal[index];
                thisDigitTotal[index] = thisStartPos;
                thisStartPos += buffer;
            }
        }

        for (size_t index = 0; nComps++ && index < n; index++)
            a[thisDigitTotal[(copyArray[index] & checkByte) >> 8 * indexBite]++] = copyArray[index];
    }
    free(copyArray);
    free(thisDigitTotal);
    return nComps;
}