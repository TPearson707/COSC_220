/*
 * Name: Thomas Pearson
 * Date of Creation: 9/26/2023
 * Date of Last Update: 9/26/2023
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

template<class T>
class Array2D {
private:
    vector<vector<T>> A;
    int rows;
    int cols;
    T defval;

public:
    Array2D(int r, int c, T);
    Array2D(const Array2D &);
    ~Array2D();

    void display();
    void display(int);
    int getRows();
    int getCols();
    void resize(int r, int c);
    void set(int, int, T);
    T get(int, int);

    Array2D operator=(const Array2D &);

    bool operator==(const Array2D &);
    bool operator!=(const Array2D &);

    vector<T> & operator[](int);

    template <class U>
    friend ostream &operator<<(ostream &, const Array2D<U> &);

    void memError();
    void setError();
    void getError();
};

/*
 * Description: Constructor for the Array2D class. Called if the user enters a row, col, and a default value at parameters when creating object
 * Parameters: int r, int c, T d
 * Return Type: none
 */
template<class T>
Array2D<T>::Array2D(int r, int c, T d) {
        rows = r;
        cols = c;
        defval = d;

        if (rows < 1)
            rows = 1;

        if (cols < 1)
            cols = 1;

        A.resize(rows);

        try {

            for (int i = 0; i < rows; i++) {

                A[i].resize(cols);

                for (int j = 0; j < cols; j++) {

                    A[i][j] = defval;

                }

            }

        } catch (std::bad_alloc &e) {

            memError();

        }
    }

/*
 * Description: Copy Constructor for teh Array2D class
 * Parameters: const Array2D & arr
 * Return Type: None
 */
template<class T>
Array2D<T>::Array2D(const Array2D & arr) {
    rows = arr.rows;
    cols = arr.cols;
    defval = arr.defval;

    A.resize(rows);

    try {


        for (int i = 0; i < rows; i++) {

            A[i].resize(cols);

            for (int j = 0; j < cols; j++) {

                A[i][j] = arr.A[i][j];

            }
        }

    } catch (std::bad_alloc &e) {

        memError();

    }
}

/*
 * Description: Desctrocutor for the Array2D class has no functionality, but is good practice to include.
 * Parameters: none
 * Return Type: none
 */
template<class T>
Array2D<T>::~Array2D() {

}

/*
 * Description: Displays the matrix with the single space in between values
 * Parameters: none
 * Return Type: none
 */
template<class T>
void Array2D<T>::display() {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cout << A[i][j] << " ";
        }

        cout << endl;

    }
}

/*
 * Description: Displays the matrix with inputted amount of spaces in between values
 * Parameters: int space
 * Return Type: none
 */
template<class T>
void Array2D<T>::display(int space) {

    if (space <= 0) {

        display();
        return;

    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            cout << setw(space) << A[i][j];

        }

        cout << endl;

    }
}

/*
 * Description: Returns the rows for the matrix
 * Parameters: none
 * Return Type: int
 */
template<class T>
int Array2D<T>::getRows() {
    return rows;
}

/*
 * Description: Returns the columns for the matrix
 * Parameters: none
 * Return Type int
 */
template<class T>
int Array2D<T>::getCols() {
    return cols;
}

/*
 * Description: checks to see if rows and cols entered are less than one, if they are assign them to 1.
 * Then resizes the array accordingly.
 * Parameters: int r (rows for new array default is 3) int c (cols for new array default is 3) int defval(default value for the new array)
 * Return Type: none
 */
template<class T>
void Array2D<T>::resize(int r, int c) {

    if (r < 1)
        r = 1;

    if (c < 1)
        c = 1;

    int minRow;

    if (r <= rows)
        minRow = r;
    else
        minRow = rows;

    int minCol;

    if (c <= cols)
        minCol = c;
    else
        minCol = cols;

    vector<vector<T>> copyA;

    copyA.resize(r);

    for (int i = 0; i < r; i++) {

        copyA[i].resize(c);

    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            copyA[i][j] = defval;

    for (int i = 0; i < minRow; i++)
        for (int j = 0; j < minCol; j++)
            copyA[i][j] = A[i][j];

    A = copyA;

    rows = r;
    cols = c;

}

/*
 * Description: takes in a row, column, and a value, and sets that element in the matrix to the value.
 * Parameters: int r, int c, T val
 * Return Type: none
 */
template<class T>
void Array2D<T>::set(int r, int c, T val) {

    if (r < 0 || r > rows) {
        setError();
        return;
    }

    if (c < 0 || c > cols) {
        setError();
        return;
    }

    A[r][c] = val;
}

/*
 * Description: returns an element from row and column entered to the function
 * Parameters: int r, int c
 * Return Type: T
 */
template<class T>
T Array2D<T>::get(int r, int c) {

    if (r < 0 || r > rows) {

        getError();
        return defval;
    }

    if (c < 0 || c > cols) {
        getError();
        return defval;
    }

    return A[r][c];
}

/*
 * Description: overloads the assignment operator so we can assign the value of a 2D array to another 2D array matrix1 = matrix2
 * Parameters: const Array2D & rhs
 * Return Type: Array2D<T>
 */
template <class T>
Array2D<T> Array2D<T>::operator=(const Array2D & rhs) {

    rows = rhs.rows;
    cols = rhs.cols;
    defval = rhs.defval;

    A.resize(rows);

    for (int i = 0; i < rows; i++)
        A[i].resize(cols);

    try {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                A[i][j] = rhs.A[i][j];
            }
        }

    } catch (std::bad_alloc &e) {

        memError();

    }

    return *this;
}

/*
 * Description: Overloads the equivalence operator == so that we can compare a matrix to a matrix and determine if they are equivalent
 * Parameters: const Array2D & obj
 * Return Type: bool
 */
template <class T>
bool Array2D<T>::operator==(const Array2D & obj) {

    if (rows != obj.rows || cols != obj.cols)
        return false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] != obj.A[i][j])
                return false;
        }
    }

    return true;

}

/*
 * Description: Overloads the not equivalent operator != so that we can compare a matrix to a matrix and determine if they are not equal
 * Parameters: const Array2D & obj
 * Return Type: bool
 */
template <class T>
bool Array2D<T>::operator!=(const Array2D & obj) {

    if (rows != obj.rows || cols != obj.cols)
        return true;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] != obj.A[i][j])
                return true;
        }
    }

    return false;
}

/*
 * Description: Overloads the [] operator for Array2D class, will return the row of vector using overload
 * Parameters: int row
 * Return Type: vector<T>
 */
template <class T>
vector<T> & Array2D<T>::operator[](int row) {

    return A[row];

}

/*
 * Description: Overloads the output stream so we can print out our Array2D in a clean order with just a cout << object
 * Parameters: ostream & os, const Array2D<T> & obj
 * Return Type: ostream &
 */
template <class T>
ostream & operator<<(ostream & os, const Array2D<T> &obj) {

    os << "[";

    for (int i = 0; i < obj.rows; i++) {

        os << " [ ";

        for (int j = 0; j < obj.cols; j++) {
          os << obj.A[i][j] << " ";
        }

        os << " ] ";

    }

    os << " ] ";

    return os;
}

/*
 * Description: If there is a problem allocating memory it prints a message and exits the program
 * Parameters: None
 * Return Type: None
 */
template <class T>
void Array2D<T>::memError() {

    cout << "ERROR: Cannot allocate memory." << endl;
    exit(1);
}

/*
 * Description: Prints out a message for the user if they try to set the array to a value in a position that is out of bounds.
 * Parameters: None
 * Return Type: None
 */
template <class T>
void Array2D<T>::setError() {

    cout << "Index out of bounds, no change to the array." << endl;

}

/*
 * Description: Prints out a message for the user if they try to get a value from an index that is out of bounds.
 * Parameters: None
 * Return Type: None
 */
template <class T>
void Array2D<T>::getError() {

    cout << "Index is out of bounds, returning default value." << endl;

}
# endif //ARRAY2D_H
