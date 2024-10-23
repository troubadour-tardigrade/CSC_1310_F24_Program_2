/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/21/24
*/

#include "foodList.h"
#include <iostream>
#include <fstream>

//imports a text file to a foodList data type, will return true on a sucessful read and false on a failed read
bool importFile(std::string fileName, foodList* importME){
    //for now the delimiter will be #
    const char delimiter = '#';

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
    //Same Delimiter as importFile, if it's not someone messed up :(
    const char delimiter = '#';

    std::ofstream outputFile;
    outputFile.open(fileName);

    if(!outputFile.is_open() || exportME->peek(0) != NULL){
        return(false);
    }

    //index i is the current position in the list
    int i = 0;
    while(exportME->peek(i) != NULL){
        //Outputting to file
        outputFile << exportME->getFood(0).getName() << delimiter;
        outputFile << exportME->getFood(0).getSize() << delimiter;
        outputFile << exportME->getFood(0).getPrice() << delimiter;
        outputFile << exportME->getFood(0).getCalories() << delimiter;
    }

    //closing file and returning
    outputFile.close();
    return(true);
    
}