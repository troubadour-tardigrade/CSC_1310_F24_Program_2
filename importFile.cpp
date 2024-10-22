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

    /*
     *
     *
     * I'm making this big to make it harder to ignore later    
     * Come back and redo after file structure is more defined
     * (if needed ofc) 
     *
     * 
     * 
    */


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

    return(true);    
}