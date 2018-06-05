//
// Created by might on 2/13/2018.
//

#ifndef PJ3_PLAYER_H
#define PJ3_PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Player {
    //Variables to be accesed
    string first_name;
    string last_name;
    int number;
public:
    /**
     * Default Constructor
     * Requires: nothing
     * Modifies: first and last name, number
     * Effects: creates both variables with empty strings, and number =0
    */
    Player();

    /**
    * non-Default Constructor
    * Requires: nothing
    * Modifies: first/last name, and num
    * Effects: sets each variable to the following inputs
    */
    Player(string firstname, string lastname, int num);

    //Setters
    /**
     * First Name Setter
     * Requires: nothing
     * Modifies: First Name
     * Effects: sets first name to input
    */
    void set_first_name(string player_first_name);

    /**
    * Last Name Setter
    * Requires: nothing
    * Modifies: Last Name
    * Effects: sets Last name to input
    */
    void set_last_name(string player_last_name);

    /**
    * Player Number  Setter
    * Requires: nothing
    * Modifies: player number
    * Effects: sets number to input
    */
    void set_number(int player_number);

    //Getters
    /**
     * First Name Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns First Name
    */
    string get_first_name();

    /**
     * Last Name Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns Last name
    */
    string get_last_name();

    /**
     * Num Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns number
    */
    int get_number();


};

class Team{
private:
    // Creates a vector of only Player objects
    vector<Player> roster;
public:
    /**
 * Default Constructor
 * Requires: nothing
 * Modifies: nothing
 * Effects: makes team object
*/
    Team();

    /**
 * non-Default Constructor
 * Requires: nothing
 * Modifies: Vector of player objects updated
 * Effects: reads file and add all players to a vector of player objects
*/
    Team(string filename);

    /**
 * Roster Getter
 * Requires: nothing
 * Modifies: nothing
 * Effects: Prints out every player in the vector of player objects
*/
    void printRos();

    /**
 * Sign Player
 * Requires: Player Object
 * Modifies: Vector updated, first name, last name, number updated
 * Effects: adds a new player object to the vector of objects
*/
    void Sign(Player);

    /**
* Waive Player
* Requires: nothing
* Modifies: Vector updated, first name, last name, number updated
* Effects: removes a player object to the vector of objects
*/
    void Waive(int num);
};
#endif //PJ3_PLAYER_H
