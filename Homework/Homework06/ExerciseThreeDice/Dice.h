/*
 * Name: Homework06 Exercise 3 Dice: Dice.h
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/19/2023
 * Data of Last Update: 10/19/2023
 */
#ifndef DICE_H
#define DICE_H

#include <iostream>

#include "Dice.h"

using namespace std;

class Dice {
  private:
    int sides;   // Number of sides
    int value;   // The die's value

  public:
    Dice(int numSides = 6);        // Constructor
    ~Dice();
    void roll();     // Rolls the die
    int getSides() const;  // Returns the number of sides
    int getValue() const;  // Returns the die's value

    bool operator==(const Dice &);
    bool operator!=(const Dice &);

    friend ostream & operator<<(ostream &, const Dice &);
};
#endif
