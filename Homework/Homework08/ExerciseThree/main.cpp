/*
 * Description: Testing program for postfix expressions
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/08/2023
 * Date of Last Update: 11/08/2023
 */

#include <iostream>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

bool checkOperator(string);
template <class T> void calcAdd(double, stack<T> &);
template <class T> void calcSub(double, stack<T> &);
template <class T> void calcMult(double, stack<T> &);
template <class T> void calcDiv(double, stack<T> &);

int main() {

    string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    queue<string> tokens;
    stringstream inputstream(input);
    string token;

    stack<double> stacks;


    while (getline(inputstream, token, ' ')) {

        tokens.push(token);
        cout << tokens.back() << " ";
        cout << endl;
        double num;

        try {

            if (checkOperator(token)) {
                num = stacks.top();
                stacks.pop();

                if (token == "+")
                    calcAdd(num, stacks);
                if (token == "-")
                    calcSub(num, stacks);
                if (token == "*")
                    calcMult(num, stacks);
                if (token == "/")
                    calcDiv(num, stacks);



            } else {
                stacks.push(stod(token));
            }

        } catch (exception & e) {

            cout << "ERROR: Invalid character" << endl;

        } catch (string s) {

            cout << "ERROR: Empty List" << endl;

        }
    }

    try {

        while (!tokens.empty())
            tokens.pop();
    } catch (string s) {
        cout << s << endl;
    }

    cout << "Result: " << stacks.top() << endl;

    return 0;
}

/*
 * Description: Handles addition calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcAdd(double n, stack<T> & s) {

    double top = s.top();
    s.pop();
    s.push(n + top);

}

/*
 * Description: Handles subtraction calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcSub(double n, stack<T> & s) {

    double top = s.top();
    s.pop();
    s.push(top - n);

}

/*
 * Description: Handles multiplication calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcMult(double n, stack<T> & s) {

    double top = s.top();
    s.pop();
    s.push(n * top);


}

/*
 * Description: Handles division calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcDiv(double n, stack<T> & s) {

    double top = s.top();
    s.pop();
    s.push(top / n);


}

/*
 * Description: Checks whether the next token is an operator
 * Parameters: string token
 * Return Type: bool
 */
bool checkOperator(string token) {

    return token == "+" || token == "-" || token == "*" || token == "/";

}
