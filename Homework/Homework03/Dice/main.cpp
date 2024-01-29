#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Array2D.h"
#include "Dice.h"

using namespace std;

int main() {
    srand(time(0));

    Array2D simulation;

    Dice die1;
    Dice die2;

    int numTrials, numRolls;

    cout << "Input the number of trials: ";
    cin >> numTrials;

    cout << "input the number of dice rolls per trial: ";
    cin >> numRolls;

    simulation.resize(numTrials, numRolls, 0);
    for (int i = 0; i < numTrials; i++) {
        for (int j = 0; j < numRolls; j++) {
            die1.roll();
            die2.roll();

            simulation.set(i, j, (die1.getValue() + die2.getValue()));
        }
    }

    int numSame = simulation.checkSame();

    cout << "Number of trials resulting in same roll value was " << numSame << "." << endl;
    simulation.display(5);

    return 0;
}
