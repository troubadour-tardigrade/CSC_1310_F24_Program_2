/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/21/24
*/

#ifndef LISTNODE_H
#define LISTNODE_H
<<<<<<< Updated upstream
#include <iostream>

template <typename T>
class listNode{
    private:
    //creating what's needed for a linked list
=======

template <typename foodGroup>
class listNode{
    private:
    //creating the node value and next node pointer 
>>>>>>> Stashed changes
        T obj;
        listNode* pnt;

    public:
        //Default constructor
        listNode(){
            pnt = NULL;
        }

        //Overloaded constructor
<<<<<<< Updated upstream
        listNode(T o){
=======
        listNode(foodGroup o){
>>>>>>> Stashed changes
            obj = o;
            pnt = NULL;
        }

        //Another Overload
<<<<<<< Updated upstream
        listNode(T o, listNode* p){
=======
        listNode(foodGroup o, listNode* p){
>>>>>>> Stashed changes
            obj = o;
            pnt = p;
        }

        //Destructor
        ~listNode(){
            //there really doesn't need to be anything here
        }


        //Accessors

        //returns data in node
        T getObj(){
            return(obj);
        }

        //returns pointer to next node
        listNode* getPnt(){
            return(pnt);
        }

        //Mutators

        //sets data in node
<<<<<<< Updated upstream
        void setObj(T obj){
=======
        void setObj(foodGroup obj){
>>>>>>> Stashed changes
            this->obj = obj;
        }

        //sets pointer to next node
<<<<<<< Updated upstream
        void setPnt(listNode<T>* pnt){
=======
        void setPnt(listNode* pnt){
>>>>>>> Stashed changes
            this->pnt = pnt;
        }
};


#endif