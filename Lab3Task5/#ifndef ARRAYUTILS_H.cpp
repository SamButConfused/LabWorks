#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include <stddef.h>

template <typename T>
void swapElements(T* arr, size_t index1, size_t index2) {
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

template <typename T>
size_t findElement(const T* arr, size_t size, const T& value) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return size; // Not found
}

template <typename T>
void swapAdjacentElements(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i += 2) {
        swapElements(arr, i, i + 1);
    }
}

#endif // ARRAYUTILS_H
