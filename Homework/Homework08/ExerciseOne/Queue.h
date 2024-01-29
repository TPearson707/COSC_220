/*
 * Description: Templated queue class
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/06/2023
 * Date of Last Update: 11/06/2023
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Queue {
private:
    LinkedList<T> queue;

public:
    Queue();
    ~Queue();
    Queue(const Queue & obj);

    void displayQueue(bool n1 = false) const;

    void clear();
    int size();
    void enqueue(T);
    T dequeue();
    bool isEmpty();

    const Queue operator=(const Queue & rhs);

};

/*
 * Description: Default constructor for queue class
 * Parameters: None
 * Return Type: None
 */
template <class T>
Queue<T>::Queue() {



}

/*
 * Description: Destructor for Queue class
 * Parameters: None
 * Return Type: None
 */
template <class T>
Queue<T>::~Queue() {



}

/*
 * Description: Copy constructor for Queue class
 * Parameters: const Queue & obj
 * Return Type: Queue<T>
 */
template <class T>
Queue<T>::Queue(const Queue & obj) {

    queue = obj.queue;

}

/*
 * Description: Displays the queue
 * Parameters: bool n1
 * Return Type: None
 */
template <class T>
void Queue<T>::displayQueue(bool n1) const {

    queue.displayList(n1);

}

/*
 * Description: clears out queue
 * Parameters: None
 * Return Type: None
 */
template <class T>
void Queue<T>::clear() {

    queue.clear();

}

/*
 * Description: Returns the size of the queue
 * Parameters: None
 * Return Type: int
 */
template <class T>
int Queue<T>::size() {

    return queue.length();

}

/*
 * Description: Queues up a new node in our queue
 * Parameters: T node
 * Return Type: None
 */
template <class T>
void Queue<T>::enqueue(T node) {

    queue.push_back(node);

}

/*
 * Description: Deletes the first item from our queue
 * Parameters: None
 * Return Type: T
 */
template <class T>
T Queue<T>::dequeue() {

    return queue.pop_front();

}

/*
 * Description: Checks to see if the queue is empty
 * Parameters: None
 * Return Type: bool
 */
template <class T>
bool Queue<T>::isEmpty() {

    return !queue.length();

}

/*
 * Description: Overloaded assignment operator for Queue class
 * Parameters: const Queue & rhs
 * Return Type: const Queue<T>
 */
template <class T>
const Queue<T> Queue<T>::operator=(const Queue  & rhs) {

    queue = rhs.queue;
    return *this;

}

#endif // QUEUE_H
