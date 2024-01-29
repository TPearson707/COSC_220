/*
 * Description: Header file for NBAPlayer class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#ifndef NBAPLAYER_H
#define NBAPLAYER_H

#include <string>
#include "Person.h"

class NBAPlayer : public Person {

private:

    string positionCode;
    int playerNumber;

public:

    NBAPlayer();
    NBAPlayer(string, string, FeetInches, double, Date, string, int);

    virtual ~NBAPlayer();

    string getPositionCode() const;
    int getPlayerNumber() const;
    virtual string toString();


};

#endif // NBAPLAYER_H
