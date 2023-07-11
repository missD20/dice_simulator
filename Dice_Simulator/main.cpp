/******************************************************************************

Program 1 | Simple Dice Simulator
This program allows the user to simulate rolling a number of dice that they specify.
Dougo Kone-Sow
Monday, October 31st, 2022

*******************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>

#include <cstdlib>
#include <limits>

#include "diceType.h"


using namespace std;

int main()
{
    unsigned int dice_number(0);

    string user_name("UNKNOW");
    bool stay_in(true);

    vector<diceType> dice_array;

    cout << "-------------------------------------------\n"
         << "| WELLCOME INTO THE SIMPLE DICE SIMULATOR |\n"
         << "-------------------------------------------\n\n"
         << "\tPLAESE IDENTIFY YOUR SELF: ";

    // WE TAKE THE USER NAME HERE
    getline(cin, user_name);
    cout << "\tUSER NAME: ->> " + user_name + " <<- ACCEPTED !" << endl;

    cout << "\n\tHOW MANY DIE YOU WANT TO USE ? (MIN:2, MAX:500) : ";
    // WE TAKE HERE THE NUMBER OF DICE
    while (!(cin >> dice_number))
    {
        cout << "\n\tERROR ENTER A NUMBER : ";
        cin.clear();
        cin.seekg(0, ios::end);

        if(!cin.fail()){
            cin.ignore(numeric_limits<streamsize>::max());
        }
        else{
            cin.clear();
        }
    }

    // WE TAKE HERE THE NUMBER OF DICE
    cout << "\n\tSPECIFY THE NUMBER OF THE SIDES BELOW (MIN:2 | MAX:1000)\n";
    for(unsigned int i = 0; i < dice_number; i++)
    {
        unsigned int sides(0);
        cout << "\n\tDICE[" + to_string(i + 1) + "]: ";
        while (!(cin >> sides))
        {
            cout << "\n\tERROR ENTER A NUMBER | " << "DICE[" + to_string(i + 1) + "]: ";
            cin.clear();
            cin.seekg(0, ios::end);

            if(!cin.fail()){
                cin.ignore(numeric_limits<streamsize>::max());
            }
            else{
                cin.clear();
            }
        }

        diceType dice(to_string(i), sides);
        dice_array.push_back(dice);
    }

    // WE START THE SIMULATION HERE
    cout << "\n-----------------------------------\n"
         << "| THE DICE SIMULATOR CAN START NOW |"
         << "\n-----------------------------------\n";

    unsigned int counter(0);
    do
    {
        string result("");

        for(unsigned int i = 0; i < dice_array.size(); i++)
        {
            srand(time(0));
            result += " | " + to_string(rand() % dice_array[i].getSides() + 1);
        }

        result += " |";
        cout << "\n\tLAUNCH[" + to_string(counter + 1) + "] : " << result << endl;

        cout << "\n\tWILL YOU LIKE TO CONTINU ? 1(Yes) / 0(No) : ";
        int status(1);
        while (!(cin >> status))
        {
            cout << "\n\tWILL YOU LIKE TO CONTINU ? 1(Yes) / 0(No) : ";
            cin.clear();
            cin.seekg(0, ios::end);

            if(!cin.fail()){
                cin.ignore(numeric_limits<streamsize>::max());
            }
            else{
                cin.clear();
            }
        }

        switch (status)
        {
        case 0:
            stay_in = false;
            cout << "\n\n\tTHANK YOU, GOODBYE AND SEE YOU SOON -> " << user_name << " <- !" << endl;
            break;
        default:
            cout << "\n\n\t" << user_name << " LET'S GO FOR ANOTHER THROW...\n\n" << endl;
            counter++;
            break;
        }
    }while (stay_in);

    return 0;
}
