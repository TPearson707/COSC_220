/*
 * Description: Implementation file for Person class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#include "Person.h"

/*
 * Description: Default constructor for Person class
 * Parameters: None
 * Return Type: None
 */
Person::Person() {

    lastName = " ";
    firstName = " ";
    height.setFeet(0);
    height.setInches(0);
    dob.setDate(0, 0, 0);

}

/*
 * Description: Overloaded constructor for Person class
 * Parameters: string last, string first, FeetInches h, double w, Date date
 * Return Type: None
 */
Person::Person(string last, string first, FeetInches h, double w, Date date) {

        lastName = last;
        firstName = first;
        height = h;
        weight = w;
        dob.setMDY(date.toString());

}

/*
 * Description: Destructor for Person class
 * Parameters: None
 * Return Type: None
 */
Person::~Person() {

}

/*
 * Description: Setter for first and last name variables
 * Parameters: string last string first
 * Return Type: None
 */
void Person::setName(string last, string first) {

    lastName = last;
    firstName = first;

}

/*
 * Description: Setter for lastName variable
 * Parameters: string last
 * Return Type: None
 */
void Person::setLastName(string last) {

    lastName = last;

}

/*
 * Description: Setter for firstName variable
 * Parameters: string first
 * Return Type: None
 */
void Person::setFirstName(string first) {

    firstName = first;

}

/*
 * Description: Setter for feet and inches
 * Parameters: int f, int i
 * Return Type: None
 */
void Person::setHeight(int f,int i) {

    height.setFeet(f);
    height.setInches(i);

}

/*
 * Description: Setter for inches utilizing the simplify function from FeetInches
 * Parameters: int i
 * Return Type: None
 */
void Person::setHeight(int i) {

    height.setInches(i);

}

/*
 * Description: Setter for weight variable
 * Parameters: double w
 * Return Type: None
 */
void Person::setWeight(double w) {

    weight = w;

}

/*
 * Description: Setter for Date variable in Person class
 * Parameters: int m int d int y
 * Return Type: None
 */
void Person::setDob(int m, int d, int y) {

    dob.setDate(m, d, y);

}

/*
 * Description: Returns a string of formal player name example Pearson, Thomas
 * Parameters: None
 * Return Type: String
 */
string Person::getFormal() const {

    string formal;
    formal = lastName + ", " + firstName;
    return formal;

}

/*
 * Description: Returns a string of informal Player name example Thomas, Pearson
 * Parameters: None
 * Return Type: String
 */
string Person::getInformal() const {

    string informal;
    informal = firstName + ", " + lastName;
    return informal;

}

/*
 * Description: Returns the height variable from Person class
 * Parameters: None
 * Return Type: FeetInches
 */
FeetInches Person::getHeight() const {

    return height;

}

/*
 * Description: Returns the weight variable from Person class
 * Parameters: None
 * Return Type: double
 */
double Person::getWeight() const {

    return weight;

}

/*
 * Description: Returns the dob variable from Person class
 * Parameters: None
 * Return Type: Date
 */
Date Person::getDob() const {

    return dob;

}

/*
 * Description: Returns a string that contains the data for each player
 * Parameters: None
 * Return Type: string
 */
string Person::toString() {

    string formal;
    formal = lastName + ", " + firstName + " / " + to_string(height.getFeet()) + " feet, " + to_string(height.getInches()) + " inches / " + to_string(weight) + " / " + dob.toString();
    return formal;

}
