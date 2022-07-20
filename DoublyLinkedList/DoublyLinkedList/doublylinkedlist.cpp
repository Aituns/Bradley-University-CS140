//
//  doublylinkedlist.cpp
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
#include <iostream>

#include "doublylinkedlist.hpp"

using namespace::std;

DoublyLinkedList::DoublyLinkedList() {
    front = NULL;
    back = NULL;
}

void DoublyLinkedList::Insert(double data) {
    Node* newNode = new Node(data);
    
    bool isEmpty = (front == NULL);
    
    if (isEmpty) {
        front = newNode;
        back = newNode;
        newNode -> prev = NULL;
        newNode -> next = NULL;
    } else {
        back -> next = newNode;
        newNode -> prev = back;
        newNode -> next = NULL;
        back = newNode;
    }
}

void DoublyLinkedList::Remove(int index) {
    Node* temp = front;
    
    int count = 0;
    
    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp -> next;
    }
    
    if (temp == front) {
        temp -> next = front;
        front -> prev = NULL;
    } else if (temp == back) {
        temp -> prev = back;
        back -> next = NULL;
    } else {
        Node* a = temp -> prev;
        Node* b = temp -> next;
        b -> prev = a;
        a -> next = b;
    }
    
    free(temp);
    
    return;
}

void DoublyLinkedList::DisplayFB() {
    Node* temp = front;
    
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

void DoublyLinkedList::DisplayBF() {
    Node* temp = back;
    
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> prev;
    }
    cout << "NULL" << endl;
}

void DoublyLinkedList::Mutate(int index, double value) {
    Node* temp = front;
    
    for (int i = 0; temp != NULL && i < index; i++) {
          temp = temp->next;
    }
    temp -> data = value;
}
