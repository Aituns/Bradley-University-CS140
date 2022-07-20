//
//  sphere.hpp
//  Planet
//
//  Created by Austin Bennett on 7/7/22.
//

#ifndef sphere_hpp
#define sphere_hpp

#include <stdio.h>

class Sphere {
    private:
        double _radius;
        double _surfaceArea;
        double _volume;
    public:
        double getRadius();
        double getVolume();
        void setRadius(double radius);
        void setSurfaceArea(double surfaceArea);
        void setVolume(double volume);
        Sphere(double radius);
        Sphere();
};

#endif /* sphere_hpp */
