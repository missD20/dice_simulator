/******************************************************************************

Program 1 | Simple Dice Simulator
This program allows the user to simulate rolling a number of dice that they specify.
Dougo Kone-Sow
Monday, October 31st, 2022

*******************************************************************************/

#ifndef DICETYPE_H
#define DICETYPE_H

#include <string>

class diceType
{
    public:
        diceType(std::string name, unsigned int sides);
        ~diceType();

        void setName(std::string number);
        void setSides(unsigned int sides);

        std::string getName() const;
        unsigned int getSides() const;

    private:
        std::string dice_name; // THE DIE'S NAME
        unsigned int number_of_sides; // NUMBER OF SIDES OF THE DIE
        const unsigned int max_sides =  1000; // THE MAXIMUM NUMBER OF SIDES
};

#endif // DICETYPE_H
