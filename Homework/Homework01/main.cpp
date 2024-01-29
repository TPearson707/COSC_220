/*
 * Name: Thomas Pearson
 * Creation Date: 09/11/2023
 * Last Update: 9/14/2023
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int *getRandomNumbers(int);
int *duplicateArray(int *, int);
void display(int *, int);
void div();
void sort(int *, int);
bool sorted(int *, int);
void concat(int *&, int &, int *, int);
void remove(int *&, int &, int, int);
void shuffle(int *, int);
void sub(int *&, int &, int, int);
void insert(int *&, int, int *, int, int);
void resize(int *&arr, int &oldSize, int newSize);

int main() {
  int size = 0;

  cout << "Input array size: ";
  cin >> size;

  int *A = getRandomNumbers(size);

  display(A, size);
  sort(A, size);
  display(A, size);

  if (sorted(A, size))
    cout << "Array is sorted." << endl;
  else
    cout << "Array is not sorted." << endl;

  div();

  delete[] A;

  A = new int[10];
  size = 10;

  for (int i = 0; i < size; i++)
    A[i] = i + 1;

  int *copyA = duplicateArray(A, size);

  display(A, size);
  shuffle(A, size);
  display(A, size);

  cout << sorted(A, size) << endl;

  sort(A, size);
  display(A, size);

  cout << sorted(A, size) << endl;

  div();

  int *B = new int[5];
  int sizeB = 5;

  for (int i = 0; i < sizeB; i++)
    B[i] = rand() % 100;

  display(B, sizeB);
  display(A, size);
  concat(A, size, B, sizeB);
  display(B, sizeB);
  display(A, size);
  div();

  // Reset A to original data.
  delete[] A;
  size = 10;
  A = duplicateArray(copyA, size);

  display(A, size);
  remove(A, size, 3, 7);
  display(A, size);
  div();

  // Reset A to original data.
  delete[] A;

  size = 10;
  A = duplicateArray(copyA, size);
  display(A, size);
  sub(A, size, 3, 7);
  display(A, size);
  div();

  // Reset A to original data.
  delete[] A;
  size = 10;
  A = duplicateArray(copyA, size);
  display(A, size);
  display(B, sizeB);
  insert(A, size, B, sizeB, 2);
  display(A, size);
  div();

  // Reset A to original data.
  delete[] A;
  size = 10;
  A = duplicateArray(copyA, size);
  display(A, size);
  resize(A, size, 20);
  display(A, size);
  div();

  // Reset A to original data.
  delete[] A;
  size = 10;
  A = duplicateArray(copyA, size);
  display(A, size);
  resize(A, size, 5);
  display(A, size);

  delete[] A;
  A = nullptr;
  delete[] copyA;
  copyA = nullptr;
  delete[] B;
  B = nullptr;

  return 0;
}

void div() { cout << "\n--------------------------------------------\n\n"; }
// creates an array and fills it with random numbers
// // parameters: size
int *getRandomNumbers(int size) {
  int *arr = new int[size];

  srand(time(0));

  for (int i = 0; i < size; i++)
    *(arr + i) = rand() % 20 + 1;

  return arr;
}
// prints out an array
// int * int
void display(int *arr, int size) {

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
// duplicates the array
// parameters int * int
int *duplicateArray(int *arr, int size) {
  int *dupeArr = new int[size];

  for (int i = 0; i < size; i++)
    dupeArr[i] = arr[i];

  return dupeArr;
}
// sorts an array using bubblesort
// int * int
void sort(int *arr, int n) {
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    // If no two elements were swapped
    // by inner loop, then break
    if (swapped == false)
      break;
  }
}

/*
 * for each element in the array starting from index 0
 * if element is less
 */
// checks if an array is sorted
// parameters int * int
bool sorted(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    for (int j = i; j < arrSize - i; j++) {
      if (arr[i] > arr[j]) {
        return false;
      }
    }
  }
  return true;
}

// concatenates two array together
// parameters int *& int & int * int
void concat(int *&arr, int &size1, int *arr2, int size2) {
  int *newArr = duplicateArray(arr, size1+size2);
  int counter = 0;
  for (int i = size1; i < size1 + size2; i++) {
    newArr[i] = arr2[counter];
    counter++;
  }

  delete[] arr;

  arr = duplicateArray(newArr, size1);
  delete[] newArr;
  size1 += size2;
}

// removes starting index through ending index from the array
// parameters int *& int & int int
void remove(int *&arr, int &size, int si, int ei) {
   if (si >= ei)
      return;
   if (si < 0)
      si = 0;

  int dupeSize = size - (ei - si);
  int *newArr = duplicateArray(arr, dupeSize);
  int counter = 0;

  for (int i = 0; i < size; i++) {
    if (!(i >= si && i < ei)) {
      counter++;
    } else {
        newArr[i - counter] = arr[i];
  }
  }
  delete[] arr;
  size = dupeSize;
  arr = duplicateArray(newArr, dupeSize);
  delete[] newArr;
}
// shuffles the elements of the array
// paramters int * int
void shuffle(int *arr, int arrSize) {
  int ranNumOne;
  int ranNumTwo;
  srand(time(0));

  for (int i = 0; i < 500; i++) {
    ranNumOne = rand() % arrSize;
    ranNumTwo = rand() % arrSize;

    while (ranNumOne == ranNumTwo) {
      ranNumOne = rand() % arrSize;
      ranNumTwo = rand() % arrSize;
    }

    swap(arr[ranNumOne], arr[ranNumTwo]);
  }
}

// changes the array into a sub array from starting index and ends before end index
// paramters int *& int & int int
void sub(int *&arr, int &size, int si, int ei) {
  if (si > ei)
      return;
  if (si < 0)
      si = 0;
  int dupeSize = ei - si;
  int *newArr = duplicateArray(arr, dupeSize);
  int counter = 0;

  for (int i = 0; i < size; i++) {
    if (!(i >= si && i < ei)) {
      counter++;
    } else {
        newArr[i - counter] = arr[i];
  }
  }
  delete[] arr;
  size = dupeSize;
  arr = duplicateArray(newArr, dupeSize);
  delete[] newArr;
  newArr = nullptr;
}
// resizes the first array to fit the second arry where it should be inserted at
// paramters int *& int int * int int
void insert(int *&arr, int size, int *arrB, int sizeB, int insAt) {
  arr = duplicateArray(arr, size + sizeB);

  int counter = 0;
  for (int i = insAt; i < sizeB + insAt; i++) {
    *(arr + i) = arrB[counter];
    counter++;
  }
}
// resize the given array to a new size and changes the old size to the new size
// paramters int *&arr int & int
void resize(int *&arr, int &oldSize, int newSize) {
  int* newArr = duplicateArray(arr, newSize);

  if (newSize < oldSize) {
      return;
  }
  if (newSize == oldSize) {
        for (int i = 0; i < oldSize; i++) {
            newArr[i] = arr[i];
        }
        arr = newArr;
        return;
  }
  if (newSize > oldSize) {
    for (int i = oldSize; i < newSize; i++) {
        newArr[i] = 0;
    }
    delete[] arr;
    arr = duplicateArray(newArr, newSize);
    delete[] newArr;
    oldSize = newSize;
    return;
  }
}
