/*
 * Description: Testing program for postfix expressions
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/08/2023
 * Date of Last Update: 11/08/2023
 */

#include <iostream>
#include <sstream>

#include "Queue.h"
#include "Stack.h"


using namespace std;

bool checkOperator(string);
template <class T> void calcAdd(double, Stack<T> &);
template <class T> void calcSub(double, Stack<T> &);
template <class T> void calcMult(double, Stack<T> &);
template <class T> void calcDiv(double, Stack<T> &);

int main() {

    string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    Queue<string> tokens;
    stringstream inputstream(input);
    string token;

    Stack<double> stack;


    while (getline(inputstream, token, ' ')) {

        tokens.enqueue(token);
        double num;

        try {

            if (checkOperator(token)) {

                num = stack.pop();

                if (token == "+")
                    calcAdd(num, stack);
                if (token == "-")
                    calcSub(num, stack);
                if (token == "*")
                    calcMult(num, stack);
                if (token == "/")
                    calcDiv(num, stack);

            } else {

                stack.push(stod(token));

            }

        } catch (exception & e) {

            cout << "ERROR: Invalid character" << endl;

        } catch (string s) {

            cout << "ERROR: Empty List" << endl;

        }
    }

    tokens.displayQueue();
    cout << endl;
    try {

        while (!tokens.isEmpty())
            cout << tokens.dequeue() << endl;
    } catch (string s) {
        cout << s << endl;
    }

    stack.displayStack();
    cout << endl;
    return 0;
}

/*
 * Description: Handles addition calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcAdd(double n, Stack<T> & s) {

    s.push(n + s.pop());

}

/*
 * Description: Handles subtraction calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcSub(double n, Stack<T> & s) {

    s.push(s.pop() - n);

}

/*
 * Description: Handles multiplication calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcMult(double n, Stack<T> & s) {

    s.push(n * s.pop());

}

/*
 * Description: Handles division calculations
 * Parameters: double n, Stack <T> & s
 * Return Type: None
 */
template <class T> void calcDiv(double n, Stack<T> & s) {

    s.push(s.pop() / n);

}

/*
 * Description: Checks whether the next token is an operator
 * Parameters: string token
 * Return Type: bool
 */
bool checkOperator(string token) {

    return token == "+" || token == "-" || token == "*" || token == "/";

}
