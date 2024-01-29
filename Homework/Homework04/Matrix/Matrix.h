/*
 * Name: Thomas Pearson
 * Date of Creation: 10/04/2023
 * Date of Last Update: 10/4/2023
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    double** A = nullptr;
    int rows;
    int cols;

public:
    Matrix(int r = 3, int c = 3, double defval = 0);
    Matrix(const Matrix &);
    ~Matrix();

    void display();
    void display(int);
    int getRows();
    int getCols();
    void resize(int r = 3, int c = 3, double defval = 0);
    void set(int, int, double);
    double get(int, int);
    Matrix operator=(const Matrix &);
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);
    friend std::ostream& operator<<(std::ostream&, const Matrix &);
    friend Matrix operator*(const Matrix &, double);
    friend Matrix operator*(double, const Matrix &);
    double* operator[](int);
    Matrix transpose();
    friend Matrix operator*(const Matrix &, const Matrix &);
};


# endif // MATRIX_H
