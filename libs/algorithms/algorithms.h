#ifndef O_N__ALGORITHMS_H
#define O_N__ALGORITHMS_H

#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0]);

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode; \
    clock_t end_time = clock(); \
    clock_t sort_time = end_time - start_time; \
    time = (double)sort_time / CLOCKS_PER_SEC; \
}

#define TEST_SORT(array, size) assertArray(array, size, __LINE__, __FUNCTION__)

/* Выводит массив a размера n */
void outputArray_(int *a, size_t n);

/* Возвращает 'истина' - если массив a размера n отсортирован по не убыванию,
 * иначе - 'ложь' */
bool isOrdered(int *a, size_t n);

/* Генерирует рандомный массив по адресу a размера n */
void generateRandomArray(int *a, size_t n);

/* Генерирует по не убыванию массив по адресу a размера n */
void generateOrderedArray(int *a, size_t n);

/* Генерирует по не возрастанию массив по адресу a размера n */
void generateOrderedBackwards(int *a, size_t n);

/* Функция-компоратор для сортировки целочисленного массива по не убыванию */
int compare_ints(const void *a, const void *b);

/* Функция-компоратор для сортировки целочисленного массива по не возрастанию */
int compare_intsReverse(const void *a, const void *b);

/* Обмен значений целочисленных переменных по адресам a и b */
void swapInts(int *a, int *b);

/* Проверка на упорядоченность массива a размера n.
 * Вывод в консоль названия функции и строки вызова проверки массива, а также сообщение с результатом */
void assertArray(int *a, size_t n, int line, const char *name);

/* Копирует массив из адреса data размера n по адресу beginCopy */
void copyArray_(const int *data, int *beginCopy, size_t n);

#endif //O_N__ALGORITHMS_H
