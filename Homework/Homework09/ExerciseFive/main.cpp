/*
 * Description: Recursive program to find combinations
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/17/2023
 * Date of Last Update: 10/17/2023
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Description: Utilizes backtracking to recursively permute a vector
 * Parameters: vector <int> &permList, unsigned int index
 * Return Type: None
 */
void permute(vector<int> &permList, unsigned int index) {

    if (index == permList.size()) {

        for (unsigned int i = 0; i < permList.size(); i++)
            cout << permList[i] << " ";

        cout << endl;

        return;

    }

    for (unsigned int i = index; i < permList.size(); i++) {

        swap(permList[index], permList[i]);
        permute(permList, index + 1);
        swap(permList[index], permList[i]);

    }

}

int main() {

    int pSize;

    cout << "Enter the size of the permutation list: ";
    cin >> pSize;

    if (pSize < 1) {
        cout << "Error: invalid size please enter an integer greater than 0" << endl;
        exit(1);
    }

    vector<int> permList;

    for (int i = 1; i <= pSize; i++) {
        permList.push_back(i);
    }

    permute(permList, 0);

    return 0;
}
