//
//  main.cpp
//  Planet
//
//  Created by Austin Bennett on 7/7/22.
//
/*
 
 Your planet class will be derived from your sphere class.  It should add mass as a private member (with mutator and accessor) along with a constructor and functions to calculate density and acceleration due to gravity at the surface.  Functions for input and display are optional.
 Using this class, write a program that will prompt the user for the radius and mass of a planet.  Your program will display the surface area, density and acceleration due to gravity at the surface.
 */

#include <iostream>
#include "planet.hpp"
#include "input.h"

using namespace std;

int main(int argc, const char * argv[]) {
    double radius = ReadValue<double>("Radius: ");
    double mass = ReadValue<double>("Mass: ");
    
    Planet earth = Planet(radius, mass);
    
    earth.display();
    
    return 0;
}
