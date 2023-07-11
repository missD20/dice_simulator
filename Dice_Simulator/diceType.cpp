/******************************************************************************

Program 1 | Simple Dice Simulator
This program allows the user to simulate rolling a number of dice that they specify.
Dougo Kone-Sow
Monday, October 31st, 2022

*******************************************************************************/

#include <iostream>

#include "diceType.h"

using namespace std;


diceType::diceType(string name, unsigned int sides)
{
    this->dice_name = name;
    if(sides < 2 || sides > this->max_sides)
    {
        this->number_of_sides = 6;
    }
    else
    {
        this->number_of_sides = sides;
    }
}

diceType::~diceType(){}

void diceType::setName(string name)
{
   this->dice_name = name;
}

void diceType::setSides(unsigned int sides)
{
    if(sides > this->max_sides)
    {
        this->number_of_sides = this->max_sides;
    }
    else
    {
        this->number_of_sides = sides;
    }

}

string diceType::getName() const
{
    return this->dice_name;
}

unsigned int diceType::getSides() const
{
    return this->number_of_sides;
}
