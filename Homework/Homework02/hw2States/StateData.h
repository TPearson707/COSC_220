#ifndef STATEDATA_H_
#define STATEDATA_H_

#include <cstdlib>

using namespace std;

class StateData {
private:
    string StateName;
    double *data;
    int size;

public:
    StateData();
    ~StateData();

    void setStateName(string);
    string getStateName();
    void add(double);
    double get(int);
};

#endif // STATEDATA_H
