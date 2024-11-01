/*
    Collaborators: Nick Romsdal
    Program 2
    Date 1021.24
*/
#ifndef FOOD_H
#define FOOD_H

#include <string>


class Food
{
private:
    std::string name;
    int servingSize;
    double calories;
    double price;

public:
    // Constructors
    Food();
    Food(std::string, int, double, double);

    // Mutator Functions
    void setName(std::string);
    void setSize(int);
    void setCalories(double);
    void setPrice(double);

    // Accessor Functions
    std::string getName();
    int getSize();
    double getCalories();
    double getPrice();
};

// Constructor Definitions
Food::Food()
{
    this->name = "bread";
    this->servingSize = 5;
    this->calories = 400.5;
    this->price = 5.99;
}

// Overloaded Constructor Definition
Food::Food(std::string name, int servingSize, double calories, double price)
{
    this->name = name;
    this->servingSize = servingSize;
    this->calories = calories;
    this->price = price;
}

// Mutators

// Set the name of the given food object to string value passed in through 'name' 
void Food::setName(std::string name)
{
    this->name = name;
}

// Set the recommended serving size of the given food object to the integer parameter 'servingSize'.
// For the sake of this program, the serving size will be some arbituary integer between 1 and 2000.  
void Food::setSize(int servingSize)
{
    this->servingSize = servingSize;
}

// Set the number of calories in the recommended serving size of the given food object to the double value passed in via 'calories'.
// For the sake of this program, the calories per seving value will be an arbituary value between 1 and 500.
void Food::setCalories(double calories)
{
    this->calories = calories; 
}

// Set the price of the given food object to the double value passed in through the 'price' parameter.
// For the sake of the program, the price will be some arbituary value between 0.01 and 15.99
void Food::setPrice(double price)
{
    this->price = price;
}

// Accessor Functions

// Return the name of the given food object
std::string Food::getName()
{
    return this->name;
}

// Return the recommended serving size of a given food object
int Food::getSize()
{
    return this->servingSize;
}

// Return the calories per serving value for a given food object
double Food::getCalories()
{
    return this->calories;
}

// Return the price of a given food object
double Food::getPrice()
{
    return this->price;
}

#endif