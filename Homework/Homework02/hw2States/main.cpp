#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "StateData.cpp"

using namespace std;

/*
 * 27 years
 * 27 data per year
 * 1 data per year
 */
int main() {
    StateData *statedata;
    string yearsString = " ";
    int *years;
    int numYears;
    int numStates;

    string file;
    cout << "What file do you want to open" << endl;
    cin >> file;

    ifstream indata;
    indata.open(file);

    if (!indata) {
        cout << "File cannot be opened" << endl;
        exit(1);
    }
    if (indata.is_open()) {
        string currentLineData = " ";
        getline(indata, currentLineData);
        currentLineData.erase(0, 6);

        size_t last_comma = currentLineData.find(",") + 1;

        int yearsSize = 0;
        string getYearSize = currentLineData;
        while (getYearSize != "") {
            getYearSize.erase(0, last_comma);
            yearsSize++;
        }

        numYears = yearsSize;
        years = new int[yearsSize];

        for (int i = 0; i < yearsSize; i++) {
            yearsString = currentLineData.substr(0, currentLineData.find(","));
            years[i] = stoi(yearsString);
            currentLineData.erase(0, last_comma);
            // cout << years[i] << " "; // check num years in array
        }

        int statesSize = 0;
        while (!indata.eof()) {
            getline(indata, currentLineData);
            statesSize++;
        }
        statesSize -= 1;
        statedata = new StateData[statesSize];
        numStates = statesSize;
    }

    indata.close();
    indata.open(file);

    if(!indata) {
        cout << "File cannot be opened" << endl;
        exit(1);
    }

    if(indata.is_open()) {
        string currentLineData = " ";
        getline(indata, currentLineData);
        string nextData = " ";
        size_t nextComma;
        size_t startPosition = 0;

        for (int i = 0; i < numStates; i++) {
            getline(indata, currentLineData);
            nextComma = currentLineData.find(",", startPosition);
            nextData = currentLineData.substr(startPosition, (nextComma - startPosition));
            statedata[i].setStateName(nextData);
            startPosition = nextComma + 1;

            for (int j = 0; j < numYears ; j++) {
                nextComma = currentLineData.find(",", startPosition);
                nextData = currentLineData.substr(startPosition, (nextComma - startPosition));
                statedata[i].add(stod(nextData));
                startPosition = nextComma + 1;
            }
            startPosition = 0;
        }

        for (int i = 0; i < numStates; i++)
            cout << i + 1 << ": " << statedata[i].getStateName() << endl;
    }

    indata.close();

    int stateNum;
    cout << "Enter a state number: ";
    cin >> stateNum;
    cout << endl;

    while (stateNum < 1 || stateNum > numStates) {
        cout << "Invalid state number please try again" << endl;
        cin >> stateNum;
    }

    stateNum -= 1;

    cout << "\nSelect a year" << endl;
    for (int i = 0; i < numYears; i++) {
        cout << years[i] << endl;
    }
    int yearSelect;
    int dataIndex;
    bool validYear = false;
    cout << "Selection: ";
    cin >> yearSelect;

    for (int i = 0; i < numYears; i++) {
        if (yearSelect == years[i]) {
            validYear = true;
            dataIndex = i;
        }
    }

    while (validYear == false) {
        cout << "invalid year please try again" << endl;
        cin >> yearSelect;

        for (int i = 0; i < numYears; i++) {
            if (yearSelect == years[i]) {
                validYear = true;
                dataIndex = i;
            }
        }
    }

    cout << "The energy-related carbon dioxide emissions for " << statedata[stateNum].getStateName() << " in millions of metric tons in the year " << yearSelect << " was " << statedata[stateNum].get(dataIndex) << "." << endl;

    delete[] years;
    return 0;
}
