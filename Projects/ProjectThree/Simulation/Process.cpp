/*
 * Description: Implementation for Process class
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/25/2023
 * Date of Last Update: 11/25/2023
 */

#include "Process.h"

/*
 * Description: Default constructor for processes class, sets all variables to 0
 * Parameters: None
 * Return Type: None
 */
// Process::Process() {
//     exeTime = 0;
//     timeStamp = 0;
// }

/*
 * Description: Ovelroaded constructor for Prcoess class, sets exeTime to inputted time, and timeStamp to inputted stamp
 * Parameters: int time, int stamp
 * Return Type: None
 */
Process::Process(int time, int stamp) {
    exeTime = time;
    timeStamp = stamp;
}

/*
 * Description: Copy constructor Process class
 * Parameters: const Process &obj
 * Return Type: None
 */
Process::Process(const Process &obj) {
    exeTime = obj.exeTime;
    timeStamp = obj.timeStamp;
}

/*
 * Description: Destructer for Process class
 * Parameters: None
 * Return Type: None
 */
Process::~Process() {}

/*
 * Description: Mutator function for ExeTime variable
 * Parameters: int time
 * Return Type: None
 */
void Process::setExeTime(int time) {

    if (time < 1) {
        cout << "ERROR: Invalid ExeTime, time must be a value of 1 or higher" << endl;

        return;
    }

    exeTime = time;
}

/*
 * Description: Accessor function for exeTime variable
 * Parameters: None
 * Return Type: int
 */
int Process::getExeTime() const {
    return exeTime;
}

/*
 * Description: Mutator function for timeStamp variable
 * Parameters: int stamp
 * Return Type: None
 */
void Process::setTimeStamp(int stamp) {
    timeStamp = stamp;
}

/*
 * Description: Accessors function for timeStamp variable
 * Parameters: None
 * Return Type: int
 */
int Process::getTimeStamp() const {
    return timeStamp;
}

/*
 * Description: overloaded assignment operator Process objects
 * Parameters: const Process & right
 * Return Type: Process
 */
const Process Process::operator=(const Process &right) {
    exeTime = right.exeTime;
    timeStamp = right.timeStamp;

    return *this;
}

/*
 * Description: overloaded ostream operator for formatted cout
 * Parameters: ostream & os, const Process & obj
 * Return Type: ostream &
 */
ostream & operator << (ostream & os, const Process & obj) {
    os << "[" << obj.exeTime << ", " << obj.timeStamp << "]";

    return os;
}
