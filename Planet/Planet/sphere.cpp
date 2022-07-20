//
//  sphere.cpp
//  Planet
//
//  Created by Austin Bennett on 7/7/22.
//

#include <cmath>

#include "sphere.hpp"

double _radius;
double _surfaceArea;
double _volume;

double Sphere::getRadius() {
    return _radius;
}

double Sphere::getVolume() {
    return _volume;
}

void Sphere::setRadius(double radius) {
    _radius = radius;
}

void Sphere::setSurfaceArea(double surfaceArea){
    _surfaceArea = surfaceArea;
}

void Sphere::setVolume(double volume) {
    _volume = volume;
}

Sphere::Sphere(double radius) {
    _radius = radius;
    _surfaceArea = 4 * M_PI * (radius * radius);
    _volume = (4/3) * M_PI * (radius * radius * radius);
    
}

Sphere::Sphere(){
    
}
