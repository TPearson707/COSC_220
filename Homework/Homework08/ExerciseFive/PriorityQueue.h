/*
 * Description: PriorityQueue Templated Class
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/10/2023
 * Date of Last Update: 11/10/2023
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

// Node data type that holds the data and priority of the item.

template <class T>
class PQNode {
public:
    T data;
    int priority;

    PQNode(T Data) {
        data = Data;
        priority = 1;
    }

    PQNode(T Data, int Priority) {
        data = Data;
        if (Priority < 1)
            Priority = 1;

        priority = Priority;
    }
};

template <class T>
class PriorityQueue {
private:
    vector<PQNode<T> > queue; // The vector holding all of the items in the queue.

public:
    // Constructors and Destructor
    PriorityQueue();
    PriorityQueue(const PriorityQueue & obj);
    ~PriorityQueue();

    // Acessors and Mutators
    void enqueue(T Data, int priority = 1);
    T dequeue();

    // Other Functions
    void print();
    bool isEmpty();
    void clear();
    int size();

    PriorityQueue<T> operator=(const PriorityQueue & obj);
};

/*
 * Description: Default constructor for PriorityQueue class
 * Parameters: None
 * Return Type: None
 */
template <class T>
PriorityQueue<T>::PriorityQueue() {}

/*
 * Description: Copy constructor for PriorityQueue class
 * Parameters: const PriorityQueue & obj
 * Return Type: None
 */
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue & obj) {

    for (size_t i = 0; i < obj.queue.size(); i++) {

        queue.push_back(obj[i]);

    }


}

/*
 * Description: Destructor for PriorityQueue class
 * Parameters: None
 * Return Type: None
 */
template <class T>
PriorityQueue<T>::~PriorityQueue() {}

/*
 * Description: pushes a new node onto the next spot of the queue
 * Parameters: T Data, int priority
 * Return Type: None
 */
template <class T>
void PriorityQueue<T>::enqueue(T Data, int priority) {

    PQNode<T> node(Data, priority);
    queue.push_back(node);

}

/*
 * Description: Dequeue's the the first element of the highest priority from the queue if the queue is empty it will return garbage
 * Parameters: None
 * Return Type: T
 */
template <class T>
T PriorityQueue<T>::dequeue() {

    T value;

    if (queue.size() == 0)
        return value;

    int prio = 1;
    size_t index = 0;
    value = queue[0].data;

    for (size_t i = 0; i < queue.size(); i++) {
        if (queue[i].priority > prio) {
            prio = queue[i].priority;
            index = i;
            value = queue[i].data;
        }
    }

    queue.erase(queue.begin() + index);

    return value;

}

/*
 * Description: Prints out the queue
 * Parameters: None
 * Return Type: None
 */
template <class T>
void PriorityQueue<T>::print() {

    for (size_t i = 0; i < queue.size(); i++)
        cout << queue[i].data << " --- " << queue[i].priority << endl;


}

/*
 * Description: Checks to see if the queue is Empty
 * Parameters: None
 * Return Type: bool
 */
template <class T>
bool PriorityQueue<T>::isEmpty() {

    return queue.empty();

}

/*
 * Description: Clears out the queue
 * Parameters: None
 * Return Type: None
 */
template <class T>
void PriorityQueue<T>::clear() {

    queue.clear();

}

/*
 * Description: returns the size of our queue
 * Parameters: None
 * Return Type: int
 */
template <class T>
int PriorityQueue<T>::size() {

    return queue.size();

}

/*
 * Description: overloaded assignment operator for PriorityQueue
 * Parameters: const PriorityQueue & obj
 * Return Type: PriorityQueue<T>
 */
template <class T>
PriorityQueue<T> PriorityQueue<T>::operator=(const PriorityQueue & obj) {

    for (int i = 0; i < obj.queue.size(); i++) {

        queue.push_back(obj[i]);

    }

    return *this;

}

#endif // PRIORITYQUEUE_H
