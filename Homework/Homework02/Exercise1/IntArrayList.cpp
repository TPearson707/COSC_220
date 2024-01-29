/*
 * Name: Thomas Pearson
 * Date of Creation: 09/17/2023
 * Date of Last Update: 09/19/2023
 */

#include "IntArrayList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

IntArrayList::IntArrayList() {
    list = nullptr;
    size = 0;
}

IntArrayList::~IntArrayList() {
    delete[] list;
}

/*
 * Description: created a duplicate array of the object calling the function
 * parameters: IntArrayList &list2
 * return type: none
 */
void IntArrayList::duplicate(IntArrayList &list2) {
    if (list2.list != nullptr) { // if list2.list is not assigned to nullptr free up memory
        delete [] list2.list;
        list2.list = nullptr;
    }

    list2.list = new int[size]; // create a new list for list2 the same size as list

    for (int i = 0; i < size; i++)
        *(list2.list + i) = *(list + i); // copy the elements over to list2.list from list

    list2.size = size; // change the size of list2.list to size
}

/*
 * Description: Displays the list vertically if bool vert is declared true
 * Parameters: bool vert
 * return type none;
 */
void IntArrayList::display(bool vert) {
    if (vert == true) {
        for (int i = 0; i < size; i++)
            cout << list[i] << endl;

        return;
    }

    for (int i = 0; i < size; i++)
        cout << list[i] << " ";

    cout << endl;
}

void IntArrayList::displayAddress() {
    cout << &list << endl;
}

/*
 * Description: sorts the array using bubble sort
 * Parameters: none
 * Return type: none
 */
void IntArrayList::sort() {
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
    for (j = 0; j < size - i - 1; j++) {
        if (list[j] > list[j + 1]) {
            swap(list[j], list[j + 1]);
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
 * Description: returns true if the array is sorted and false if the array is not
 * Parameters: none
 * return type: none
 */
bool IntArrayList::sorted() {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size - i; j++) {
            if (list[i] > list[j]) {
                return false;
            }
        }
    }
    return true;
}
/*
 * Descrition: adds a number to the end of list
 * parameters: int num (number to be appended)
 * return type: none
 */
void IntArrayList::add(int num) {
    size += 1; // change size to our new size
    int *copyArr = new int[size]; // create a copy array to hold old values
    for(int i = 0; i < size - 1; i++)
        *(copyArr + i) = *(list + i); // for old size set the values of x index to list

    copyArr[size - 1] = num; // set the last index of copyArr to the vlaue to be added

    delete[] list; // free memory from old list
    list = nullptr; // set list to nullptr
    list = new int[size]; // create a new list of our new size

    for (int i = 0; i < size; i++)
        *(list + i) = *(copyArr + i); // set values of new list to copyArr

    delete[] copyArr; // free up memory by deleting copyArr
    copyArr = nullptr; // set copyArr to nullptr
}

/*
 * Description: concatenates the two array together
 * Parameters: const IntArrayList &list2
 * return type: none
 */
void IntArrayList::concat(const IntArrayList &list2) {
    int newSize = list2.size + size;
    int *copyArr = new int[newSize];

    for (int i = 0; i < size; i++) {
        copyArr[i] = list[i];
    }

    int counter = 0;
    for (int i = size; i < newSize; i++) {
        copyArr[i] = list2.list[counter];
        counter++;
    }

    delete[] list;
    list = nullptr;
    list = new int[newSize];

    for (int i = 0; i < newSize; i++) {
        list[i] = copyArr[i];
    }

    delete[] copyArr;
    copyArr = nullptr;

    size = newSize;
}

/*
 * Description: remove the elements from starting index and ending index from the array
 * Parameters: int start, int end
 * return type: none
 */
void IntArrayList::remove(int start, int end) {
    if (start >= end)
        return;

    if (start < 0)
        start = 0;

    if ((start + end) > size) {
        delete[] list;
        list = nullptr;
        return;
    }

    int newSize = size - (end - start);
    int *copyArr = new int[newSize];
    int counter = 0;

    for (int i = 0; i < size; i++) {
      if ((i >= start && i < end)) {
        counter++;
      } else {
        copyArr[i - counter] = list[i];

    }
    }

    delete[] list;
    list = nullptr;
    list = new int[newSize];
    for (int i = 0; i < newSize; i++) {
      list[i] = copyArr[i];
    }

    delete[] copyArr;
    copyArr = nullptr;
    size = newSize;
}

/*
 * Description: creates a sub array of the array
 * Parameters: int start, int end
 * return type: none
 */
void IntArrayList::sub(int start, int end) {
    if (start > end)
        return;

    if (start < 0)
        start = 0;

    if (end > size) {
        end = size;
    }
    int newSize = end - start;
    int *copyArr = new int[newSize];

    int counter = 0;

    for (int i = 0; i < size; i++) {
    if (!(i >= start && i < end)) {
        counter++;
    } else {
        copyArr[i - counter] = list[i];
    }
    }

    delete[] list;
    list = nullptr;
    list = new int[newSize];

    for (int i = 0; i < newSize; i++) {
        list[i] = copyArr[i];
    }

    delete[] copyArr;
    copyArr = nullptr;

    size = newSize;
}

/*
 * Description: inserts an inputted array into the objects array from starting index
 * Parameters: const IntArrayList& list2, int index
 * return type: none
 */
void IntArrayList::insert(const IntArrayList& list2, int index) {

    if (index > size + list2.size || index < 0)
        return;

    int newSize = size + list2.size;
    cout << newSize << endl;
    int *copyArr = new int[newSize];

    for (int i = 0; i < index; i++)
        copyArr[i] = list[i];

    int counter1 = 0;
    for (int i = index; i < list2.size + index; i++) {
        copyArr[i] = list2.list[counter1];
        counter1++;
    }

    int counter2 = index;
    for (int i = index + list2.size; i < newSize; i++) {
        copyArr[i] = list[counter2];
        counter2++;
    }

    delete[] list;
    list = nullptr;
    list = new int[newSize];

    for (int i = 0; i < newSize; i++)
        list[i] = copyArr[i];

    delete[] copyArr;
    copyArr = nullptr;

    size = newSize;
}

/*
 * Description: inserts a number into index element in list and shifts other elements accordingly to fit
 * Parameters: int value, int index
 * return type: none
 */
void IntArrayList::insert(int value, int index) {

    if (index > size + 1 || index < 0)
        return;

    int newSize = size + 1;
    int *copyArr = new int[newSize];

    int counter = 0;
    for(int i = 0; i < newSize; i++) {
        if (i != index) {
            copyArr[i] = list[counter];
            counter++;
        } else {
            copyArr[i] = value;
        }
    }

    delete[] list;
    list = nullptr;
    list = new int[newSize];

    for (int i = 0; i < newSize; i++)
        list[i] = copyArr[i];

    delete[] copyArr;
    copyArr = nullptr;
    size = newSize;
}

/*
 * Description: shuffles the elements in the list
 * Parameters: none
 * return type: none
 */
void IntArrayList::shuffle() {
    int ranNumOne;
    int ranNumTwo;
    srand(time(0));

    for (int i = 0; i < 500; i++) {
        ranNumOne = rand() % size;
        ranNumTwo = rand() % size;

    while (ranNumOne == ranNumTwo) {
            ranNumOne = rand() % size;
            ranNumTwo = rand() % size;
    }

    swap(list[ranNumOne], list[ranNumTwo]);
    }
}

/*
 * Description: returns the elements of list[i]
 * Parameters: int i
 * return type int
 */
int IntArrayList::get(int i) {
    return list[i];
}

/*
 * Description: sets the element of list[i] to num
 * Parameters: int num, int i
 * return type: none
 */
void IntArrayList::set(int num, int i) {
    if (i < size && i >= 0)
        list[i] = num;

}

/*
 * Description: resizes the array to new given size
 * Parameters: int newSize
 * return type: none
 */
void IntArrayList::resize(int newSize) {
    int *newList = new int[newSize];

    for (int i = 0; i < newSize; i++)
        newList[i] = list[i];

    delete[] list;
    list = nullptr;

    list = new int[newSize];

    for (int i = 0; i < newSize; i++) {
        list[i] = newList[i];
    }

    delete[] newList;
    newList = nullptr;

    size = newSize;
}

/*
 * Description: returns the length of list
 * Parameters: none
 * return type: int
 */
int IntArrayList::length() {
    return size;
}
