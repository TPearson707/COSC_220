/*
 * Name: Thomas Pearson
 * Date of Creation: 10/11/2023
 * Date of Last Update: 10/12/2023
 */
#include <iostream>
#include <cstdlib>
#include "CustomerData.h"

using namespace std;

// default constructor for CustomerData
CustomerData::CustomerData() {
  
}

// virtual destructor for PersonData
CustomerData::~CustomerData() {
    
}

/*
 * Description: Prompts the user to input all the info for a CustomerData Object
 * Parameters: None
 * Return Type: None
 */

void CustomerData::setData() {
    char mailingList;
    int intput;
    bool validNum = false;
    PersonData::setData();

    do {

      try {

        cout << "Input Customer Number: ";
        cin >> customerNumber;

        intput = stoi(customerNumber);


        validNum = true;

      } catch(exception) {
          cout << "Error: The chosen input is a not an integer value, please enter an integer." << endl;
          cin.clear();
          cin.ignore();
      }

    } while (validNum == false);

    do {
        try {

          cout << "Do they wish to be on the mailing list [Y/N]: ";
          cin >> mailingList;

        } catch (exception) {
          cout << "Error: not a valid character was entered please enter y or n" << endl;
          cin.clear();
          cin.ignore();
        }
    
    } while (tolower(mailingList) != 'y' && tolower(mailingList) != 'n');

    switch (tolower(mailingList)) {
        case 'y':
            mailingList = true;
            break;
        case 'n':
            mailingList = false;
            break;
    }
}
/*
 * Description: takes in an intger and sets customer number to that integer
 * Parameters: int cn (customer number)
 * return type: none
 */
void CustomerData::setCustomerNumber(int cn) {
  
    customerNumber = cn;
  
}

/*
 * Description: takes in a boolean value and sets mailing list to that value
 * Parameters: bool ml (mailing list)
 * return type: none
 */
void CustomerData::setMailingList(bool ml) {
  
    mailingList = ml;
  
}

/*
 * Description: returns a string called result that contains all the data
 * for a customer
 * Parameters: none 
 * return type: string 
 */
string CustomerData::getRecord() {

    string result = PersonData::getRecord();

    
    result += "/ c#: " + customerNumber + " / ";

    if (mailingList)
      result += "ML: Yes";
    else
      result += "ML: No";
    return result;
  
}

/*
 * Description: prints out all the data for a customer
 * Parameters: none
 * return type: none
 */
void CustomerData::PrintRecord() {
  
    PersonData::PrintRecord();

    cout << "Customer Number: " << customerNumber << endl;
    if (mailingList)
      cout << "On the Mailing List: Yes" << endl;
    else
      cout << "On the Mailing List: No" << endl;
  
}
