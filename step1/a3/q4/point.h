#ifndef __POINT_H__
#define __POINT_H__

#include "data.h"
#include "lldata.h"
#include "sphere.h"
#include <cmath>

class Sphere;
class Point
{
    Data *coords;

public:
    Point(Data *coords);
    // Point(int x, int y, int z);
    bool isInSphere(Sphere &s);
    float getDistance(Point &other);
    ~Point();
};

#endif
