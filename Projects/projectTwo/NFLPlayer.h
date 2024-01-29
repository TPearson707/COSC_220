/*
 * Description: Header file for NFLPlayer class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#ifndef NFLPLAYER_H
#define NFLPLAYER_H

#include <string>

#include "Person.h"

using namespace std;

class NFLPlayer : public Person {
private:
    string positionCode;
    int playerNumber;
    string teamCode;
public:
    NFLPlayer();
    NFLPlayer(string, string, string, double, Date, string, int, string);

    virtual ~NFLPlayer();

    string getPositionCode() const;
    int getPlayerNumber() const;
    string getTeamCode() const;

    virtual string toString();
};

#endif // NFLPLAYER_H
