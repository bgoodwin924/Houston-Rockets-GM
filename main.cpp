#include <iostream>
#include <fstream>
#include "Player.h"
using namespace std;

int main() {
    //intro
    cout << "Congrats on becoming the new coach of the Houston Rockets!" << endl;
    cout << "Here is the current roster of the team: " << endl << "---------------------" << endl;
    Team Hou("roster.txt");
    Hou.printRos();
    cout << endl
         << "Now that you are the coach, you can sign new players to the team, or you can waive a current players contract!"
         << endl;
    int ans;
    do {
        //Menu
        cout << "What would you like to do?" << endl;
        cout << "1. Sign a Player"<<endl;
        cout << "2. Waive a Player"<<endl;
        cout << "3. Quit Program"<<endl;
        cout << "Enter a number(1-3): ";
        cin >> ans;
        //Validation
        while(cin.fail()){
            cout<<"That is not a number"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin>>ans;
        }
        while((ans<1) || (ans>3)){
            cout <<"Please choose a number from 1-3: "<<endl;
            cout << "1. Sign a Player"<<endl;
            cout << "2. Waive a Player"<<endl;
            cout << "3. Quit Program"<<endl;
            cin >> ans;
        }
        //user's choices
        switch(ans){
            case 1: {
                string FN, LN;
                int num;
                cout << "You are signing a new player!" << endl;
                cout << "What is their first name?" << endl;
                cin >> FN;
                while (FN.find_first_of("0123456789") != -1)
                {
                    cout << "Names Don't have numbers in them, try again:" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin>>FN;
                }
                cout << "What is their last name?" << endl;
                cin >> LN;
                while (LN.find_first_of("0123456789") != -1)
                {
                    cout << "Names Don't have numbers in them, try again:" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin>>LN;
                }
                cout << "What number should they where?" << endl;
                cin >> num;
                while(cin.fail()){
                    cout<<"That is not a number"<<endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin>>num;
                }
                Player per(FN, LN, num);
                Hou.Sign(per);
                cout << "That player has been signed" << endl;
                cout << "Here is the updated roster" << endl;
                Hou.printRos();
            }
                break;
            case 2: {
                int num;
                cout << "You are about to waive a players contract. Enter their jersey number:" << endl;
                cin >> num;
                Hou.Waive(num);
                //cout<<"That player has been waived. Here is the new roster updated."<<endl;
                Hou.printRos();
            }
                break;
        }

    } while (ans != 3);
}