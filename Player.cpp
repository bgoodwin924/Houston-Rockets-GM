//
// Created by might on 2/13/2018.
//

#include "Player.h"

//Player is created
Player::Player() {
    first_name="";
    last_name="";
    number=0;
}

//Player is created and given name and number
Player::Player(string firstname, string lastname, int num) {
    first_name=firstname;
    last_name=lastname;
    number=num;

}

//sets first name
void Player::set_first_name(string player_first_name) {
    first_name=player_first_name;
}

//sets last name
void Player::set_last_name(string player_last_name) {
    last_name=player_last_name;
}

//sets number
void Player::set_number(int player_number) {
    number=player_number;
}

//gets first name
string Player::get_first_name() {
    return first_name;
}

//gets last name
string Player::get_last_name() {
    return last_name;
}

//gets number
int Player::get_number() {
    return number;
}

//Reads File and loads them into vector
Team::Team(string filename) {
    string player,junk;
    string tempFN, tempLN;
    int num;
    Player P1;
    //open file to read from (reads each line in file)
    ifstream InFile;
    InFile.open(filename);
    while(InFile) {
        getline(InFile, player);
        if(InFile){
            vector<string>result;
            istringstream iss(player);
            for(string player; iss >> player;)
                result.push_back(player);
                tempFN=result[1];
                tempLN=result[2];
                istringstream(result[0])>>num;
                roster.emplace_back(Player(tempFN, tempLN, num));
        }

    }
    InFile.close();

}

//prints the vector of objects out
void Team::printRos() {
    for(int i=0;i<roster.size();i++){
        cout << roster[i].get_number()<<" "<<roster[i].get_first_name()<<" "<<roster[i].get_last_name()<<endl;
    }
}

//adds new player object to the vector
void Team::Sign(Player per) {
    roster.emplace_back(per);
}

//Removes a certain player from the vector
void Team::Waive(int num) {
    auto ob = find_if(roster.begin(), roster.end(), [&num](Player& per) {return per.get_number() == num;});
    if(ob !=roster.end()){
        auto pos=distance(roster.begin(),ob);
        roster.erase(roster.begin()+pos);
        cout<<"That player has been waived"<<endl;
    }else{
        cout<<"That player does not exist sorry"<<endl;
    }
}

