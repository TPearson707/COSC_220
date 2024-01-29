/*
 * Description: Header file for Date class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
public:
    Date(); // default constructor
    Date(int, int, int); // constructor to set month, day, year
    ~Date(); // destructor for Date objects

    void setDate(int, int, int);
    void setMDY(string);
    string toString();

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    bool operator>(const Date & rhs);
    bool operator<(const Date & rhs);
    bool operator>=(const Date & rhs);
    bool operator<=(const Date & rhs);
    bool operator==(const Date & rhs);
    bool operator!=(const Date & rhs);

    friend ostream & operator<<(ostream & os, const Date & Obj);

};

#endif //DATE_H
