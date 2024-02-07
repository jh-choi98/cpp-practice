#include "sphere.h"

Sphere::Sphere(int x, int y, int z, int r)
{
    sphereData = new LLData(x, y, z, r);
}
Sphere::Sphere(Data *sphereData) : sphereData{sphereData} {}
Sphere::~Sphere() { delete sphereData; }
Data *Sphere::getSphereData()
{
    return sphereData;
}

bool Sphere::isValid()
{
    int r = sphereData->getDataValue().r;
    return r > 0;
}
bool Sphere::isCollide(Sphere &other)
{
    DataValue sd1 = sphereData->getDataValue();
    DataValue sd2 = other.sphereData->getDataValue();

    Point p1{sd1.x, sd1.y, sd1.z};
    Point p2{sd2.x, sd2.y, sd2.z};

    return sd1.r + sd2.r >= p1.getDistance(p2);
}
