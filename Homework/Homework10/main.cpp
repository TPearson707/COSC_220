#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include "BinaryTree.h"


using namespace std;
using namespace std::chrono;

template<class T>
void merge(T A[], T Temp[], int startA, int startB, int end);

template<class T>
void mergeSort(T A[], T Temp[], int start, int end);

template<class T>
void mergeSort(T A[], int size);

template<class T>
void quickSort(T A[], int left, int right);

template<class T>
void quickSort(T A[], int size);

template <typename T>
void treeSort(T array[], int size);

template <typename T>
void populateArray(T * array, int size);

template <typename T>
void clearArray(T * array, int size);

int main() {

    srand(time(0));
    BinaryTree<int> tree;
    int size = 500000;

    int* array = new int[size];

    populateArray(array, size);

    auto start = high_resolution_clock::now();

    treeSort(array, size);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort with tree sort: " << duration.count() / 1000000.0
    << " seconds" << endl;

    clearArray(array, size);

    populateArray(array, size);

    start = high_resolution_clock::now();

    mergeSort(array, size);

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort with merge sort: " << duration.count() / 1000000.0
    << " seconds" << endl;

    clearArray(array, size);

    populateArray(array, size);

    start = high_resolution_clock::now();

    quickSort(array, size);

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort with quick sort: " << duration.count() / 1000000.0
    << " seconds" << endl;

    delete[] array;
    return 0;
}

template<class T>
void merge(T A[], T Temp[], int startA, int startB, int end) {
	int aptr = startA;
	int bptr = startB;
	int i = startA;

	while (aptr < startB && bptr <= end)
		if (A[aptr] < A[bptr])
			Temp[i++] = A[aptr++];
		else
			Temp[i++] = A[bptr++];

	while (aptr < startB)
		Temp[i++] = A[aptr++];

	while (bptr <= end)
		Temp[i++] = A[bptr++];

	for (i = startA; i <= end; i++)
		A[i] = Temp[i];
}

template<class T>
void mergeSort(T A[], T Temp[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(A, Temp, start, mid);
		mergeSort(A, Temp, mid + 1, end);
		merge(A, Temp, start, mid + 1, end);
	}
}

template<class T>
void mergeSort(T A[], int size) {
	T Temp[size];
	mergeSort(A, Temp, 0, size - 1);
//     delete [] Temp;
}

///////////////////////////////////////////////////////////

template<class T>
void quickSort(T A[], int left, int right) {
	int i = left;
	int j = right;
	int mid = (left + right) / 2;

	T pivot = A[mid];

	while (i <= j) {
		while (A[i] < pivot)
			i++;

		while (A[j] > pivot)
			j--;

		if (i <= j) {
			T tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(A, left, j);

	if (i < right)
		quickSort(A, i, right);
}

template<class T>
void quickSort(T A[], int size) {
	quickSort(A, 0, size - 1);
}

template <typename T>
void treeSort(T array[], int size) {

    BinaryTree<T> tree;

    for (int i = 0; i < size; i++)
        tree.insertNode(array[i]);

    tree.loadInOrder(array);
}

template <typename T>
void populateArray(T * array, int size) {
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100 + 1;
}

template <typename T>
void clearArray(T * array, int size) {
    for (int i = 0; i < size; i++)
        array[i] = 0;
}
