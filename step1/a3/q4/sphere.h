#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "data.h"
#include "lldata.h"
#include "point.h"

class Sphere
{
    Data *sphereData;

public:
    Sphere(int x, int y, int z, int r);
    Sphere(Data *sphereData);
    Data *getSphereData();
    bool isValid();
    bool isCollide(Sphere &other);
    ~Sphere();
};

#endif
