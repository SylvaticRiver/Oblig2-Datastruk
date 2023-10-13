#include "QuickSort.h"
#include <algorithm>
#include <ioStream>
using namespace std;

void QuickSort::insertionSort(int array[], int size) {
    int index = 1;
    int value;
    int currentPos;

    for (index; index < size; index++) {
        value = array[index];
        currentPos = index - 1;

        while (currentPos >= 0 && array[currentPos] > value) {
            array[currentPos + 1] = array[currentPos];
            currentPos -= 1;
        }
        array[currentPos + 1] = value;
    }
}
