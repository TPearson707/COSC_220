/*
    Name: thomas Pearson
    Date of Creation: 09/28/2023
    Date of Last Update: 09/28/2023
*/

#ifndef DICE_H
#define DICE_H

class Dice {
  private:
    int sides;   // Number of sides
    int value;   // The die's value

    const int MIN_VALUE = 1;   // Minimum die value

  public:
    Dice(int numSides = 6);        // Constructor
    void roll();     // Rolls the die
    int getSides() const;  // Returns the number of sides
    int getValue() const;  // Returns the die's value
};
#endif
