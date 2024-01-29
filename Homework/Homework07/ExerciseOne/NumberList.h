/*
 * Name: Lab06, Header for NumberList
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/19/2023
 * Date of Last Update: 10/19/2023
 */

// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList {
private:
	// Declare a structure for the list
	struct ListNode {
		double value;           // The value in this node
		struct ListNode *next;  // To point to the next node
	};

	ListNode *head;            // List head pointer

public:
	// Constructor
	NumberList() {
		head = nullptr;
	}

	// Destructor
	~NumberList();

	// Linked list operations
	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void deleteList();
	int length();
	void displayList() const;
};
#endif
