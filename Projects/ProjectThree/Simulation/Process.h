/*
 * Description: Header for Process class
 * Name of Author: Given by Professor
 * Date of Creation: N/A
 * Date of Last Update: N/A
 */

#ifndef PROCESS_H
#define PRCOESS_H

#include <iostream>
#include <math.h>

using namespace std;

class Process {

private:
    int exeTime; // Execution time of the process
    int timeStamp; // Time stamp of the process creation

public:
    // Constructors and Destructor
//     Process();
    Process(int time = 1, int stamp = 0);
    Process(const Process &obj);
    ~Process();

    // Acessors and Mutators
    void setExeTime(int);
    int getExeTime() const;
    void setTimeStamp(int);
    int getTimeStamp() const;

    // Overloaded operator functions
    const Process operator=(const Process &right);

    friend ostream & operator << (ostream &, const Process &);

};

#endif // PROCESS_H
