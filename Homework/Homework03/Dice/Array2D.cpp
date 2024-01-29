/*
 * Name: Thomas Pearson
 * Date of Creation: 9/26/2023
 * Date of Last Update: 9/26/2023
 */

#include <iostream>
#include <iomanip>
#include "Array2D.h"

using namespace std;

/*
 * Description: constructor to build the 2D array
 * parameters: int r (rows for array) int c (cols for array) int defval (initial value for each index of the array)
 */
Array2D::Array2D(int r, int c, int defval) {
    rows = r;
    cols = c;

    if (rows < 1)
        rows = 1;

    if (cols < 1)
        cols = 1;

    A = new int*[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new int[cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = defval;
        }
    }

}

/*
 * Description: Destructor for 2D Array
 */
Array2D::~Array2D() {
    for (int i = 0; i< rows; i++)
        delete[] A[i];
    delete[] A;
}

// displays the array
void Array2D::display() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// displays the array adding x amount of spaces to each column
// parameters: int space (number of spaces for each column)
void Array2D::display(int space) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(space) << A[i][j];

        }
        cout << endl;
    }
}

// returns the amount of rows the array has
int Array2D::getRows() {
    return rows;
}

// returns the amount of columns the array has
int Array2D::getCols() {
    return cols;
}

/*
 * Description: checks to see if rows and cols entered are less than one, if they are assign them to 1.
 * Then resizes the array accordingly.
 * Parameters: int r (rows for new array default is 3) int c (cols for new array default is 3) int defval(default value for the new array)
 * Return Type: none
 */
void Array2D::resize(int r, int c, int defval) {

    if (r < 1)
        r = 1;

    if (c < 1)
        c = 1;

    int **copyA = new int*[r];

    for (int i = 0; i < r; i++)
        copyA[i] = new int[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            copyA[i][j] = defval;
        }
    }

    if (r >= rows && c >= cols) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                copyA[i][j] = A[i][j];
    } else if (r <= rows && c <= cols) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                copyA[i][j] = A[i][j];
    } else if (r >= rows && c <= cols) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < c; j++)
                copyA[i][j] = A[i][j];
    } else if (r <= rows && c >= cols) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < cols; j++)
                copyA[i][j] = A[i][j];
    }


    for (int i = 0; i < rows; i++)
        delete[] A[i];

    delete[] A;
    A = nullptr;
    A = copyA;

    rows = r;
    cols = c;

}

// checks to see if the parameters are within the array if they aren't throw an error and return
// if they are set the row and column entered to the value entered by the user
void Array2D::set(int r, int c, int val) {
    if (r < 0 || r > rows) {
        cout << "Index out of bounds" << endl;
        return;
    }

    if (c < 0 || c > cols) {
        cout << "Index out of bounds" << endl;
        return;
    }

    A[r][c] = val;
}

// checks to see if the parameters are within the bounds of the array if they aren't throw an error and return 1;
// if they are return the value in the row and column entered;
int Array2D::get(int r, int c) {
    if (r < 0 || r > rows) {
        cout << "Index out of bounds" << endl;
        return 0;
    }

    if (c < 0 || c > cols) {
        cout << "Index out of bounds" << endl;
        return 0;
    }

    return A[r][c];
}

int Array2D::checkSame() {
    int counter = 0;
    int currentVal;
    bool allSame;
    for (int i = 0; i < rows; i++) {
        currentVal = A[i][0];
        allSame = false;

        for (int j = 0; j < cols; j++) {
            if (A[i][j] == currentVal && j != 0) {
                allSame = true;
            } else if (A[i][j] != currentVal && j != 0) {
                allSame = false;
                break;
            }

        }

        if (allSame == true)
            counter++;
    }

    return counter;
}
