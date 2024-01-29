/*
 * Description: Test file for sports database
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */


#include <iostream>
#include <fstream>
#include <vector>

#include "Date.h"
#include "FeetInches.h"
#include "Person.h"
#include "NBAPlayer.h"
#include "NFLPlayer.h"

using namespace std;

void loadNBADataFile(string, vector<Person*> &);
void loadNFLDataFile(string, vector<Person*> &);

void displayPlayerInfo(vector<Person*> &);

void sortByName(vector<Person*> &);
void sortByHeight(vector<Person*> &);
void sortByWeight(vector<Person*> &);

int main() {

    vector<Person*> PlayerInfo;

    loadNBADataFile("NBA.csv", PlayerInfo);
    loadNFLDataFile("NFL.csv", PlayerInfo);

    displayPlayerInfo(PlayerInfo);

    sortByName(PlayerInfo);

    displayPlayerInfo(PlayerInfo);

    vector<Person*> BigPlayers;

    for (size_t i = 0; i < PlayerInfo.size(); i++)
        if (PlayerInfo[i]->getWeight() > 350)
            BigPlayers.push_back(PlayerInfo[i]);

    sortByWeight(BigPlayers);

    displayPlayerInfo(BigPlayers);

    FeetInches max;

    for (size_t i = 0; i < PlayerInfo.size(); i++)
        if (PlayerInfo[i]->getHeight() > max)
            max = PlayerInfo[i]->getHeight();

    vector<Person*> TallestPlayers;

    for (size_t i = 0; i < PlayerInfo.size(); i++)
        if(PlayerInfo[i]->getHeight() == max)
            TallestPlayers.push_back(PlayerInfo[i]);

    displayPlayerInfo(TallestPlayers);

    Date oldest;

    for (size_t i = 0; i < PlayerInfo.size(); i++)
            if (oldest < PlayerInfo[i]->getDob())
                oldest = PlayerInfo[i]->getDob();

    vector<Person*> OldestPlayers;

    for (size_t i = 0; i < PlayerInfo.size(); i++)
        if (PlayerInfo[i]->getDob() == oldest)
            OldestPlayers.push_back(PlayerInfo[i]);

    displayPlayerInfo(OldestPlayers);

    Date youngest;
    for (size_t i = 0; i < PlayerInfo.size(); i++)
            if (youngest > PlayerInfo[i]->getDob())
                youngest = PlayerInfo[i]->getDob();

    vector<Person*> YoungestPlayers;

    for (size_t i = 0; i < PlayerInfo.size(); i++)
        if (PlayerInfo[i]->getDob() == youngest)
            YoungestPlayers.push_back(PlayerInfo[i]);

    displayPlayerInfo(YoungestPlayers);

    for (size_t i = 0; i < PlayerInfo.size(); i++)
        delete PlayerInfo[i];

    return 0;


}

/*
 * Description: Function to read in an NBA csv file to a vector of Person pointers
 * Parameters: string filename, vector<Person> & PlayerInfo
 * Return Type: None
 */
void loadNBADataFile(string filename, vector<Person*> & PlayerInfo) {

    ifstream indata;
    indata.open(filename);

    if (!indata) {

        cout << "The file could not be opened" << endl;
        exit(1);

    }

    size_t nextComma;
    size_t startPosition = 0;
    string currentData = " ";
    string lastName = " ";
    string firstName = " ";
    string jerseyNum = " ";
    string position = " ";
    string height = " ";
    string weight = " ";
    string dob = " ";

    FeetInches h;
    Date date;

    if(indata.is_open()) {

        getline(indata, currentData); // store header

      while (getline(indata, currentData)){

            startPosition = 0;

            nextComma = currentData.find(",", startPosition);
            lastName = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);


            nextComma = currentData.find(",", startPosition);
            firstName = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            jerseyNum = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            position = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            height = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            weight = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            dob = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            h.setLength(height);
            date.setMDY(dob);

            try {
                stod(weight);

            } catch (exception & e) {
                weight = "200";
                stod(weight);
            }

            try {
                stoi(jerseyNum);
            } catch (exception & e) {

                jerseyNum = "0";
                stoi(jerseyNum);

            }

            PlayerInfo.push_back(new NBAPlayer(lastName, firstName, h, stod(weight), date, position, stoi(jerseyNum)));

        }

    }

    indata.close();
    PlayerInfo.shrink_to_fit();
}

/*
 * Description: Function to read in an NFL csv file to a vector of Person pointers
 * Parameters: string filename, vector<Person> & PlayerInfo
 * Return Type: None
 */
void loadNFLDataFile(string filename, vector<Person*> & PlayerInfo) {

    ifstream indata;
    indata.open(filename);

    if (!indata) {

        cout << "The file could not be opened" << endl;
        exit(1);

    }

    size_t nextComma;
    size_t startPosition = 0;
    string currentData = " ";
    string lastName = " ";
    string firstName = " ";
    string jerseyNum = " ";
    string position = " ";
    string height = " ";
    string weight = " ";
    string dob = " ";
    string teamCode = " ";

    FeetInches h;
    Date date;

    if(indata.is_open()) {

        getline(indata, currentData); // store header

      while (getline(indata, currentData)){

            startPosition = 0;

            nextComma = currentData.find(",", startPosition);
            jerseyNum = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            lastName = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            lastName.erase(0, 1);

            nextComma = currentData.find(",", startPosition);
            firstName = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            firstName.erase(0, 1);

            nextComma = firstName.find("\"", startPosition);
            firstName = firstName.substr(startPosition, (nextComma + startPosition));

            nextComma = currentData.find(",", startPosition);
            position = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            height = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            weight = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            dob = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            nextComma = currentData.find(",", startPosition);
            teamCode = currentData.substr(startPosition, (nextComma + startPosition));
            currentData.erase(0, nextComma + 1);

            date.setMDY(dob);

            try {
                stod(weight);

            } catch (exception & e) {
                weight = "200";
                stod(weight);
            }

            try {
                stoi(jerseyNum);
            } catch (exception & e) {

                jerseyNum = "0";
                stoi(jerseyNum);

            }

            PlayerInfo.push_back(new NFLPlayer (lastName, firstName, height, stod(weight), date, position, stoi(jerseyNum), teamCode));

        }

    }

    indata.close();

}

/*
 * Description: Prints out our database which is a vector of Person pointers
 * Parameters: None
 * Return Type: None
 */
void displayPlayerInfo(vector<Person*> & PlayerInfo) {

    for (long unsigned int i = 0; i < PlayerInfo.size(); i++) {

        cout << PlayerInfo.at(i)->toString() << endl;

    }

}

/*
 * Description: Sorts our database which is a vector of Person pointers in alphabetical order
 * Parameters: vector<Person*> & PlayerInfo
 * Return Type: None
 */
void sortByName(vector<Person*> & PlayerInfo) {

    int minIndex;
    string minValue;

    for (long unsigned int start = 0; start < (PlayerInfo.size() - 1); start++) {
        minIndex = start;
        minValue = PlayerInfo[start]->getFormal();

        for (long unsigned int index = start + 1; index < PlayerInfo.size(); index++) {
            if (PlayerInfo[index]->getFormal() < minValue) {

                minValue = PlayerInfo[index]->getFormal();
                minIndex = index;
            }
        }

        swap(PlayerInfo[minIndex], PlayerInfo[start]);
    }

}

/*
 * Description: Sorts our database which is a vector of Person pointers by height from shortest to tallest
 * Parameters: vector<Person*> & PlayerInfo
 * Return Type: None
 */
void sortByHeight(vector<Person*> & PlayerInfo) {

    int minIndex;

    FeetInches minValue;

	for (long unsigned int start = 0; start < (PlayerInfo.size() - 1); start++) {

		minIndex = start;
		minValue = PlayerInfo[start]->getHeight();
		for (long unsigned int index = start + 1; index < PlayerInfo.size(); index++) {

			if (PlayerInfo[index]->getHeight() < minValue) {

				minValue = PlayerInfo[index]->getHeight();
				minIndex = index;

			}

		}

		swap(PlayerInfo[minIndex], PlayerInfo[start]);

	}

}

/*
 * Description: Sorts our database which is a vector of Person pointers by weight from lightest to heaviest
 * Parameters: vector<Person*> & PlayerInfo
 * Return Type: None
 */
void sortByWeight(vector<Person*> & PlayerInfo) {

    int minIndex, minValue;

	for (long unsigned int start = 0; start < (PlayerInfo.size() - 1); start++) {

		minIndex = start;
		minValue = PlayerInfo[start]->getWeight();

		for (long unsigned int index = start + 1; index < PlayerInfo.size(); index++) {

			if (PlayerInfo[index]->getWeight() < minValue) {

				minValue = PlayerInfo[index]->getWeight();
				minIndex = index;

			}

		}

		swap(PlayerInfo[minIndex], PlayerInfo[start]);

	}

}


