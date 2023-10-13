#include "Compulsory2SortingAlgorithms.h"
#include <IOstream>
#include <chrono>
#include "InsertionSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
using namespace std::chrono;
using namespace std;

bool active = true;

InsertionSort Isort;
MergeSort MSort;
BubbleSort BSort;

void displayArray(int i[], int size) {
	for (int j = 0; j < size; j++) {
		cout << i[j] << " ";
	}
}

void perform(int i[], int type, int mid, int size) {
	//measures current time before operation
	auto start = high_resolution_clock::now();
	switch (type) {
	case 1:
		Isort.insertionSort(i, size);
		break;
	case 2:
		MSort.mergeSort(i, 0, size - 1);
		break;
	case 3:
		BSort.bubbleSort(i, size);
		break;
	default:
		active = false;
		cout << "invalid selection" << endl;
	}
	if (active) {
		//measures current time after operation
		auto finished = high_resolution_clock::now();
		//calculates the passage of time in milliseconds
		auto speed = duration_cast<milliseconds>(finished - start);
		if (size <= 1000) {
			displayArray(i, size);
		}
		cout << "" << endl;

		cout << speed.count();
		cout << " Milliseconds" << endl;
	}
}

void createRandomisedArray(int arr[], int size) {
	//randomises the contents of a 'size' sized array with numbers from 0 to 100
	for (int l = 0; l < size; l++) {
		arr[l] = { rand() % 100 };
	}
}

int main() {
	while (active) {
		//couldn't make an array of a variable size so just change this number to what you want to use
		const int Asize = 10;
		int mid = 6;
		int array[Asize];

		cout << "your array is: ";
		createRandomisedArray(array, Asize);

		int size = sizeof(array) / sizeof(array[0]);
		//added this so it doesn't spend my entire life trying to display 10k numbers. feel free to remove the if statement if you want
		if (Asize <= 1000) {
			displayArray(array, size);
		}

		cout << "" << endl;
		int type;
		cout << "1 for InsertionSort, 2 for MergeSort, 3 for BubbleSort" << endl;
		cin >> type;
		perform(array, type, mid, size);
	}
	return 1;
}