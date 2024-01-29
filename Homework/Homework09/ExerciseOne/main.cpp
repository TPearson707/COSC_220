/*
 * Description: Recursive program to find combinations
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/15/2023
 * Date of Last Update: 10/15/2023
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Description: Returns the vlaue of n choose k
 * Parameters: int n, int k
 * Return Type: int
 */
int choose(int n, int k) {

    if (n == 0 || k == 0 || n == k) // base case
        return 1;

    if (n < 0 || k < 0 || k > n) // base case
        return 0;

    return choose(n - 1, k) + choose(n - 1, k - 1);

}

int main() {

    int n, k;

    cout << "Enter n and k (integer) with a space between them: ";
    cin >> n >> k;

    int sum = choose(n, k);

    cout << n << " choose " << k << " = " << sum << endl;

    return 0;

}
