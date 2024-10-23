/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/23/24
*/
#ifndef MAINHEAD_H
#define MAINHEAD_H

#include "foodList.H"
#include <iostream>

//function Prototypes for Main

//Imports Food Objects from a text file into a foodList
bool importFile(std::string, foodList*);

//Exports Food Objects to a text file
bool exportFile(std::string, foodList*);

#endif