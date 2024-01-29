#include "StateData.h"

StateData::StateData() {
    data = nullptr;
    size = 0;
    StateName = " ";


}

StateData::~StateData() {
    delete[] data;
}

void StateData::setStateName(string name) {
    StateName = name;
}

string StateData::getStateName() {
    return StateName;
}

void StateData::add(double dataToAdd) {
    int newSize = size + 1;

    double *copyArr = new double[newSize];

    for (int i = 0; i < size; i++)
        copyArr[i] = data[i];

    copyArr[size] = dataToAdd;

    delete[] data;
    data = nullptr;
    data = new double[newSize];

    for (int i = 0; i < newSize; i++)
        data[i] = copyArr[i];

    delete[] copyArr;
    copyArr = nullptr;
    size = newSize;
}

double StateData::get(int i) {
    if (i > size || i < 0)
        return 0;

    return data[i];
}
