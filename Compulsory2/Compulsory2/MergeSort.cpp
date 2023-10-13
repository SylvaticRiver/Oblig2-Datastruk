#include "MergeSort.h"
#include <iostream>
using namespace std;

void merge(int array[], int left, int divisionpoint, int right) {

    int end1 = divisionpoint - left + 1;
    int end2 = right - divisionpoint;
    //I couldn't manage to create sub arrays with a variable amount of space so I had to just define it as a number big enough for the assignment
    int sub1[10000];
    int sub2[10000];

    //copies over to the sub arrays
    for (int i = 0; i < end1; i++) {
        sub1[i] = array[left + i];
    }
    for (int j = 0; j < end2; j++) {
        sub2[j] = array[divisionpoint + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < end1 && j < end2) {
        if (sub1[i] <= sub2[j]) {
            array[k] = sub1[i];
            i++;
        }
        else {
            array[k] = sub2[j];
            j++;
        }
        k++;
    }

    while (i < end1) {
        array[k] = sub1[i];
        i++;
        k++;
    }
    while (j < end2) {
        array[k] = sub2[j];
        j++;
        k++;
    }
}

void MergeSort::mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int divisionpoint = left + (right - left) / 2;

        mergeSort(arr, left, divisionpoint);
        mergeSort(arr, divisionpoint + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, divisionpoint, right);
    }
}


