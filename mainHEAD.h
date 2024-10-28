/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/23/24
*/
#ifndef MAINHEAD_H
#define MAINHEAD_H

#include "foodList.H"

//function Prototypes for Main

//Imports Food Objects from a text file into a foodList
bool importFile(std::string, foodList*);

//Exports Food Objects to a text file
bool exportFile(std::string, foodList*);

//Prints Menu based on provided index, default is Main menu
void printMenu(int);

#endif