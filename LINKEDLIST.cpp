/***********************************************
*   IMPLEMENTATION FILE OF LINKED LIST CLASS
***********************************************/

#include "LINKEDLIST.h"

LinkedList::LinkedList()
{
    head = NULL;
    length = 0;
}


LinkedList::LinkedList(LinkedList& obj)
{

}

LinkedList::~LinkedList()
{
    delete head;
}

int LinkedList::getLength()
{
    return length;
}

void LinkedList::insertNode(std::string data)
{
    // create node that will store the data
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;

    // conditions on inserting a new node
    if( head == NULL )  // if list is empty
    {
        head = temp;
    }
    else if( !isEmpty() )   // if the list isn't empty
    {
        // node to traverse head ptr to end
        node* p = new node;
        p = head;   // assign same address as head node

        // traverse the list with the temp ptr, p, to end of head(list)
        while( p->next != NULL )
        {
            p = p->next;
        }
        p->next = temp; // link temp and last node of list
    }
    length++;
}

void LinkedList::deleteNode(int index)
{
    if( !isEmpty() )
    {
        if( index == 1 )    // first node is being deleted
        {
            node* temp = new node;
            temp = head;
            head = head->next;
            delete temp;
        }
        else    // any node after the first node is deleted
        {
            node* temp = new node;
            node* p = new node;

            temp = head->next;
            p = head;
            
            // traverse to index that will be deleted
            for( int i = 0; i < index - 1; i++ )
            {
                temp = temp->next;
                p = p->next;
            }

            // create new node to hold data
            delete p;
            node* q = new node;
            q = head;
            for( int i = 0; i < index - 1; i++ )
            {
                q = q->next;
            }
            q->next = temp;
        }
    }
    else    // list is empty
    {
        std::cout << "List is empty." << std::endl;
    }
    length--;
}

bool LinkedList::searchList(std::string data)
{
    bool foundFlag;
    if( isEmpty() )
    {
        std::cout << "No tasks." << std::endl;
    }
    else
    {
        node* temp = new node;
        temp = head;    // assign the memory of head to temp to traverse
        while( temp->data != data )
        {
            temp = temp->next;
            if( temp->data == data )
            {
                foundFlag = true;
            }
            else
            {
                foundFlag = false;
            }
        }
    }
    return foundFlag;
}

bool LinkedList::isEmpty()
{
    return length == 0;
}

void LinkedList::printList()
{
    int i = 1;
    node* temp = head;
    while( temp != NULL )
    {
        std::cout << i << ". " << temp->data << std::endl;
        temp = temp->next;
        i++;
    }
}