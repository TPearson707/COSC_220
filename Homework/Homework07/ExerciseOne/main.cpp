/*
 * Description: main.cpp file for homework #7
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/24/2023
 * Date of Last Update: 10/24/2023
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include "NumberList.h"

using namespace std;
using namespace std::chrono;

template <typename T>
void bubbleSort(T * array, int size);

template <typename T>
void selectionSort(T * array, int size);

template <typename T>
void insertionSort(T * array, int size);

int main() {

    srand(time(0));

    int numData;

    NumberList numList;
    vector<int> vectList;

    cout << "Input the number of values to store: ";
    cin >> numData;

    int* intArr = new int[numData];

    int num;

    for (int i = 0; i < numData; i++) {

        num = rand() % 10 + 1;
        vectList.push_back(num);

    }

    auto start = high_resolution_clock::now();

    for (int i = 0; i < numData; i++)
        numList.insertNode(vectList.at(i));

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort with linked list: " << duration.count() / 1000000.0
    << " seconds" << endl;

    start = high_resolution_clock::now();

    for (int i = 0; i < numData; i++) {

        *(intArr + i) = vectList.at(i);

    }

    bubbleSort(intArr, numData);

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort the array with bubble sort " << duration.count() / 1000000.0
    << " seconds" << endl;


    start = high_resolution_clock::now();

    for (int i = 0; i < numData; i++) {

        *(intArr + i) = vectList.at(i);

    }

    insertionSort(intArr, numData);

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort the array with insertion sort " << duration.count() / 1000000.0
    << " seconds" << endl;

    start = high_resolution_clock::now();

    for (int i = 0; i < numData; i++) {

        *(intArr + i) = vectList.at(i);

    }

    selectionSort(intArr, numData);

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort the array with selection sort " << duration.count() / 1000000.0
    << " seconds" << endl;

    delete[] intArr;
    return 0;
}

template <typename T>
void bubbleSort(T * array, int size) {

	int maxElement;
	int index;

	for (maxElement = size - 1; maxElement > 0; maxElement--)
		for (index = 0; index < maxElement; index++)
			if (array[index] > array[index + 1])
				swap(array[index], array[index + 1]);

}

template <typename T>
void selectionSort(T * array, int size) {

	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++) {

		minIndex = start;
		minValue = array[start];

		for (int index = start + 1; index < size; index++) {

			if (array[index] < minValue) {

				minValue = array[index];
				minIndex = index;

			}

		}

		swap(array[minIndex], array[start]);

	}

}

template <typename T>
void insertionSort(T * array, int size) {

for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {

	int temp = array[itemsSorted];
	int loc = itemsSorted - 1;

		while (loc >= 0 && array[loc] > temp) {

			array[loc + 1] = array[loc];
			loc = loc - 1;

		}

	array[loc + 1] = temp;

	}

}
