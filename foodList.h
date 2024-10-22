/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/21/24
*/
#ifndef FOODLIST_H
#define FOODLIST_H


#include "Food.h"
#include "listNode.h"

//inheriting template from parent class to ensure usability
class foodList{
    private:
    //Creating a linked List
    listNode<Food> head;
    listNode<Food>* tail;

    //function Prototypes
    void push_back(Food);
    void insert(Food, int);
    void deletion(int);
    listNode<Food>* accessItem(int);

    public:
    //constructor
    foodList();

    //Destructor
    ~foodList();

    //Accessor functions
    Food getFood(int);

    //Mutator functions
    void setFood(int, Food);
    void newFood();
    void newFood(Food);
    void newFood(Food, int);
    void RemoveItem(int);

};


//function Definitions :)

//Mostly for internal use, if needed, they can become external

//creates new object
void foodList::push_back(Food item){
    listNode<Food>* temp = tail;
    tail->setPnt(new listNode<Food>);
    tail->getPnt()->setObj(item);
    tail->getPnt()->setPnt(NULL);
    tail = temp;
}

//will create a new food object at the provided index
void foodList::insert(Food item, int index){
    listNode<Food>* temp = accessItem(index)->getPnt();
    accessItem(index)->setPnt(new listNode<Food>);
    accessItem(index + 1)->setPnt(temp);
}


//will delete the food object at the provided index
void foodList::deletion(int index){
    listNode<Food>* temp = accessItem(index)->getPnt();
    delete accessItem(index);
    accessItem(index - 1)->setPnt(temp);
}


//returns a pointer to the list obj at a given position
listNode<Food> *foodList::accessItem(int index){
    //Temporary Variables
    listNode<Food>* temp = &head;
    int i = 0;
    //accessing item by iterating through the list until the index is reached
    while(i < index || temp != NULL){
        temp = temp->getPnt();
        i++;
    }
    return(temp);
}




//PUBLIC FUNCTION DEFINITIONS :|

//The humble accessor function

//returns food object at index
Food foodList::getFood(int index){
    return(accessItem(index)->getObj());
}

//Mutator functions

//sets food object at an existing index
void foodList::setFood(int index, Food newObj){
    accessItem(index)->setObj(newObj);
}

//Creates an empty food object
void foodList::newFood(){
    //using default constructors for foodgroup
    Food a;
    //adding empty obj to list
    push_back(a);
}

//Adds a new food object to the end of the list
void foodList::newFood(Food obj){
    push_back(obj);
}

//Inserts a new food object at the index
void foodList::newFood(Food obj, int index){
    insert(obj, index);
}

//Deletes the object at the index
void foodList::RemoveItem(int index){
    deletion(index);
}

//Constructor and Destructor Definintion :(

//Constructor
foodList::foodList(){
    //by default, tail will point to NULL and head will point to the tail.
    head.setPnt(tail);
    tail->setPnt(NULL);
}

//Destructor
foodList::~foodList(){
    //similar to accessitem but we're destroying EVERYTHING
    //Temporary Variables
    listNode<Food>* temp = &head;
    int i = 0;
    //iteratively deleting list
    while(temp != NULL){
        temp = temp->getPnt();
        delete accessItem(i);
        i++;
    }
}


#endif