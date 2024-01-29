/*
 * Description: Recursive program to find combinations
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/16/2023
 * Date of Last Update: 10/16/2023
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Description: Checks to see if a queen placement is safe
 * Parameters: int row, int col, const vector<int> &queenList
 * Return Type: bool
 */
bool safeLocation(int row, int col, const vector<int> &queenList) {

    for (int qCol = 0; qCol < col; qCol++) {

        int qRow = queenList[qCol];

        if (qRow == row)
            return false;
        else if (qCol == col)
            return false;
        else if (qCol - qRow == col - row || qCol + qRow == col + row)
            return false;
    }

    return true;

}

/*
 * Descriptions: Utilizes backtracking to find all possible solutions for a queens starting row
 * Parameters: vector<int> &queenList, int col, int &numSolves
 * Return Type: bool
 */
bool placeQueens(vector<int> &queenList, int col, int &numSolves) {

    int row;
    bool validPlacements = false;

    if (col == 8) {
        for (unsigned int i = 0; i < queenList.size(); i++)
            cout << queenList[i] << " ";

        cout << endl;
        numSolves++;

    }

        for (row = 0; row < 8; row++) {

            if (safeLocation(row, col, queenList)) {

                queenList[col] = row;
                validPlacements = placeQueens(queenList, col + 1, numSolves);

            }
        }

    return validPlacements;

}

int main() {

    int row;
    int numSolves = 0;

    cout << "Enter row for queen in column 0: ";
    cin >> row;

    if (row < 0 || row > 7) {
        cout << "invalid row please pick from 0 - 7" << endl;
        exit(1);
    }

    vector<int> queenList(8);
    queenList[0] = row;

    if (placeQueens(queenList, 1, numSolves));

    cout << "Number of solutions: " << numSolves << endl;

    return 0;

}
