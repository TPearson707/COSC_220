/*
 * Name: Thomas Pearson
 * Date of Creation: 10/11/2023
 * Date of Last Update: 10/12/2023
 */

#include <iostream>
#include <iomanip>

#include "PreferredCustomer.h"

using namespace std;

PreferredCustomer::PreferredCustomer() {
  
}

PreferredCustomer::~PreferredCustomer() {
  
}

/*
 * Description: Prompts the user to input all the info for a PreferredCustomer Object
 * Parameters: None
 * Return Type: None
 */
void PreferredCustomer::setData() {
    string purchases;
    double pa;
    bool validPurchase = false;
    CustomerData::setData();

    do {
        try {

            cout << "Input Purchases Amount: ";
            cin >> purchases;
            pa = stoi(purchases);

            if (pa < 0) {

                cout << endl << "Error: Invalid Input, please enter a positive integer value" << endl << endl;
                continue;

            }

            setPurchases(pa);
            validPurchase = true;

        } catch (exception) {
            cout << endl << "Error: Invalid Input, please enter an integer value" << endl << endl;
        }

    } while (validPurchase == false);
}

/*
 * Description: Setter function for purchasesAmount
 * Parameters: double numPurchases
 * Return Type: None
 */
void PreferredCustomer::setPurchases(double numPurchases) {

    purchasesAmount = numPurchases;
    setDiscount();
  
}

/*
 * Description: Sets the discount rate for a PreferredCustomer object based on how much they have purchased
 * Parameters: None
 * Return Type: None
 */
void PreferredCustomer::setDiscount() {

    if (purchasesAmount >= 500 && purchasesAmount < 1000) {
        
        discountLevel = 5;
      
    } else if (purchasesAmount >= 1000 && purchasesAmount < 1500) {
      
        discountLevel = 6;
    
    } else if (purchasesAmount >= 1500 && purchasesAmount < 2000) {
      
      discountLevel = 7;
      
    } else if (purchasesAmount >= 2000) {
      
      discountLevel = 10;
      
    } else {

        discountLevel = 0;

    }
  
}

/*
 * Description: Getter function for purchasesAmount
 * Parameters: None
 * Return Type: double
 */
double PreferredCustomer::getPurchases() {
    return purchasesAmount;
}

/*
 * Description: Getter function for discountLevel
 * Parameters: None
 * Return Type: double
 */
double PreferredCustomer::getDiscount() {
    return discountLevel;
}


/*
 * Description: returns a string called record that contains all the data
 * for a customer
 * Parameters: none
 * return type: string
 */
string PreferredCustomer::getRecord() {
    string result = CustomerData::getRecord();

    result += "/ Account: $" + to_string(purchasesAmount) + " / Discount: " + to_string(static_cast<int>(discountLevel)) + "%";

    return result;
}

/*
 * Description: prints out all the data for a PreferredCustomer object
 * Parameters: none
 * return type: none
 */
void PreferredCustomer::PrintRecord() {
    CustomerData::PrintRecord();

    cout << "Purchases Amount: " << static_cast<int>(purchasesAmount) << endl;
    cout << "Discount Level: " << discountLevel << "%" << endl;
}

