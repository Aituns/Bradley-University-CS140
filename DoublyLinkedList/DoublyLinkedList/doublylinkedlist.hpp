//
//  doublylinkedlist.hpp
//  DoublyLinkedList
//
//  Created by Austin Bennett on 7/18/22.
//
/*
 Constructor
 Destructor
 Insert function
 Remove function
 Accessor function
 Mutator function
 */

#ifndef doublylinkedlist_hpp
#define doublylinkedlist_hpp

#include <stdio.h>

#include "node.hpp"

class DoublyLinkedList {
private:
    Node* front;
    Node* back;
public:
    DoublyLinkedList();
    //~DoublyLinkedList();
    void Insert(double data);
    void Remove(int index);
    void DisplayFB();
    void DisplayBF();
    void Mutate(int index, double value);
};

#endif /* doublylinkedlist_hpp */
