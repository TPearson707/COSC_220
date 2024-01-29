/*
 * Name: Thomas Pearson
 * Date of Creation: 10/11/2023
 * Date of Last Update: 10/12/2023
 */

#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>

using namespace std;

class PersonData {
private:
    string lastName;
    string address;
    string state;
    string phone;
    string firstName;
    string city;
    string zip;
public:
    PersonData();
    virtual ~PersonData();

    virtual void setData();
    void setName(string, string);
    void setAddress(string, string, string, string);
    void setPhone(string);
    string getFirstName();
    string getLastName();
    string getAddress();
    string getState();
    string getCity();
    string getZip();
    string getPhone();
    virtual string getRecord();
    virtual void PrintRecord();
};

#endif
