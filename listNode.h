/*
    Collaborators: Jonathan Salvato
    Program 2
    Date: 10/21/24
*/

#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class listNode{
    private:
    //creating what's needed for a linked list
        T obj;
        listNode* pnt;

    public:
        //Default constructor
        listNode(){
            pnt = NULL;
        }

        //Overloaded constructor
        listNode(T o){
            obj = o;
            pnt = NULL;
        }

        //Another Overload
        listNode(T o, listNode* p){
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
        void setObj(T obj){
            this->obj = obj;
        }

        //sets pointer to next node
        void setPnt(listNode* pnt){
            this->pnt = pnt;
        }
};


#endif