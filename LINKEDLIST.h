/*************************************
*   Class definition of linked list  *
*************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

struct node
{
    std::string data;
    node* next;
};

class LinkedList
{
    private:
        node* head;
        int length;

    public:
        /* Constructor, Copy Constructor, & Destructor */
        LinkedList();
        LinkedList(LinkedList&);
        ~LinkedList();

        /* methods to:
        *insert into the list
        *delete from the list
        *search the list */

        int getLength();

        void insertNode(std::string);
        void deleteNode(int);
        bool searchList(std::string);

        bool isEmpty();
        void printList();
};

#endif