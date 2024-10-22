/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/21/24
*/
#ifndef FOODLIST_H
#define FOODLIST_H


#include "Food.h"

//inheriting template from parent class to ensure usability
template<class foodGroup>
class foodList{
    private:
    //Creating a linked List
    struct list{
        Food<foodGroup> obj; 
        Food<foodGroup>* pnt;
    };
    list head;
    list* tail;

    //function Prototypes
    void push_back(Food<foodGroup>);
    void insert(Food<foodGroup>, int);
    void deletion(int);
    list* accessItem(int);

    public:
    //constructor
    foodList<foodGroup>();

    //Destructor
    ~foodList<foodGroup>();

    //Accessor functions
    Food<foodGroup> getFood(int);

    //Mutator functions
    void setFood(int, Food<foodGroup>);
    void newFood();
    void newFood(Food<foodGroup>);
    void newFood(Food<foodGroup>, int);
    void RemoveItem(int);

};


//function Definitions :)

//Mostly for internal use, if needed, they can become external

//creates new object
template <class foodGroup>
void foodList<foodGroup>::push_back(Food<foodGroup> item){
    Food<foodGroup>* temp;
    temp = new list;
    tail->pnt = temp;
    temp->obj = item;
    temp->pnt = NULL;
    tail = temp; 
}

//will create a new food object at the provided index
template <class foodGroup>
void foodList<foodGroup>::insert(Food<foodGroup> item, int index){
    Food<foodGroup>* temp = accessItem(index)->pnt;
    accessItem(index)->pnt = new list;
    accessItem(index + 1)->pnt= temp;
}


//will delete the food object at the provided index
template <class foodGroup>
void foodList<foodGroup>::deletion(int index){
    Food<foodGroup>* temp = accessItem(index)->pnt;
    delete *accessItem(index);
    accessItem(index - 1).pnt = temp;
}


//returns a pointer to the list obj at a given position
template <class foodGroup>
typename foodList<foodGroup>::list* foodList<foodGroup>::accessItem(int index){
    //Temporary Variables
    Food<foodGroup>* temp = &head;
    int i = 0;
    //accessing item by iterating through the list until the index is reached
    while(i < index || temp != NULL){
        temp = temp.pnt;
        i++;
    }
    return(temp);
}




//PUBLIC FUNCTION DEFINITIONS :|

//The humble accessor function

//returns food object at index
template<class foodGroup>
Food<foodGroup> foodList<foodGroup>::getFood(int index){
    return(accessItem(index)->obj);
}

//Mutator functions

//sets food object at an existing index
template <class foodGroup>
void foodList<foodGroup>::setFood(int index, Food<foodGroup> newObj){
    accessItem(index)->obj = newObj;
}

//Creates an empty food object
template <class foodGroup>
void foodList<foodGroup>::newFood(){
    //using default constructors for foodgroup
    Food<foodGroup> a;
    //adding empty obj to list
    push_back(a);
}

//Adds a new food object to the end of the list
template <class foodGroup>
void foodList<foodGroup>::newFood(Food<foodGroup> obj){
    push_back(obj);
}

//Inserts a new food object at the index
template <class foodGroup>
void foodList<foodGroup>::newFood(Food<foodGroup> obj, int index){
    insert(obj, index);
}

//Deletes the object at the index
template <class foodGroup>
void foodList<foodGroup>::RemoveItem(int index){
    deletion(index);
}

//Constructor and Destructor Definintion :(

//Constructor
template <class foodGroup>
foodList<foodGroup>::foodList(){
    //by default, tail will point to NULL and head will point to the tail.
    head.pnt = tail;
    tail.pnt = NULL;
}

//Destructor
template <class foodGroup>
foodList<foodGroup>::~foodList(){
    //similar to accessitem but we're destroying EVERYTHING
    //Temporary Variables
    Food<foodGroup>* temp = &head;
    int i = 0;
    while(temp != NULL){
        temp = temp.pnt;
        delete *accessItem(i);
        i++;
    }
}


#endif