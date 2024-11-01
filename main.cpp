/*
    Collaborators: Jonathan Salvato, Nick Romsdal
    Program 2
    Date: 10/23/24
*/

#include "mainHEAD.h"
#include <string>
#include <fstream>

const char delimiter = ',';


int main(){
    foodList fruit;
    foodList vegetable;
    foodList grain;
    foodList protein;

    foodList foodGroups[4] = {fruit, vegetable, grain, protein}; 

    bool status;

    importFile("data_files/fruit.txt", &fruit);

    // importFile("data_files/vegetable.txt", &vegetable);

    // importFile("data_files/grain.txt", &grain);
    
    // importFile("data_files/protein.txt", &protein);

    // fruit.sortAsc();
    // std:: cout << fruit;

    printMenu(0);



    // exportFile("data_files/fruit.txt", &fruit);

    // exportFile("data_files/vegetable.txt", &vegetable);

    // exportFile("data_files/grain.txt", &grain);
    
    // exportFile("data_files/protein.txt", &protein);

    std::cout << "\nEND";
    return(0);
}


//imports a text file to a foodList data type, will return true on a sucessful read and false on a failed read
bool importFile(std::string fileName, foodList* importME){

    //temp Variables
    std::string input;
    Food Temp;

    //opening file
    std::ifstream inputFile;
    inputFile.open(fileName);

    if(!inputFile.is_open() || inputFile.eof()){
        //if file doesn't open or is empty, return false
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
void printMenu(int i){
    int input;
    switch(i){
        case 0:
            std::cout << "\nWhat Would you Like to do?\n";
            std::cout << "0.) Main Menu\n";
            std::cout << "1.) View Food Group Lists\n";
            std::cout << "2.) Quit\n";

            std::cout << "Enter the number associated with what you want to do:\t";
            std::cin >> input;
            printMenu(input);

            break;
        case 1:    // View Food Group Lists
            std::cout << "\nWhich food group do you want to view?\n";
            std::cout << "11.) Fruits\n";
            std::cout << "12.) Vegetables\n";
            std::cout << "13.) Grains\n";
            std::cout << "14.) Protein\n";

            std::cout << "Enter the number associated with what you want to do:\t";
            std::cin >> input;
            printMenu(input);

            break;
        case 2:     // Quit
            break;

        case 11:
            std::cout << "Current Food Group:\tFruit" << std::endl;
            std::cout << "Current Food: " << std::endl;
            // Print food object (title, serving size, calories, price)

            // Ask the user if they want to move to the next node or quit 

        case 12:
            std::cout << "Current Food Group:\tVegetable" << std::endl;
            std::cout << "Current Food: " << std::endl;
            // Print food object (title, serving size, calories, price)

            // Ask the user if they want to move to the next node or quit 
            
        case 13:
            std::cout << "Current Food Group:\tGrain" << std::endl;
            std::cout << "Current Food: " << std::endl;
            // Print food object (title, serving size, calories, price)

            // Ask the user if they want to move to the next node or quit 
            
        case 14:
            std::cout << "Current Food Group:\tProtein" << std::endl;
            std::cout << "Current Food: " << std::endl;
            // Print food object (title, serving size, calories, price)

            // Ask the user if they want to move to the next node or quit 
            



    }
}