/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/23/24
*/
#include "mainHEAD.h"

int main(){
    Food a("Test 4", 4, 4, 4);
    Food b("Test 2", 2, 2, 2);
    Food c("Test 3", 3, 3, 3);
    Food d("Test 1", 1, 1, 1);

    foodList A;

    A.setFood(0, a);
    A.newFood(b);
    A.newFood(c);
    A.newFood(d);
    std::cout << A;

    A.sortAsc();
    std:: cout << A;

    //A.sortDec();
    //std::cout << A;


    std::cout << "\nEND";
    return(0);
}