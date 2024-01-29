/*
 * Name: Thomas Pearson
 * Date of Creation: 10/11/2023
 * Date of Last Update: 10/12/2023
 */

#include "CustomerData.h"

class PreferredCustomer : public CustomerData {
private:
    double purchasesAmount;
    double discountLevel;
public:
    PreferredCustomer();
    virtual ~PreferredCustomer();

    virtual void setData();
    void setPurchases(double);
    void setDiscount();
    double getPurchases();
    double getDiscount();
    virtual string getRecord();
    virtual void PrintRecord();
};
