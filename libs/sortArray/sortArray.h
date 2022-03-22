#ifndef O_N__SORTARRAY_H
#define O_N__SORTARRAY_H

#include <stdlib.h>
#include "D:\_Work\_GitHub\O(n)\libs\algorithms\algorithms.h"

/* Сортировка обменом массива a размера n */
void bubbleSort(int *a, size_t n);

/* Сортировка выбором массива a размера n */
void selectionSort(int *a, size_t n);

/* Сортировка вставками массива a размера n */
void insertionSort(int *a, size_t n);

/* Сортировка расческой массива a размера n */
void combSort(int *a, size_t n);

/* Сортировка Шелла массива a размера n */
void shellSort(int *a, size_t n);

/* Цифровая сортировка целочисленного массива a размера n */
void digitalSort(int *a, size_t n);

/* Возвращает количество операций сравнений и выполняет
 * Сортировку обменом массива a размера n */
long long bubbleSortNComp(int *a, size_t n);

/* Возвращает количество операций сравнений и выполняет
 * Сортировку выбором массива a размера n */
long long selectionSortNComp(int *a, size_t n);

/* Возвращает количество операций сравнений и выполняет
 * Сортировку вставками массива a размера n */
long long insertionSortNComp(int *a, size_t n);

/* Возвращает количество операций сравнений и выполняет
 * Сортировку расческой массива a размера n */
long long combSortNComp(int *a, size_t n);

/* Возвращает количество операций сравнений и выполняет
 * Сортировку Шелла массива a размера n */
long long shellSortNComp(int *a, size_t n);

/* Возвращает количество операций сравнений и выполняет
 * Цифровую сортировку целочисленного массива a размера n */
long long digitalSortNComp(int *a, size_t n);

#endif //O_N__SORTARRAY_H
