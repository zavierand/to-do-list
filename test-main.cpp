#include <iostream>
#include <string>
#include "LINKEDLIST.h"

/* function prototypes */
void printMenu();

int main()
{
    // list instantiation
    LinkedList todo;

    // store user input
    int menuInput;
    int listNum;
    std::string task;

    // do-while loop to run program
    std::cout << "\n\t\tTo-Do List" << std::endl;
    do
    {
        printMenu();
        std::cin >> menuInput;
        switch( menuInput )
        {
            case 1:
                std::cout << "Enter the task to be added: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, task);
                todo.insertNode(task);
                std::cout << "Task added to list." << std::endl;
                break;
            case 2:
                todo.printList();
                std::cout << "Which task number would you like to delete" << std::endl;
                std::cin >> listNum;
                todo.deleteNode(listNum);
                std::cout << "Task deleted from list." << std::endl;
                break;
            case 3:
                std::cout << "Search for a task:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, task);
                todo.insertNode(task);
                if( todo.searchList(task) )
                {
                    std::cout << "Task on the list" << std::endl;
                }
                else
                {
                    std::cout << "Task not yet on the list" << std::endl;
                }
                break;
            case 4:
                std::cout << "Current To-Do List: " << std::endl;
                todo.printList();
                break;
            case 6:
                std::cout << "Bye-bye!" << std::endl;
                break;
        }

    }
    while( menuInput != 6 );

    return 0;
}

/* function defintions */
void printMenu()
{
    std::cout << "\t\t*** MENU ***" << std::endl 
    << "Type the number of the action desired." << std::endl
    << "1. Add a task." << std::endl
    << "2. Delete a task." << std::endl
    << "3. Search for a task." << std::endl
    << "4. Show my current list." << std::endl
    << "5. Edit List" << std::endl
    << "6. Quit." << std::endl;
}