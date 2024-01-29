/*
 * Description: Implementation file for NBAPlayer class
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/30/2023
 * Date of Last Update: 11/3/2023
 */

#include "NBAPlayer.h"

#include <string>

using namespace std;

/*
 * Description: Default constructor for the NBAPlayer class
 * Parameters: None
 * Return Type: None
 */
NBAPlayer::NBAPlayer() {

    setName(" ", " ");
    setHeight(0, 0);
    setWeight(0);
    setDob(0, 0, 0);
    positionCode = " ";
    playerNumber = -1;

}

/*
 * Description: Overloaded constructor to bring in data for NBA Player
 * Parameters: string last string first FeetInches h double w Date date string pos int num
 * Return Type: None
 */
NBAPlayer::NBAPlayer(string last, string first, FeetInches h, double w, Date date, string pos, int num) {
        setName(last, first);
        setHeight(h.getFeet(), h.getInches());
        setWeight(w);
        setDob(date.getMonth(), date.getDay(), date.getYear());
        positionCode = pos;
        playerNumber = num;
}

/*
 * Description: Destructor
 * Parameters: None
 * Return Type: None
 */
NBAPlayer::~NBAPlayer() {


}

/*
 * Description: Returns the position code for NBAPlayer object
 * Parameters: None
 * Return Type: string
 */
string NBAPlayer::getPositionCode() const {

    return positionCode;

}

/*
 * Description: Returns the player number for NBAPlayer object
 * Parameters: None
 * Return Type: int
 */
int NBAPlayer::getPlayerNumber() const {

    return playerNumber;


}

/*
 * Description: Returns a string of the data for an NBA player
 * Parameters: None
 * Return Type: string
 */
string NBAPlayer::toString() {

    string formal = Person::toString();
    formal += " / " + positionCode + " / " + to_string(playerNumber) + " / NBA";

    return formal;

}
