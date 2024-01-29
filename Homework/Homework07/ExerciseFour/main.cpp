/*
 * Description: Testing program for shapes and linked list
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/27/2023
 * Date of Last Update: 10/27/2023
 */

#include <iostream>

#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Shape.h"
#include "LinkedList.h"

using namespace std;

void printArea(Shape &s);

int main() {
	int numObj;
	LinkedList<Shape*> list;

	cout << "Input the number of objects: ";
	cin >> numObj;

	int num;
	int sides = rand() % 11 + 5;
	for (int i = 0; i < numObj; i++) {

		num = rand() % 3;

		switch(num) {

			case 0:

				list.push_back(new Triangle(sides, sides, sides, "Red"));
				break;

			case 1:
				list.push_back(new Rectangle(sides, sides, "Red"));
				break;

			case 2:
				list.push_back(new Square(sides, "Red"));
				break;
		}

	}

	for (int i = 0; i < numObj; i++) {
		list[i]->draw();
	}

	return 0;
}

void printArea(Shape &s) {
	cout << "Area: " << s.Area() << endl;
}

