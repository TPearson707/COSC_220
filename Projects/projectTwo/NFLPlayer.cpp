/*
 * Description: Implementation file for NFLPlayer class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#include "NFLPlayer.h"

#include <string>

using namespace std;

/*
 * Description: Default constructor for NFLPlayer class
 * Parameters: None
 * Return Type: None
 */
NFLPlayer::NFLPlayer() {

    setName(" ", " ");
    setHeight(0, 0);
    setWeight(0);
    setDob(0, 0, 0000);
    positionCode = " ";
    playerNumber = -1;
    teamCode = " ";

}

/*
 * Description: Overloaded constructor for NFLPlayer class
 * Parameters: string last string first string h double w Date date string pos int num string tC
 * Return Type: None
 */
NFLPlayer::NFLPlayer(string last, string first, string h, double w, Date date, string pos, int num, string tC) {
        setName(last, first);
        setHeight(stod(h));
        setWeight(w);
        setDob(date.getMonth(), date.getDay(), date.getYear());
        positionCode = pos;
        playerNumber = num;
        teamCode = tC;
}

/*
 * Description: Destructor for the NFLPlayer class
 * Parameters: None
 * Return Type: None
 */
NFLPlayer::~NFLPlayer() {


}

/*
 * Description: returns the position code for an object of the NFLPlayer class
 * Parameters: None
 * Return Type: string
 */
string NFLPlayer::getPositionCode() const {

    return positionCode;

}

/*
 * Description: returns the player number for an object of the NFLPlayer class
 * Parameters: None
 * Return Type: int
 */
int NFLPlayer::getPlayerNumber() const {

    return playerNumber;


}

/*
 * Description: Returns the team code for an object of the NFLPlayer class
 * Parameters: None
 * Return Type: string
 */
string NFLPlayer::getTeamCode() const {

    return teamCode;

}

/*
 * Description: returns a string of the data for an NFL player
 * Parameters: None
 * Return Type: string
 */
string NFLPlayer::toString() {

    string formal = Person::toString();
    formal += " / " + positionCode + " / " + to_string(playerNumber) + " / " + teamCode + " / NFL";

    return formal;

}
