/*
 * Name: Thomas Pearson
 * Date of Creation: 9/26/2023
 * Date of Last Update: 9/26/2023
 */

#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

/*
 * Description: constructor to build the 2D array
 * parameters: int r (rows for array) int c (cols for array) int defval (initial value for each index of the array)
 */
Matrix::Matrix(int r, int c, double defval) {
    rows = r;
    cols = c;

    if (rows < 1)
        rows = 1;

    if (cols < 1)
        cols = 1;

    A = new double*[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new double[cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = defval;
        }
    }

}

/*
 * Description: Copy Constructor for Matrix Class
 * Parameters: const Matrix & matrix
 * return type: none
 */
Matrix::Matrix(const Matrix &matrix) {
    rows = matrix.rows;
    cols = matrix.cols;

    A = new double*[rows];

    for (int i = 0; i < rows; i++)
        A[i] = new double[cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = matrix.A[i][j];
        }
    }
}

/*
 * Description: Destructor for 2D Array
 */
Matrix::~Matrix() {
    for (int i = 0; i< rows; i++)
        delete[] A[i];
    delete[] A;
}

// displays the array
void Matrix::display() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// displays the array adding x amount of spaces to each column
// parameters: int space (number of spaces for each column)
void Matrix::display(int space) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(space) << A[i][j];

        }
        cout << endl;
    }
}

// returns the amount of rows the array has
int Matrix::getRows() {
    return rows;
}

// returns the amount of columns the array has
int Matrix::getCols() {
    return cols;
}

/*
 * Description: checks to see if rows and cols entered are less than one, if they are assign them to 1.
 * Then resizes the array accordingly.
 * Parameters: int r (rows for new array default is 3) int c (cols for new array default is 3) int defval(default value for the new array)
 * Return Type: none
 */
void Matrix::resize(int r, int c, double defval) {

    if (r < 1)
        r = 1;

    if (c < 1)
        c = 1;

    double **copyA = new double*[r];

    for (int i = 0; i < r; i++)
        copyA[i] = new double[c];

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
void Matrix::set(int r, int c, double val) {
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
double Matrix::get(int r, int c) {
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

/*
 * Description: = operator overload to copy another matrix after object creation
 * Parameters: const Matrix & matrix
 * return type: Matrix
 */
Matrix Matrix::operator=(const Matrix &matrix) {

    for (int i = 0; i < rows; i++)
        delete[] A[i];

    delete[] A;

    rows = matrix.rows;
    cols = matrix.cols;
    
    A = new double*[rows];

    for (int i = 0; i < rows; i++)
        A[i] = new double [cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            A[i][j] = matrix.A[i][j];

    return *this;
}

/*
 * Description: Addition operator overload to add two Matrixes together
 * Parameters: const Matrix &lhs, const Matrix &rhs
 * return type: Matrix
 */
Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
  
    if (lhs.rows == rhs.rows && lhs.cols == rhs.cols) {

        Matrix matrix(lhs.rows, lhs.cols, 0);

        for (int i = 0; i <  lhs.rows; i++)
            for (int j = 0; j < lhs.cols; j++)
                matrix.A[i][j] = lhs.A[i][j] + rhs.A[i][j];

        return matrix;
    }

    Matrix matrix(1, 1, 0);
    return matrix;
  
}

/*
 * Description: Subtraction operator overload to subtract two matrixes
 * Parameters: const Matris &lhs, const Matrix &rhs
 * return type: Matrix
 */
Matrix operator-(const Matrix &lhs, const Matrix &rhs) {
    
    if (lhs.rows == rhs.rows && lhs.cols == rhs.cols) {

        Matrix matrix(lhs.rows, lhs.cols, 0);

        for (int i = 0; i <  lhs.rows; i++)
            for (int j = 0; j < lhs.cols; j++)
                matrix.A[i][j] = lhs.A[i][j] - rhs.A[i][j];

        return matrix;
    }

    Matrix matrix(1, 1, 0);
    return matrix;
}

/*
 * Description: insertion operator overload to print the vlaues of a matrix on a single line
 * Parameters: ostream & os, const Matrix &matrix
 * return type: ostream&
 */
ostream& operator<<(ostream & os, const Matrix & matrix) {
    os << "[";

    for (int i = 0; i < matrix.rows; i++) {
      
        os << " [ ";
      
        for (int j = 0; j < matrix.cols; j++) {
          os << matrix.A[i][j] << " ";
        }

        os << " ] ";
      
    }
  
    os << " ] ";

    return os;
}

/*
 * Description: multiplies a matrix by a double
 * Parameters: const Matrix & matrixMult, double num
 * return type: Matrix
 */

Matrix operator*(const Matrix & matrixMult, double num) {
  
    Matrix matrix(matrixMult.rows, matrixMult.cols, 0);

    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.cols; j++)
            matrix.A[i][j] = matrixMult.A[i][j] * num;

  return matrix;
}

Matrix operator*(double num, const Matrix & matrixMult) {
    return matrixMult * num;
}

double* Matrix::operator[](int row) {
    
    if (row < 0 || row >= rows) {
        return nullptr;

    }

    return A[row];
    
}

/*
 * Description: takes and array and renturns the transposed array
 * Parameters: none
 * Return Type: Matrix
 */
Matrix Matrix::transpose() {
    Matrix matrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[j][i] = A[i][j];
        }
    }

    return matrix;
}

/* 
 * Description: Multiplies a matrix by a matrix 
 * Parameters: const Matrix &lhs, const Matrix &rhs
 * return type: Matrix
 */
Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
  if (lhs.cols != rhs.rows)
    return Matrix();

  Matrix product(lhs.rows, rhs.cols);
  for (int i = 0; i < lhs.rows; i++) {
    for (int j = 0; j < rhs.cols; j++) {
      product[i][j] = 0;
        for (int k = 0; k < lhs.cols; k++)
          product[i][j] += lhs.A[i][k] * rhs.A[k][j];
    }
  }
  return product;
}
