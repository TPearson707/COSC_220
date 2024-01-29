/*
 * Name: Thomas Pearson
 * Date of Creation: 10/02/2023
 * Date of Last Update: 10/03/2023
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Point.h"

Point::Point(double xv, double yv, double zv) {
    x = xv;
    y = yv;
    z = zv;
}

void Point::setX(double xv) {
    x = xv;
}

void Point::setY(double yv) {
    y = yv;
}

void Point::setZ(double zv) {
    z = zv;
}

void Point::setXYZ(double xv, double yv, double zv) {
    x = xv;
    y = yv;
    z = zv;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}

double Point::length() {
    double sqr;

    sqr = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return sqr;
}

Point Point::operator=(const Point &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Point Point::operator+(const Point &rhs) {
    x = x + rhs.x;
    y = y + rhs.y;
    z = z + rhs.z;

    return *this;
}

Point Point::operator-(const Point &rhs) {
    x = x - rhs.x;
    y = y - rhs.y;
    z = z - rhs.z;

    return *this;
}

double Point::operator*(const Point &rhs) {
    double dotProduct;
    dotProduct = (x * rhs.x) + (y * rhs.y) + (z * rhs.z);

    return dotProduct;
}

double Point::operator/(double a) {
    double division;
    division = (x * y * z) / a;

    return division;
}

bool Point::operator==(const Point &rhs) {
    if (x == rhs.x && y == rhs.y && z == rhs.z)
      return true;

    return false;
}

// friend functions
std::ostream& operator<<(std::ostream &os, const Point &point) {

    os << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")";

    return os;
}

std::ostream& operator<<(std::ostream &os, Point &point) {

    os << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")";

    return os;
}

Point operator*(double a, Point &point) {

    double newX, newY, newZ;
    Point newPoint;

    newPoint = point;

    newX = a * point.getX();
    newPoint.setX(newX);

    newY = a * point.getY();
    newPoint.setY(newY);

    newZ = a * point.getZ();
    newPoint.setZ(newZ);

    return newPoint;
}

Point operator*(Point &point, double a) {
    double newX, newY, newZ;
    Point newPoint;

    newPoint = point;

    newX = a * point.getX();
    newPoint.setX(newX);

    newY = a * point.getY();
    newPoint.setY(newY);

    newZ = a * point.getZ();
    newPoint.setZ(newZ);

    return newPoint;
}

Point operator/(Point &point, int a) {
    double newX, newY, newZ;
    Point newPoint;

    newPoint = point;
    newX = newPoint.getX() / a;
    newPoint.setX(newX);

    newY = newPoint.getY() / a;
    newPoint.setY(newY);

    newZ = newPoint.getZ() / a;
    newPoint.setZ(newZ);

    return newPoint;
}
