//
//  node.hpp
//  DoublyLinkedList
//
//  Created by Austin Bennett on 7/18/22.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>

struct Node {
public:
    double data;
    struct Node *prev;
    struct Node *next;
    Node(double value);
    ~Node();
};

#endif /* node_hpp */
