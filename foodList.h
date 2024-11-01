/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/21/24
*/
#ifndef FOODLIST_H
#define FOODLIST_H


#include "Food.h"
#include "listNode.h"
#include <iostream>

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
    void mergeSort(foodList*, int, int, bool);
    void merge(foodList*, int, int, int, bool);

    public:
    //constructor
    foodList();

    //Destructor
    ~foodList();

    //Accessor functions
    Food getFood(int);
    listNode<Food>* peek(int);

    //Output operator
    friend std::ostream& operator<<(std::ostream& os, foodList& list){
        listNode<Food>* index = &list.head;
        int i = 0;
        while(index != NULL){
            os << "\n\nFood Type:\t" << index->getObj().getName();
            os << "\nFood Size:\t" << index->getObj().getSize();
            os << "\nFood Price:\t" << index->getObj().getPrice();
            os << "\nFood Calories:\t" << index->getObj().getCalories();
            index = index->getPnt();
            i++;
        }
        return os;
    }

    //Mutator functions
    void setFood(int, Food);
    void newFood();
    void newFood(Food);
    void newFood(Food, int);
    void RemoveItem(int);
    void sortAsc();
    void sortDec();

};


//function Definitions :)

//Mostly for internal use, if needed, they can become external

//creates new object
void foodList::push_back(Food item){

    tail->setPnt(new listNode<Food>);
    tail->getPnt()->setObj(item);
    tail->getPnt()->setPnt(NULL);
    tail = tail->getPnt();
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
    while(i < index || temp->getPnt() != NULL){
        temp = temp->getPnt();
        i++;
    }

    return(temp);
}

//To make recursion easier within context, definfining a seperate mergesort function
void foodList::mergeSort(foodList* list, int lower, int upper, bool asc = 0){
    int midpnt = 0;
    static int r = 0;
    r++;
    if(lower < upper){
        midpnt = (upper + lower) / 2;
        //splitting to lowest elements
        mergeSort(list, lower, midpnt, asc);
        mergeSort(list, midpnt + 1, upper, asc);
        //merging based on calorie size of each element
        //using a bool to define ascending or descending order, where 0/false is ascending and 1/true is descending
        
        merge(list, lower, midpnt, upper, asc);
    }
}

void foodList::merge(foodList* list, int lower, int mid, int upper, bool asc){
    int mergeSize = upper - lower + 1;
    int lowPos(lower), mergePos(0), upPos(mid + 1);

    //creating a new list the size of the input
    foodList* mergedList = new foodList;
    for(int i = 0; i < mergeSize - 1; i++){
        mergedList->newFood();
    }
    //sorting ascending or descending
    if(asc == 0){
        while(lowPos <= mid && upPos <= upper){
            if(list->getFood(lowPos).getCalories() < list->getFood(upPos).getCalories()){
                mergedList->setFood(mergePos, list->getFood(lowPos));
                lowPos++;
            }else{
                mergedList->setFood(mergePos, list->getFood(upPos));
                upPos++;
            }
            mergePos++;
        }

        while(lowPos <= mid){
            mergedList->setFood(mergePos, list->getFood(lowPos));
            lowPos++;
            mergePos++;
        }

        while(upPos <= upper){
            mergedList->setFood(mergePos, list->getFood(upPos));
            upPos++;
            mergePos++;
        }
        for(int j = 0; j < mergeSize; j++){
            list->accessItem(j)->setObj(mergedList->getFood(j));
        }
    }else{
        while(lowPos <= mid && upPos <= upper){
            if(list->getFood(lowPos).getCalories() > list->getFood(upPos).getCalories()){
                mergedList->setFood(mergePos, list->getFood(lowPos));
                lowPos++;
            }else{
                mergedList->setFood(mergePos, list->getFood(upPos));
                upPos++;
            }
            mergePos++;
        }

        while(lowPos <= mid){
            mergedList->setFood(mergePos, list->getFood(lowPos));
            lowPos++;
            mergePos++;
        }

        while(upPos <= upper){
            mergedList->setFood(mergePos, list->getFood(upPos));
            upPos++;
            mergePos++;
        }
        for(int j = 0; j < mergeSize; j++){
            list->accessItem(j)->setObj(mergedList->getFood(j));
        }
    }

}



//PUBLIC FUNCTION DEFINITIONS :|

//The humble accessor functions

//returns food object at index
Food foodList::getFood(int index){
    return(accessItem(index)->getObj());
}

//returns the pointer to the next object in the list (NULL if at the end)
listNode<Food>* foodList::peek(int index){
    return(accessItem(index)->getPnt());
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

//Sorts the array in ascending order based on Calorie values
void foodList::sortAsc(){
    //using a mergesort algorithm

    listNode<Food>* index = &head;
    int size;

    //start by finding the size of the list
    for(int i = 0; index->getPnt() != NULL; i++){
        size = i;
        index = index->getPnt();
    }
    mergeSort(this, 0, size, 0);
}


//Sorts the array in descending order based on Calorie values
void foodList::sortDec(){
    //using a mergesort algorithm

    listNode<Food>* index = &head;
    int size;

    //start by finding the size of the list
    for(int i = 0; index->getPnt() != NULL; i++){
        size = i;
        index = index->getPnt();
    }
    mergeSort(this, 0, size, 1);
}

//Constructor and Destructor Definintion :(

//Constructor
foodList::foodList(){
    //by default, head points to NULL and Tail points to head
    head.setPnt(NULL);
    tail = &head;
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