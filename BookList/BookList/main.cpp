//
//  main.cpp
//  BookList
//
//  Created by Austin Bennett on 6/22/22.
//

/*
 Create a C++ program that will keep a list of books.  Your program must meet the following criteria:
ø   The program will provide the user with a menu to add names to the list, delete a name from the list (searching by title), display the list in it's entirety
√   The list of books will be stored as a dynamically allocated array of strings.  The strings can be either STL strings or C style strings
√   The list must be stored in a class
√   There must be an operator overload created for the stream extraction operator that will handle the output of the list
√   You must provide a copy constructor for the class that will allow the programmer to set one class object equal to another
√   There must be a function to allow the list size to be increased without losing data that has been previously stored in the list.
 */

#include <iostream>

#include "list.h"
#include "input.h"

// The program will provide the user with a menu to add names to the list, delete a name from the list (searching by title), display the list in it's entirety
void menu(List books) {
    int choice;
    bool inProgram = true;
    while (inProgram != false){
    std::cout << "*******************************\n";
    std::cout << " 1 - Add Item.\n";
    std::cout << " 2 - Delete Item.\n";
    std::cout << " 3 - Display List.\n";
    std::cout << " 4 - Exit.\n";

    choice = ReadValue<int>("Enter your choice and press return: ");

    switch (choice) {
        case 1: // Add Item
            books.Add();
            break;
        case 2: // Delete Item
            books.Remove(ReadValue<std::string>("Enter Book to Remove: "));
            break;
        case 3: // Display List
            // There must be an operator overload created for the stream extraction operator that will handle the output of the list
            std::cout << books;
            break;
        case 4:
            std::cout << "End of Program.\n";
            inProgram = false;
            break;
        default:
            std::cout << "Not a Valid Choice. \n";
            std::cout << "Choose again.\n";
            std::cin >> choice;
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    // The list must be stored in a class
    List books;
    
    menu(books);
    
    // You must provide a copy constructor for the class that will allow the programmer to set one class object equal to another
    List books2 = List(books);
    
    return 0;
}


