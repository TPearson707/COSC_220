/*
 * Name: Thomas Pearson
 * Date of Creation: 10/11/2023
 * Date of Last Update: 10/12/2023
 */

#include <iostream>
#include <iomanip>

#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

void validateSelection(int);
void menuAction(int, PersonData* database[], int &);
void PrintMenu();

int main() {
    int size = 10; // size of database
    int databaseSize = 0; // num objects in database
    string input;
    int selection;

    PersonData* database[size];

    do {
        PrintMenu();
        try {
            cin >> input;
            cout << endl;
            selection = stoi(input);
        
        } catch (exception) {
            cout << endl << "Error: Invalid Input, selection must be an integer between 1 and 6" << endl << endl;
            cin.clear();
            continue;
        }
        
        menuAction(selection, database, databaseSize);
    } while (selection != 6);
        
    return 0;
}

/*
 * Description: takes in the selection from the user, and handles accordingly. If the database is full for commands 1 - 3 the program tells the * * * user the database is full, and returns nothing, if the database is empty for commands 4 - 5 the program tells the user the database is empty and * returns nothing.
 * Parameters: int selectoin, PersonData* database[], int &databaseSize
 * Return Type: None
 */
void menuAction(int selection, PersonData* database[], int &databaseSize) {
  
    switch(selection) {
      
        case 1:

            if (databaseSize > 9) {
                cout << "Error: Cannot add PersonData, the database is full." << endl << endl;
                return;
            }

            database[databaseSize] = new PersonData;
            database[databaseSize] -> setData();
            databaseSize++;
            break;

        case 2:

            if (databaseSize > 9) {
                cout << "Error: Cannot add CustomerData, the database is full." << endl << endl;
                return;
            }

            database[databaseSize] = new CustomerData;
            database[databaseSize] -> setData();
            databaseSize++;
            break;

        case 3:

            if (databaseSize > 9) {
                cout << "Error: Cannot add PreferredCustomerData, the database is full." << endl << endl;
                return;
            }

            database[databaseSize] = new PreferredCustomer;
            database[databaseSize] -> setData();
            databaseSize++;
            break;

        case 4: 

            if (databaseSize == 0) {
                cout << "Error: Cannot print record, the database is empty." << endl << endl;
                return;
            }
            for (int i = 0; i < databaseSize; i++) {
                database[i] -> PrintRecord();
                cout << endl;
            }
            break;

        case 5:

            if (databaseSize == 0) {
                cout << "Error: Cannot print record, the database is empty." << endl << endl;
                return;
            }

            for (int i = 0; i < databaseSize; i++)
                cout << database[i] -> getRecord() << endl;
            cout << endl;
            break;

    }
  
}

/*
 * Description: Prints out the menu for the user
 * Parameters: None
 * Return Type: None
 */
void PrintMenu() {
    cout << "1. Add Personal Data Object" << endl;
    cout << "2. Add Customer Data Object" << endl;
    cout << "3. Add Preferred Customer Data Object" << endl;
    cout << "4. View Database Long Form" << endl;
    cout << "5. View Database Short Form" << endl;
    cout << "6. Quit" << endl;
    cout << "Choice: ";
}
