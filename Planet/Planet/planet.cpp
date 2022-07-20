//
//  planet.cpp
//  Planet
//
//  Created by Austin Bennett on 7/7/22.
//
#include <iostream>
#include <cmath>

#include "planet.hpp"


using namespace std;

double _mass;
double _density;
double _accDueToGravity;

double Planet::getMass() {
    return _mass;
}

void Planet::setMass(double mass) {
    _mass = mass;
}

Planet::Planet(double radius, double mass) {
    _mass = mass;
    setRadius(radius);
    setSurfaceArea(4 * M_PI * (radius * radius));
    setVolume((4/3) * M_PI * (radius * radius * radius));
    _density = _mass / getVolume();
    _accDueToGravity = (9.8 * _mass) / (getRadius() * getRadius());
}

void Planet::display() {
    cout << "Mass: " << _mass << "\n";
    cout << "Density: " << _density << "\n";
    cout << "Acceleration Due To Gravity: " << _accDueToGravity << "\n";
    
}
