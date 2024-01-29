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
 * Description: Utilizes backtracking to recursively find all possible placements on an n X n chessboard
 * Parameters: vector <int> &queenList, int col, int n, int & numSolves
 * Returns Type: bool
 */
bool placeQueens(vector<int> &queenList, int col, int n, int &numSolves) {

    int row;
    bool validPlacements = false;

    if (col == n) {
        for (unsigned int i = 0; i < queenList.size(); i++)
            cout << queenList[i] << " ";

        cout << endl;
        numSolves++;

    }

        for (row = 0; row < n; row++) {

            if (safeLocation(row, col, queenList)) {

                queenList[col] = row;
                validPlacements = placeQueens(queenList, col + 1, n, numSolves);

            }

        }

    return validPlacements;

}

int main() {

    int n;
    int numSolves = 0;

    cout << "Input the board size n X n. n = ";
    cin >> n;

    if (n < 0) {

        cout << "Invalid board size! Please enter a positive integer." << endl;
        exit(1);

    }

    vector<int> queenList(n);

    if (placeQueens(queenList, 0, n, numSolves));

    cout << "Number of solutions: " << numSolves << endl;

    return 0;

}

