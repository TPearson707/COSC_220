/*
 * Description: Recursive program to check if a word is a palindrome
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/15/2023
 * Date of Last Update: 10/15/2023
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Description: Returns true if the inputed word is a palindrome, and false if the word is not a palindrome.
 * Parameters: const strin& str, int startIndex, int endIndex
 * Return Type: bool
 */
bool isPal(const string& str, int startIndex, int endIndex) {

    if (str[startIndex] != str[endIndex])
        return false;

    if (endIndex < startIndex)
        return true;

    return isPal(str, startIndex + 1, endIndex -1);
}

int main() {


    string pal = "atoyota";
    int start = 0;
    int end = pal.length() - 1;

    cout << "Is Palindrome: " << isPal(pal, start, end) << endl;



    return 0;

}
