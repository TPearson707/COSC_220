/*
 * Description: Implementation file for Date class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#include "Date.h"

/*
 * Description: Default constructor for the Date class
 * Parameters: None
 * Return Type: None
 */
Date::Date() { // default constructor

    month = 0;
    day = 0;
    year = 0000;

}

/*
 * Description: Overloaded constructor for the Date class
 * Parameters: int m int d int y
 * Return Type: None
 */
Date::Date(int m, int d, int y) { // constructor to set month, day, year

    month = m;
    day = d;
    year = y;

}

/*
 * Description: Desctructor for the Date class
 * Parameters: None
 * Return Type: None
 */
Date::~Date() { // destructor for Date objects


}

/*
 * Description: Setter function for the date
 * Parameters: int m int d int y
 * Return Type: None
 */
void Date::setDate(int m, int d, int y) {
    try {
        month = m;
        day = d;
        year = y;
    } catch (exception & e) {

        month = 0;
        day = 0;
        year = 0000;
    }
}

/*
 * Description: Setter function that sets month day year if the user inputs a string in xx/xx/xxxx format
 * Parameters: string date
 * Return Type: None
 */
void Date::setMDY(string date) {

    size_t nextSlash;
    size_t startPosition = 0;
    string nextData = " ";

    try {
        for (int i = 0; i < 3; i++) {

            nextSlash = date.find("/", startPosition);
            nextData = date.substr(startPosition, (nextSlash - startPosition));

            switch(i) {
                case 0:
                    month = stoi(nextData);
                    break;
                case 1:
                    day = stoi(nextData);
                case 2:
                    year = stoi(nextData);

            }

            startPosition = nextSlash + 1;

        }
    } catch (exception & e) {
        month = 0;
        day = 0;
        year = 0000;
    }

}

/*
 * Description: Returns the month of a Date object
 * Parameters: None
 * Return Type: int
 */
int Date::getMonth() const {

    return month;

}

/*
 * Description: Returns the day of a Date object
 * Parameters: None
 * Return Type: int
 */
int Date::getDay() const {

    return day;

}

/*
 * Description: Returns the year of a Date object
 * Parameters: None
 * Return Type: int
 */
int Date::getYear() const {

    return year;

}

/*
 * Description: returns a string for a date in xx/xx/xxxx format
 * Parameters: None
 * Return Type: string
 */
string Date::toString() {

    string date;
    date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

    return date;

}

/*
 * Description: overloads the > operator for Date
 * Parameters: const Date & rhs
 * Return Type: bool
 */
bool Date::operator>(const Date & rhs) {

    if (year > rhs.year)
        return true;
    if (year < rhs.year)
        return false;
    if (month > rhs.month && year == rhs.year)
        return true;
    if (month < rhs.month)
        return false;
    if (day > rhs.day && month == rhs.month && year == rhs.year)
        return true;

    return false;
}

/*
 * Description: Overloads the < operator for Date
 * Parameters: const Date & rhs
 * Return Type: bool
 */
bool Date::operator<(const Date & rhs) {

    if (year < rhs.year)
        return true;
    if (year > rhs.year)
        return false;
    if (month < rhs.month && year == rhs.year)
        return true;
    if (month > rhs.month)
        return false;
    if (day < rhs.day && month == rhs.month && year == rhs.year)
        return true;

    return false;

}

/*
 * Description: Overloads the >= operator for Date
 * Parameters: const Date & rhs
 * Return Type: bool
 */
bool Date::operator>=(const Date & rhs) {

    if (year >= rhs.year)
        return true;
    if (year <= rhs.year)
        return false;
    if (month >= rhs.month && year == rhs.year)
        return true;
    if (month <= rhs.month)
        return false;
    if (day >= rhs.day && month == rhs.month && year == rhs.year)
        return true;

    return false;

}

/*
 * Description: Overloads the <= operator for Date
 * Parameters: const Date & rhs
 * Return Type: bool
 */
bool Date::operator<=(const Date & rhs) {

    if (year <= rhs.year)
        return true;
    if (year >= rhs.year)
        return false;
    if (month <= rhs.month && year == rhs.year)
        return true;
    if (month >= rhs.month)
        return false;
    if (day <= rhs.day && month == rhs.month && year == rhs.year)
        return true;

    return false;

}

/*
 * Description: Overloads the == operator for Date
 * Parameters: const Date & rhs
 * Return Type: bool
 */
bool Date::operator==(const Date & rhs) {

    if (year == rhs.year && month == rhs.month && day == rhs.day)
        return true;

    return false;

}

/*
 * Description: Overloads the != operator for Date
 * Parameters: const Date & rhs
 * Return Type: bool
 */
bool Date::operator!=(const Date & rhs) {

    if (year != rhs.year || month != rhs.month || day != rhs.day)
        return true;

    return false;

}

/*
 * Description: Friend functoin that overloads the ostream operator << for Date
 * Parameters: ostream & os, const Date & obj
 * Return Type: ostream &
 */
ostream & operator<<(ostream & os, const Date & obj) {

    os << obj.month << "/" << obj.day << "/" << obj.year;

    return os;

}
