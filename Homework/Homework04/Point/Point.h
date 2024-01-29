/*
 * Name: Thomas Pearson
 * Date of Creation: 10/02/2023
 * Date of Last Update: 10/03/2023
 */

#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Point {
private:
    double x;
    double y;
    double z;

public:
    Point(double xv = 0, double yv = 0, double zv = 0);
    void setX(double);
    void setY(double);
    void setZ(double);
    void setXYZ(double, double, double);
    double getX() const;
    double getY() const;
    double getZ() const;
    double length();
    Point operator=(const Point &rhs);
    Point operator+(const Point &rhs);
    Point operator-(const Point &rhs);
    double operator*(const Point &rhs);
    double operator/(double a);
    bool operator==(const Point &rhs);
    friend std::ostream& operator<<(std::ostream &os, const Point &point);
    friend std::ostream& operator<<(std::ostream &os, Point &point);
    friend Point operator*(double a, Point &point);
    friend Point operator*(Point &point, double a);
    friend Point operator/(Point &point, int a);
};

#endif
