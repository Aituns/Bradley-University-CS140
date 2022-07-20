//
//  main.cpp
//  Midterm
//
//  Created by Austin Bennett on 7/7/22.
//
/*
 Redo question number 3 with these changes. Instead of dynamically allocating an array to store the data, your program will will an STL array. Even numbers will also be copied to an STL array. The input of the data and copying of even numbers will require the program to start at the beginning of the array and walk thorugh the values to the end. This must be done using iterators.
 */

#include <iostream>
#include <array>
#include <iterator>
#include <cmath>

#include "input.h"

using namespace std;

int main() {
    array<int, 5> arr;
    array<int, 5> evenArr;
    
    array<int, 5>::iterator ptr;
    array<int, 5>::iterator evenPtr = evenArr.begin();
    
    for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
        *ptr = ReadValue<int>("Value: ");
    }
    
//    for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
//        cout << *ptr;
//    }
    
    for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
        if (*ptr % 2 == 0) {
            *evenPtr = *ptr;
            evenPtr++;
        } else {
            *evenPtr = NULL;
        }
    }
    
    for (evenPtr = evenArr.begin(); *evenPtr != NULL; evenPtr++) {
        cout << *evenPtr;
    }

    return 0;
}
