#include "BubbleSort.h"
#include <iostream>
#include <array>
using namespace std;

 void BubbleSort::bubbleSort(int array[], int size)
 {
     //the base case so it doesn't infinitely work itself to exhaustion
     //returns if the array size is 1
     if (size == 1) {
         return;
     }
     int iterations = 0;
     for (int i = 0; i < size - 1; i++)
         if (array[i] > array[i + 1]) {
             swap(array[i], array[i + 1]);
             //adds 1 to iteration to trigger another call of the function
             iterations++;
         }
     //returns if the amount of iterations is 0 which means the array is completely sorted
     if (iterations == 0) {
         return;
         }
     bubbleSort(array, size - 1);
 }
