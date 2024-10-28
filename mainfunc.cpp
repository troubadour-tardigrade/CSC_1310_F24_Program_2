/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/21/24
*/

#include "foodList.h"
#include <iostream>
#include <fstream>

//global variable to ensure import and export functions are using the same char, should it be changed later on
const char delimiter = '#';

//imports a text file to a foodList data type, will return true on a sucessful read and false on a failed read
bool importFile(std::string fileName, foodList* importME){

    //temp Variables
    std::string input;
    Food Temp;

    //opening file
    std::ifstream inputFile;
    inputFile.open(fileName);

    if(!inputFile.is_open()){
        //if file doesn't open, return false
        return(false);
    }


    do{
        //reading data
        getline(inputFile, input, delimiter);
        Temp.setName(input);

        getline(inputFile, input, delimiter);
        Temp.setSize(stoi(input));

        getline(inputFile, input, delimiter);
        Temp.setPrice(stod(input));

        getline(inputFile, input, delimiter);
        Temp.setCalories(stod(input));

        //adding to list :]
        importME->newFood(Temp);
    }while(inputFile.good());

    //closing and ending function
    inputFile.close();
    return(true);    
}


//function definition for exportFile, will export a foodList to a text file, will return true upon a successful export
bool exportFile(std::string fileName, foodList* exportME){

    //opening file
    std::ofstream outputFile;
    outputFile.open(fileName);

    //checking that the file opened and the list isn't empty
    if(!outputFile.is_open() || exportME->peek(0) != NULL){
        return(false);
    }

    //index i is the current position in the list
    int i = 0;
    while(exportME->peek(i) != NULL){
        //Outputting to file
        outputFile << exportME->getFood(i).getName() << delimiter;
        outputFile << exportME->getFood(i).getSize() << delimiter;
        outputFile << exportME->getFood(i).getPrice() << delimiter;
        outputFile << exportME->getFood(i).getCalories() << delimiter;
        i++;
    }

    //closing file and returning
    outputFile.close();
    return(true);
    
}

//Prints Main Menu based on the provided index where the default is the main menu
void printMenu(int i = 0){
    switch(i){
        case (0):
            std::cout << "\nWhat Would you Like to do?\n";
            std::cout << "1.) \n";
            std::cout << "2.) \n";
            std::cout << "3.) \n";
    }
}