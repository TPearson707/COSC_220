/*
 * Description: Testing program for postfix expressions
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/08/2023
 * Date of Last Update: 11/08/2023
 */

#include <iostream>
#include <sstream>
#include <stack>


using namespace std;

bool checkLeftDelim(char);
bool checkRightDelim(char);

int main() {

    string input;
    cout << "Enter a expression: ";
    getline(cin, input);

    stringstream inputstream(input);
    string token;

    stack<char> stacks;

   for(size_t i = 0; i < input.length(); i++) {

        char token = input.at(i);

            if (checkLeftDelim(token)) {

                stacks.push(token);

            } else if(checkRightDelim(token)) {

                if (!((token == '}' && stacks.top() == '{') || (token == ')' && stacks.top() == '(') || (token == ']' && stacks.top() == '['))) {

                    cout << "Delimiters are not balanced" << endl;
                    exit(0);

                } else {

                    stacks.pop();

                }
            }

    }

    cout << "Delimiters are balanced" << endl;

    return 0;
}

/*
 * Description: Checks whether the next token is a left side delimiter
 * Parameters: string token
 * Return Type: bool
 */
bool checkLeftDelim(char token) {

    return token == '{' || token == '(' || token == '[';

}

/*
 * Description: Checks whether the next token is a right side delimiter
 * Parameters: string token
 * Return Type: bool
 */
bool checkRightDelim(char token) {

    return token == '}' || token == ')' || token == ']';

}
