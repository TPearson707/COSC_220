/*
 * Description: main.cpp file for homework #7
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/27/2023
 * Date of Last Update: 10/27/2023
 */

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include "LinkedList.h"

using namespace std;
using namespace std::chrono;

int main() {

    srand(time(0));

    int numData;

    LinkedList<int> linkedList;
    vector<int> vectList;
    list<int> list;

    cout << "Input the number of values to store: ";
    cin >> numData;

    int num;

    auto start = high_resolution_clock::now();

    for(int i = 0; i < numData; i++) {
        num = rand() % 10 + 1;
        linkedList.push_front(num);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to push_front with linked list: " << duration.count() / 1000000.0
    << " seconds" << endl;

    start = high_resolution_clock::now();


    for (int i = 0; i < numData; i++) {
        num = rand() % 10 + 1;
        vectList.insert(vectList.begin(), num);
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to push_front vectList " << duration.count() / 1000000.0
    << " seconds" << endl;


    start = high_resolution_clock::now();

    for (int i = 0; i < numData; i++) {

        num = rand() % 10 + 1;
        list.push_front(num);

    }

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to push_front STL List " << duration.count() / 1000000.0
    << " seconds" << endl;


    LinkedList<int> linkedList2;
    vector<int> vectList2;
    list.clear();

    start = high_resolution_clock::now();

    for(int i = 0; i < numData; i++) {
        num = rand() % 10 + 1;
        linkedList2.push_back(num);
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to push_back LinkedList " << duration.count() / 1000000.0
    << " seconds" << endl;

    start = high_resolution_clock::now();


    for (int i = 0; i < numData; i++) {
        num = rand() % 10 + 1;
        vectList2.push_back(num);
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to push_back vectList " << duration.count() / 1000000.0
    << " seconds" << endl;

    start = high_resolution_clock::now();

    for (int i = 0; i < numData; i++) {

        num = rand() % 10 + 1;
        list.push_back(num);

    }

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to push_back STL List " << duration.count() / 1000000.0
    << " seconds" << endl;

    return 0;
}
