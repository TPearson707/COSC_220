/*
 * Description: Header file for Person class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "Date.h"
#include "FeetInches.h"

using namespace std;

class Person {
private:
    string lastName;
    string firstName;
    FeetInches height;
    double weight;
    Date dob;

public:

    Person();
    Person(string, string, FeetInches, double, Date);

    virtual ~Person();

    void setName(string, string);
    void setLastName(string);
    void setFirstName(string);
    void setHeight(int, int);
    void setHeight(int);
    void setWeight(double);
    void setDob(int, int, int);

    string getFormal() const;
    string getInformal() const;
    FeetInches getHeight() const;
    double getWeight() const;
    Date getDob() const;

    virtual string toString();

};

#endif // PERSON_H
