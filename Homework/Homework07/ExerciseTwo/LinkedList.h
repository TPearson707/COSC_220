/*
 * Description: Templated Link List Class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/25/2023
 * Date of Last Update: 10/27/2023
 */

// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************

template<class T>
class ListNode {
public:
	T value;           // Node value
	ListNode<T> *next; // Pointer to the next node

	// Constructor
	ListNode(T nodeValue) {
		value = nodeValue;
		next = nullptr;
	}
};

//*********************************************
// LinkedList class                           *
//*********************************************

template<class T>
class LinkedList {
private:
	ListNode<T> *head;   // List head pointer
	ListNode<T> *tail;   // List tail pointer
public:
	// constructor
	LinkedList();
	// copy constructor
	LinkedList(const LinkedList &);
	// Destructor
	~LinkedList();

	// Linked list operations
	void push_back(T);
	void push_front(T);
	T pop_front();
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
	void clear();
	int length();
	void set(int, T);
	T get(int);
	T peakHead();
	T peakTail();

	LinkedList<T> & operator=(const LinkedList &);
	T & operator[](int);
};


// Constructor

template<class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

/*
 * Description: Copy Constructor to copy another linked list upon creation of an object
 * Parameters: const LinkedList & newList
 * Return Type: LinkedList<T>
 */
template<class T>
LinkedList<T>::LinkedList(const LinkedList & newList) {

	if (head != nullptr)
		clear();

	head = nullptr;
	tail = nullptr;

	ListNode<T> *newNode;
	newNode = newList.head;

	while (newNode) {
		push_back(newNode->value);
		newNode = newNode->next;
	}
}

/*
 * Description: Pushes a new element to the front of the list
 * Parameters: T newValue
 * Return Type: None
 */
template<class T>
void LinkedList<T>::push_front(T newValue) {
	ListNode<T> *newNode;
	ListNode<T> *nodePtr;
	newNode = new ListNode<T>(newValue);

	if (!head) {
		head = newNode;
		tail = newNode;
		return;
	}

	nodePtr = head;
	head = newNode;
	head->next = nodePtr;
}

/*
 * Description: Pushes a new value to the back of the list
 * Parameters: T newValue
 * Return Type: None
 */

template<class T>
void LinkedList<T>::push_back(T newValue) {
	ListNode<T> *newNode;  // To point to a new node
	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head){
		head = newNode;
		tail = newNode;
		return;
	}

	if(tail->next)
		while (tail->next)
			tail = tail->next;

	tail->next = newNode;
	tail = tail->next;

}

/*
 * Description: Pops a node from the front of the list
 * Parameters: None
 * Return Type: T
 */
template<class T>
T LinkedList<T>::pop_front() {
	T val;
	string error;
	if (!head) {
		error = "Empty List Exception";
		throw error;
	}

	val = head->value;
	deleteNode(val);
	return val;

}
//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************

template<class T>
void LinkedList<T>::displayList() const {
	ListNode<T> *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr) {
		// Display the value in this node.
		cout << nodePtr->value << " ";

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template<class T>
void LinkedList<T>::insertNode(T newValue) {
	ListNode<T> *newNode;				// A new node
	ListNode<T> *nodePtr;				// To traverse the list
	ListNode<T> *previousNode = nullptr; // The previous node

	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node
	if (!head) {
		head = newNode;
		tail = newNode;
		newNode->next = nullptr;
	} else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than newValue.
		while (nodePtr != nullptr && nodePtr->value < newValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
			tail = newNode;
		} else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
			tail = newNode;
		}
	}

	if (tail->next != nullptr)
		while(tail->next != nullptr)
			tail = tail->next;
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template<class T>
void LinkedList<T>::deleteNode(T searchValue) {

	ListNode<T> *nodePtr;       // To traverse the list
	ListNode<T> *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == searchValue) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != searchValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
			tail = previousNode;
		}
	}

	if (tail->next)
		while(tail->next)
			tail = tail->next;

}

/*
 * Description: Clears a linked list of nodes
 * Parameters: None
 * Return Type: None
 */
template<class T>
void LinkedList<T>::clear() {

	ListNode<T> *nodePtr; // To traverse the list
	ListNode<T> *last; // To free memory of the current node
	nodePtr = head;
	while (nodePtr) {

		last = nodePtr;
		nodePtr = nodePtr->next;
		delete last;

	}

	head = nullptr;
	tail = nullptr;

}

/*
 * Description: Finds the length of a linked list and returns an integer of the length
 * Parameters: None
 * Return Type: None
 */
template<class T>
int LinkedList<T>::length() {

	int counter = 0;
	ListNode<T> *nodePtr; // To traverse the list

	nodePtr = head;

	while (nodePtr->next) {
		nodePtr = nodePtr->next;
		counter++;
	}

	counter++;
	return counter;

}

/*
 * Description: Sets a specific index of the linked list to a value T
 * Parameters: int index T value
 * Return Type: None
 */
template<class T>
void LinkedList<T>::set(int index, T value) {

	if (!head) {

		string error;
		error = "Empty List Exception";
		throw error;

	}

	if (index < 0 || index >= length()) {

		string error;
		error = "Index Out of Bounds Exception";
		throw error;

	}

	ListNode<T> *nodePtr;

	nodePtr = head;

	for (int i = 0; i < index; i++) {
		nodePtr = nodePtr->next;
	}

	nodePtr->value = value;

}

/*
 * Description: Finds a specific index of a linked list and returns the value of that index
 * Parameters: int index
 * Return Type: T
 */
template<class T>
T LinkedList<T>::get(int index) {

	if (!head) {

		string error;
		error = "Empty List Exception";
		throw error;

	}

	if (index < 0 || index >= length()) {

		string error;
		error = "Index Out of Bounds Exception";
		throw error;

	}

	ListNode<T> *nodePtr;

	nodePtr = head;

	for (int i = 0; i < index; i++) {
		nodePtr = nodePtr->next;
	}

	return nodePtr->value;

}

/*
 * Description: Returns the value of head
 * Parameters: None
 * Return Type: T
 */
template<class T>
T LinkedList<T>::peakHead() {

	string s = "Null pointer exception.";

	if (head)
		return head->value;
	else
		throw s;

}

/*
 * Description: Returns the value of tail
 * Parameters: None
 * Return Type: T
 */
template<class T>
T LinkedList<T>::peakTail() {

	string s = "Null pointer exception.";

	if (tail)
		return tail->value;
	else
		throw s;

}
//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

/*
 * Description: Destructor for the linked list class
 * Parameters: None
 * Return Type: None
 */
template<class T>
LinkedList<T>::~LinkedList() {
	ListNode<T> *nodePtr;   // To traverse the list
	ListNode<T> *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

/*
 * Description: = operator overload for the linked list class allow LinkedList<T> = LinkedList<T>
 * Parameters: const LinkedList & newList
 * Return Type: LinkedList<T> &
 */
template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList & newList) {

	if (head != nullptr)
		clear();
	head = nullptr;
	tail = nullptr;

	ListNode<T> *newNode;
	newNode = newList.head;

	while (newNode) {
		push_back(newNode->value);
		newNode = newNode->next;
	}

	return *this;

}

/*
 * Description: [] operator overload for the linked list class
 * Parameters: int index
 * Return Type: T&
 */
template<class T>
T & LinkedList<T>::operator[](int index) {
	if (!head) {

		string error;
		error = "Empty List Exception";
		throw error;

	}

	if (index < 0 || index >= length()) {

		string error;
		error = "Index Out of Bounds Exception";
		throw error;

	}

	ListNode<T> *nodePtr = head;
	int counter = 0;

	while (nodePtr->next) {
		if (counter == index) {
			return nodePtr->value;
		}
		nodePtr = nodePtr->next;
		counter++;
	}
}

#endif
