#include "InsertionSort.h"
#include <algorithm>
#include <ioStream>
using namespace std;

void InsertionSort::insertionSort(int array[], int size) {
    int index = 1;
    int currentValue;
    int prev;

    for (index; index < size; index++) {
        currentValue = array[index];
        prev = index - 1;

        while (prev >= 0 && array[prev] > currentValue) {
            array[prev + 1] = array[prev];
            prev -= 1;
        }
        array[prev + 1] = currentValue;
    }
}