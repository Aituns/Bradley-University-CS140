//
//  planet.hpp
//  Planet
//
//  Created by Austin Bennett on 7/7/22.
//

#ifndef planet_hpp
#define planet_hpp

#include <stdio.h>
#include "sphere.hpp"

class Planet: private Sphere {
    private:
        double _mass;
        double _density;
        double _accDueToGravity;
    public:
        double getMass();
        void setMass(double mass);
        Planet(double radius, double mass);
        void display();
};

#endif
