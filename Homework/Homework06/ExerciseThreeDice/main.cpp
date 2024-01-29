/*
 * Name: Homework06 Exercise 3 Dice: main.cpp
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/19/2023
 * Data of Last Update: 10/19/2023
 */

#include <iostream>
#include <cstdlib>

#include "Array2D.hpp"
#include "Dice.h"

using namespace std;

bool checkDisplay(char);

int main() {
    srand(time(0));

    int numTrials, numRolls;
    bool displayArray;

    Dice die;

    cout << "Input the number of trials: ";
    cin >> numTrials;

    cout << "Input the number of dice for each trial: ";
    cin >> numRolls;

    Array2D simulation(numTrials, numRolls, die);

    for (int i = 0; i < simulation.getRows(); i++) {
        for (int j = 0; j < simulation.getCols(); j++) {

            simulation.set(i, j, die);
            simulation[i][j].roll();

        }
    }

    char displayArraySelect;
    cout << "Do you want to display the array (Y/N): ";
    cin >> displayArraySelect;

    displayArray = checkDisplay(displayArraySelect);

    if (displayArray)
        simulation.display(5);

    int numSame = simulation.checkSame();

    cout << "There were " << numSame << " matches of equal die in the " << numTrials << " trials of the simulation." << endl;



    return 0;
}

/*
 * Description: validates if the array should be printed based on user input
 * Parameters: char x
 * Return Type: bool
 */
bool checkDisplay(char x) {

    if (tolower(x) == 'y')
        return true;
    else if (tolower(x) == 'n')
        return false;

    cout << "Invalid value, must be y or n." << endl;
    exit(1);

}
