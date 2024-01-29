/*
 * Name: Homework06 Exercise 3 Dice: Dice.cpp
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/19/2023
 * Data of Last Update: 10/19/2023
 */

#include <cstdlib>     // For rand and srand

#include "Dice.h"

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

Dice::~Dice() {

}

/*
    Description: Roll function that will roll the die and store the value.
    Parameters: None
    Return: None
*/

void Dice::roll() {
    // Get a random value for the die.
    value = (rand() % sides) + 1;
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

/*
 * Overloads the equivalence operator == for dice class so we can check if dice rolls are equal
 * Parameters: const Dice & die
 * Return type: bool
 */
bool Dice::operator==(const Dice & die) {

    if (value == die.getValue())
        return true;

    return false;

}

/*
 * Description: Overloads the not equivalent operator != for dice class so we can check if dice rolls are not equal
 * Parameters: const Dice & die
 * Return Type: bool
 */
bool Dice::operator!=(const Dice & die) {

    if (value != die.getValue())
        return true;

    return false;

}

/*
 * Description: Overloads the output stream operator so we can print dice values with cout << Dice
 * Parameters: ostream & os, const Dice & die
 * Return Type: ostream &
 */
ostream & operator<<(ostream & os, const Dice & die) {
    os << die.value;

    return os;
}
