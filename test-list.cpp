#include <iostream>
#include <string>
#include "LINKEDLIST.h"

int main()
{
    LinkedList list;

    list.insertNode( "test string 0" );
    list.printList();

    if( list.isEmpty() )
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        std::cout << "List size is " << list.getLength() << std::endl;
    }

    list.insertNode( "test string 1" );
    list.insertNode( "test string 2" ); // this should be printed after the first insertion
    list.printList();
    std::cout << "List size is " << list.getLength() << std::endl;

    // test delete
    list.deleteNode(2);
    list.printList();
    std::cout << "List size is " << list.getLength() << std::endl;

    return 0;
}