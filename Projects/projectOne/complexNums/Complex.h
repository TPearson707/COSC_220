/*
 * Name of Author: Thomas Pearson
 * Desciption: class for complex numbers
 * Date of Creation: 10/13/2023
 * Date of Last Update: 10/15/2023
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double realNum; // real number in complex number
    double imagNum; // imaginary number in complex number

public:
    Complex();
    Complex(double, double);
    Complex(double);
    ~Complex();
    void set(double, double);
    void setReal(double);
    void setImag(double);
    double getReal();
    double getImag();
    double mod();

    Complex operator+(const Complex &);
    Complex operator+(double);
    friend Complex operator+(double, const Complex &);

    Complex operator-(const Complex &);
    Complex operator-(double);
    friend Complex operator-(double, const Complex &);

    Complex operator*(const Complex &);
    Complex operator*(double);
    friend Complex operator*(double, const Complex &);

    Complex operator/(const Complex &);
    Complex operator/(double);
    friend Complex operator/(double, const Complex &);

    Complex operator+=(const Complex &);
    Complex operator-=(const Complex &);

    Complex operator^(int);

    bool operator==(const Complex &);
    bool operator!=(const Complex &);

    Complex operator=(const Complex &);

    friend std::ostream& operator<<(std::ostream&, const Complex &);
    friend std::istream& operator>>(std::istream&, Complex &);
};

#endif // COMPLEX_H
