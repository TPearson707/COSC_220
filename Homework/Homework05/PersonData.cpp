/*
 * Name: Thomas Pearson
 * Date of Creation: 10/11/2023
 * Date of Last Update: 10/12/2023
 */

#include "PersonData.h"

#include <iostream>

using namespace std;
// default constructor for PersonData
PersonData::PersonData() {
  
}

// virtual destructor for PersonData
PersonData::~PersonData() {
    
}

/*
 * Description: Prompts the user to input all the info for a PersonData Object
 * Parameters: None
 * Return Type: None
 */
void PersonData::setData() {

      cout << "Input Last Name: ";
      cin >> lastName;

      cout << "Input First Name: ";
      cin >> firstName;

      cout << "Input Street Address: ";
      cin.ignore();
      getline(cin, address, '\n');

      cout << "Input City: ";
      cin >> city;

      cout << "Input State: ";
     cin >> state;

      cout << "Input Zip Code: ";
      cin >> zip;

      cout << "Input Phone Number: ";
      cin >> phone;

}

/*
 * Description: Takes in two strings, first and last and sets firstName to first and sets lastName to last
 * Parameters: string first (firstName) string last(lastName)
 * return type: none
 */
void PersonData::setName(string first, string last) {
  
    firstName = first;
    lastName = last;
  
}

/*
 * Description: takes in 4 parameters a, c, s, z and sets address to a, sets city to c, sets state to s, and sets zip to z
 * Parameters: string a, string c, string s, string z
 * return type: none
 */
void PersonData::setAddress(string a, string c, string s, string z) {
  
    address = a;
    city = c;
    state = s;
    zip = z;
  
}

/*
 * Description: takes in a string and sets phone to that string
 * Parameters: string p (phone)
 * return type: none
 */
void PersonData::setPhone(string p) {
  
    phone = p;
  
}

/*
 * Description: returns firstName
 * Parameters: none
 * return type: string
 */
string PersonData::getFirstName() {
  
    return firstName;
  
}

/*
 * Description: return lastName
 * Parameters: none
 * return type: string
 */
string PersonData::getLastName() {
  
    return lastName;
  
}

/*
 * Description: returns address
 * Parameters: none
 * return type: string
 */
string PersonData::getAddress() {
  
    return address;
  
}

/*
 * Description: returns state
 * Parameters: none
 * return type: string
 */
string PersonData::getState() {
  
    return state;

}

/*
 * Description: returns city
 * Parameters: none
 * return type: string
 */
string PersonData::getCity() {
  
    return city;
  
}

/*
 * Description: returns zip
 * Parameters: none
 * return type: string
 */
string PersonData::getZip() {
  
    return zip;
  
}

/*
 * Description: returns phone number
 * Parameters: none
 * return type: string
 */
string PersonData::getPhone() {
  
    return phone;
  
}

/*
 * Description: returns a string called record that contains all the data 
 * for a person
 * Parameters: none 
 * return type: string 
 */
string PersonData::getRecord() {
  
    string record =  getFirstName() + " " + getLastName() + " / " + getAddress() + " / " + getCity() + ", " + getState() + " " + getZip() + " / " + getPhone();
    
    return record;
}

/*
 * Description: prints out all the data for a person
 * Parameters: none
 * return type: none
 */
void PersonData::PrintRecord() {
  
    cout << getLastName() << ", " << getFirstName() << endl;
    cout << getAddress() << endl;
    cout << getCity() << ", " << getState() << " " << getZip() << endl;
    cout << getPhone() << endl;
  
}
