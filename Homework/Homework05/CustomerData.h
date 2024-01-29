/*
 * Name: Thomas Pearson
 * Date of Creation: 10/11/2023
 * Date of Last Update: 10/12/2023
 */

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData {
private:
    std::string customerNumber;
    bool mailingList;
public:
    CustomerData();
    virtual ~CustomerData();

    virtual void setData();
    void setCustomerNumber(int);
    void setMailingList(bool);
    virtual string getRecord();
    virtual void PrintRecord();
};

#endif
