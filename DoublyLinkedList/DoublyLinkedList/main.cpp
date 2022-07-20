#include <iostream>

#include "doublylinkedlist.hpp"
#include "input.h"

using namespace std;

int main()
{
    DoublyLinkedList dll = DoublyLinkedList();
    
    cout << "1. Add Value" << endl;
    cout << "2. Delete Value" << endl;
    cout << "3. Display List (forward)" << endl;
    cout << "4. Display List (backward)" << endl;
    cout << "5. Quit" << endl;
    
    int choice = ReadValue<int>("Enter Your Choice: ");
    
    do {
        if (choice == 1) {
            dll.Insert(ReadValue<double>("Enter Your Data: "));
        } else if (choice == 2) {
            dll.Remove(ReadValue<int>("Enter The Index: "));
        } else if (choice == 3) {
            dll.DisplayFB();
        } else if (choice == 4) {
            dll.DisplayBF();
        }  else if (choice == 5) {
            break;
        } else {
            cout << "Try Again" << endl;
        }
//        cout << "1. Add Value" << endl;
//        cout << "2. Delete Value" << endl;
//        cout << "3. Display List (forward)" << endl;
//        cout << "4. Display List (backward)" << endl;
//        cout << "5. Quit" << endl;
        
        choice = ReadValue<int>("Enter Your Choice: ");

    } while (choice != 5);
    return 0;
}
