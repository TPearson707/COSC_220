/*
 * Name of Author: Thomas Pearson
 * Desciption: Implementation of complex numbers class
 * Date of Creation: 10/13/2023
 * Date of Last Update: 10/15/2023
 */

#include "Complex.h"

#include <cmath>

using namespace std;

/*
 * Description: Default constructor if the user doesn't input any values
 * Parameters: none
 * Return Type: none
 */
Complex::Complex() {
    realNum = 0;
    imagNum = 0;
}

/*
 * Description: Constructor for Complex class if user enters a real number and imaginary
 * Parameters: double r (real) double i (imaginary)
 * Return Type: none
 */
Complex::Complex(double r, double i) {

    realNum = r;
    imagNum = i;

}

/*
 * Description: Constructor for Complex class to handle when user only enters real number.
 * Parameters: double r (real)
 * Return Type: none
 */
Complex::Complex(double r) {

    realNum = r;
    imagNum = 0;

}

/*
 * Desciption: Destructor for Complex class
 * Parameters: none
 * Return Type: none
 */
Complex::~Complex() {

}

/*
 * Description: setter function for both real and imaginary
 * Parameters: double r (real) double i (imaginary)
 * Return Type: none
 */
void Complex::set(double r, double i) {

    realNum = r;
    imagNum = i;

}

/*
 * Desciption: setter function for realNum
 * Parameters: double r (real)
 * Return Type: none
 */
void Complex::setReal(double r) {

    realNum = r;

}

/*
 * Description: setter function for imagNum
 * Parameters: double i (imaginary)
 * Return Type: none
 */
void Complex::setImag(double i) {

    imagNum = i;

}

/*
 * Description: getter function for realNum
 * Parameters: none
 * Return Type: double
 */
double Complex::getReal() {

    return realNum;

}

/*
 * Description: getter function for imagNum
 * Parameters: none
 * Return Type: double
 */
double Complex::getImag() {

    return imagNum;

}

/*
 * Desciption: modulus functions to find the modulus of a complex number
 * Parameters: none
 * Return Type: double
 */
double Complex::mod() {

    double modulus = sqrt(pow(realNum, 2) + pow(imagNum, 2));

    return modulus;
}

// ADDITION OPERATOR OVERLOADS

/*
 * Description: overloads the addition operator for the case complex + complex
 * Parameters: const Complex & complexNum
 * Return Type: Complex
 */
Complex Complex::operator+(const Complex & complexNum) {

    Complex complex;
    complex.setReal(realNum + complexNum.realNum);
    complex.setImag(imagNum + complexNum.imagNum);

    return complex;
}

/*
 * Description: overloads the addition operator for the case of complex + real
 * Parameters: double real
 * Return Type: Complex
 */
Complex Complex::operator+(double real) {

    Complex complex;
    complex.setReal(realNum + real);
    complex.setImag(imagNum);

    return complex;
}

/*
 * Desciption: overloads the addition operator for the case of real + complex
 * Parameters: double lhs (real), const Complex & rhs (complex number)
 * Return Type: Complex
 */
Complex operator+(double lhs, const Complex & rhs) {

    Complex complex;
    complex.setReal(lhs + rhs.realNum);
    complex.setImag(rhs.imagNum);

    return complex;
}

// SUBTRACTION OPERATOR OVERLOADS

/*
 * Desciption: overloads the subtraction operator for the case of complex - complex
 * Parameters: const Complex & complexNum
 * Return Type: Complex
 */
Complex Complex::operator-(const Complex & complexNum) {

    Complex complex;
    complex.setReal(realNum - complexNum.realNum);
    complex.setImag(imagNum - complexNum.imagNum);

    return complex;
}

/*
 * Desciption: overloads the subtraction operator for the case of complex - real
 * Parameters: double real
 * Return Type: Complex
 */
Complex Complex::operator-(double real) {

    Complex complex;
    complex.setReal(realNum - real);
    complex.setImag(imagNum);

    return complex;
}

/*
 * Desciption: overloads the subtraction operator for the case of real - complex
 * Parameters: double lhs (real) const Complex & rhs (complex num)
 * Return Type: Complex
 */
Complex operator-(double lhs, const Complex & rhs) {

    Complex complex;
    complex.setReal(lhs - rhs.realNum);
    complex.setImag(0 - rhs.imagNum);

    return complex;
}


// MULTIPLICATION OPERATOR OVERLOADS

/*
 * Desciption: overloads the multiplication operator for the case of complex * complex
 * Parameters: const Complex & complexNum
 * Return Type: Complex
 */
Complex Complex::operator*(const Complex & complexNum) {
    Complex complex;

    double newReal = (realNum * complexNum.realNum) - (imagNum * complexNum.imagNum);
    double newImag = (imagNum * complexNum.realNum) + (realNum * complexNum.imagNum);

    complex.setReal(newReal);
    complex.setImag(newImag);

    return complex;
}

/*
 * Desciption: overloads the multiplication operator for the case of complex * real
 * Parameters: double real
 * Return Type: Complex
 */
Complex Complex::operator*(double real) {

    Complex complex;
    complex.setReal(realNum * real);
    complex.setImag(imagNum * real);

    return complex;
}

/*
 * Desciption: overloads the multiplication operator for the case of real * complex
 * Parameters: double lhs (real) const Complex & rhs (complex number)
 * Return Type: Complex
 */
Complex operator*(double lhs, const Complex & rhs) {

    Complex complex;
    complex.setReal(lhs * rhs.realNum);
    complex.setImag(lhs * rhs.imagNum);

    return complex;
}

// DIVISION OPERATOR OVERLOADS

/*
 * Desciption: overloads the division operator to handle the case of complex / complex
 * Parameters: const Complex & complexNum
 * Return Type: Complex
 */
Complex Complex::operator/(const Complex & complexNum) {

    Complex result;

    double realNumerator = (realNum * complexNum.realNum) + (imagNum * complexNum.imagNum);
    double imagNumerator = (imagNum * complexNum.realNum) - (realNum * complexNum.imagNum);
    double denominator = (complexNum.realNum * complexNum.realNum) + (complexNum.imagNum * complexNum.imagNum);

    result.setReal(realNumerator / denominator);
    result.setImag(imagNumerator / denominator);

    return result;
}

/*
 * Desciption: overloads the division operator to handle the case of complex / real
 * Parameters: double real
 * Return Type: Complex
 */
Complex Complex::operator/(double real) {

    Complex complex;
    complex.setReal(realNum / real);
    complex.setImag(imagNum / real);

    return complex;
}

/*
 * Desciption: overloads the division operator to handle the case of real / complex
 * Parameters: double lhs (real) const Complex & rhs(complex number)
 * Return Type: Complex
 */
Complex operator/(double lhs, const Complex& rhs) {

    Complex result;

    double realNumerator = (lhs * rhs.realNum);
    double imagNumerator = (lhs * rhs.imagNum);
    double denominator = (rhs.realNum * rhs.realNum) + (rhs.imagNum * rhs.imagNum);;

    result.setReal(realNumerator / denominator);
    result.setImag(imagNumerator / denominator);

    return result;
}

/*
 * Desciption: overloads the += operator to handle complex += complex
 * Parameters: const Complex & rhs (complex number)
 * Return Type: Complex
 */
Complex Complex::operator+=(const Complex & rhs) {

    realNum += rhs.realNum;
    imagNum += rhs.imagNum;

    return *this;
}

/*
 * Desciption: overloads the -= operator to handle complex -= complex
 * Parameters: const Complex & rhs (complex number)
 * Return Type: Complex
 */
Complex Complex::operator-=(const Complex & rhs) {

    realNum -= rhs.realNum;
    imagNum -= rhs.imagNum;

    return *this;
}

/*
 * Desciption: overloads the ^ operator to handle (complexNum ^ x)
 * Parameters: int power
 * Return Type: Complex
 */
Complex Complex::operator^(int power) {
    // (ac − bd) + (bc + ad)i

    Complex complex;

    complex.setReal(realNum);
    complex.setImag(imagNum);

    double newReal;
    double newImag;

    for (int i = 1; i < abs(power); i++) {
        newReal = (complex.realNum * realNum) - (complex.imagNum * imagNum);
        newImag = (complex.imagNum * realNum) + (complex.realNum * imagNum);
        complex.setReal(newReal);
        complex.setImag(newImag);
    }

    if (power < 0) {

        double realNumerator = (1 * complex.realNum);
        double imagNumerator = (1 * complex.imagNum);
        double denominator = (complex.realNum * complex.realNum) + (complex.imagNum * complex.imagNum);

        complex.setReal(realNumerator / denominator);
        complex.setImag(imagNumerator / denominator);
    }

    return complex;

}

/*
 * Desciption: overloads the == oerator and returns true if a complex number is equal to another complex number otherwise returns false
 * Parameters: const Complex & rhs (complex number)
 * Return Type: bool
 */
bool Complex::operator==(const Complex & rhs) {

    if (realNum == rhs.realNum && imagNum == rhs.imagNum)
        return true;

    return false;
}

/*
 * Desciption: overloads the == oerator and returns true if a complex number is not equal to another complex number otherwise returns false
 * Parameters: const Complex & rhs (complex number)
 * Return Type: bool
 */
bool Complex::operator!=(const Complex & rhs) {

    if (realNum != rhs.realNum || imagNum != rhs.imagNum)
        return true;

    return false;
}

/*
 * Description: overloads the assignment operator to handle complex = complex
 * Parameters: const Complex & rhs (complex number)
 * Return Type: Complex
 */
Complex Complex::operator=(const Complex & rhs) {

    realNum = rhs.realNum;
    imagNum = rhs.imagNum;

    return *this;
}



/*
 * Description: overloads the extraction operator to handle printing out a complex numbers with a cout statement and formats the cout based on * * * values of realNum and imagNum
 * Parameters: ostream & os, const Complex & complexNum
 * Return Type: ostream&
 */
ostream& operator<<(ostream & os, const Complex & complexNum) {

    if (complexNum.imagNum == 0) {

        os << complexNum.realNum;
        return os;

    } else if (complexNum.realNum == 0) {

        os << complexNum.imagNum << "i";
        return os;

    } else if (complexNum.imagNum < 0) {

        os << complexNum.realNum << " - " << abs(complexNum.imagNum) << "i";
        return os;

    } else {

        os << complexNum.realNum << " + " << complexNum.imagNum << "i";
        return os;

    }
}

/*
 * Description: overloads the insertion operator so we can input a complex number with cin >> z which wll take in a real number and an imaginary * * number separated by a space
 * Parameters: istream & is, Complex & complexNum
 * Return Type: istream
 */
istream& operator>>(istream & is, Complex & complexNum) {

    is >> complexNum.realNum >> complexNum.imagNum;

    return is;
}
