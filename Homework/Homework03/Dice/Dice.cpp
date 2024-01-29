/*
    Name: thomas Pearson
    Date of Creation: 09/28/2023
    Date of Last Update: 09/28/2023
*/

#include <cstdlib>     // For rand and srand

#include "Dice.h"

using namespace std;

/*
    Description: Constructor
    Parameters: numSides - Number of sides to the die.
    Return: None
    Note: This implementation requires the RNG seed to be set in the main, or at
    least before this class is instantiated.
*/

Dice::Dice(int numSides) {
    // Set the number of sides.
    sides = numSides;

    // Perform an initial roll.
    roll();
}

/*
    Description: Roll function that will roll the die and store the value.
    Parameters: None
    Return: None
*/

void Dice::roll() {
    // Get a random value for the die.
    value = (rand() % sides) + MIN_VALUE;
}

/*
    Description: Accessor for the number of sides of the die.
    Parameters: None
    Return: Number of sides of the die.
*/

int Dice::getSides() const {
    return sides;
}

/*
    Description: Accessor for the value of the last roll.
    Parameters: None
    Return: Value of the last roll.
*/

int Dice::getValue() const {
    return value;
}
