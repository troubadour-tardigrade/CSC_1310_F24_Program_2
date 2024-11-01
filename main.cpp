/*
    Collaborators: Jonathan Salvato, Nick Romsdal
    Program 2
    Date: 10/23/24
*/

#include "mainHEAD.h"
#include <fstream>
#include <string>

int main(){
    foodList fruit;
    foodList vegetable;
    foodList grain;
    foodList protein;

    bool status;



    std::cout << "Startup" << std::endl;

    status = importFile("data_files/fruit.txt", &fruit);
    std::cout << "Fruit List Imported:\t" << status << std::endl;

    // status = importFile("data_files/vegetable.txt", &vegetable);
    // std::cout << "Vegetable List Imported:\t" << status << std::endl;

    // status = importFile("data_files/fruit.txt", &fruit);
    // std::cout << "Fruit List Imported:\t" << status << std::endl;

    // status = importFile("data_files/fruit.txt", &fruit);
    // std::cout << "Fruit List Imported:\t" << status << std::endl;

    

    fruit.sortAsc();
    std:: cout << fruit;


    std::cout << "\nEND";
    return(0);
}
