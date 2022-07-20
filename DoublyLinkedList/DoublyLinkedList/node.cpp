//
//  node.cpp
//  DoublyLinkedList
//
//  Created by Austin Bennett on 7/18/22.
//

#include "node.hpp"

Node::Node(double value) {
    data = value;
}

Node::~Node() {
    delete this;
}
