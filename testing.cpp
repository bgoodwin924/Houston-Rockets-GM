//
// Created by might on 2/15/2018.
//
#include <iostream>
#include <fstream>
#include "Player.h"
using namespace std;

int main(){

    //should print out roster
    Team test("roster.txt");
    test.printRos();

    //prints nothing
    Team test2("poster.png");
    test2.printRos();

    //Makes a new player
    Player per("Brandon","Goodwin", 20);
    cout << per.get_first_name()<<endl;
    cout << per.get_last_name()<<endl;
    cout << per.get_number()<<endl;

    //Edit the player
    per.set_first_name("John");
    per.set_last_name("Cena");
    per.set_number(0);
    cout << per.get_first_name()<<endl;
    cout << per.get_last_name()<<endl;
    cout << per.get_number()<<endl;

    //signs John Cena
    test.Sign(per);
    test.printRos();

    //We can't sae him anymore
    test.Waive(0);
    test.printRos();
};
