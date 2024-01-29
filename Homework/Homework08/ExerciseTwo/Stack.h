/*
 * Description: Templated stack class
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/06/2023
 * Date of Last Update: 11/06/2023
 */

#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Stack {

private:
    LinkedList<T> stack;

public:
    Stack();
    Stack(const Stack & obj);
    ~Stack();

    void displayStack(bool n1 = false) const;

    void clear();
    int size();
    void push(T);
    T pop();
    bool isEmpty();

    const Stack operator=(const Stack & rhs);
};

/*
 * Description: Default constructor for the Stack class
 * Parameters: None
 * Return Type: None
 */
template <class T>
Stack<T>::Stack() {


}

/*
 * Description: Copy constructor for the Stack class
 * Parameters: const Stack & obj
 * Return Type: Stack<T>
 */
template <class T>
Stack<T>::Stack(const Stack & obj) {

    stack = obj.stack;

}

/*
 * Description: Destructor for the Stack class
 * Parameters: None
 * Return Type: None
 */
template <class T>
Stack<T>::~Stack() {



}

/*
 * Description: display function to display our stack for Stack class
 * Parameters: bool n1
 * Return Type: None
 */
template <class T>
void Stack<T>::displayStack(bool n1) const {

    stack.displayList(n1);

}

/*
 * Description: clears out stack
 * Parameters: None
 * Return Type: None
 */
template <class T>
void Stack<T>::clear() {

    stack.clear();

}

/*
 * Description: returns the size for our stack
 * Parameters: None
 * Return Type: int
 */
template <class T>
int Stack<T>::size() {

    return stack.length();

}

/*
 * Description: pushes a new node onto the top of our stack
 * Parameters: T node
 * Return Type: None
 */
template <class T>
void Stack<T>::push(T node) {

    stack.push_back(node);

}

/*
 * Description: Pops the last element of the stack
 * Parameters: None
 * Return Type: T
 */
template <class T>
T Stack<T>::pop() {

    T tail = stack.peakTail();
    stack.deleteNode(stack.peakTail());
    return tail;

}

/*
 * Description: checks to see if the stack is empty
 * Parameters: None
 * Return Type: bool
 */
template <class T>
bool Stack<T>::isEmpty() {

    return !stack.length();

}

/*
 * Description: overloaded assignments operator for Stack class
 * Parameters: const Stack & rhs
 * Return Type: const Stack<T>
 */
template <class T>
const Stack<T> Stack<T>::operator=(const Stack & rhs) {

    stack = rhs.stack;
    return *this;

}

#endif // STACK_H
