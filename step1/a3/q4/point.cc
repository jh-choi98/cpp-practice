#include "point.h"
#include <iostream>

using namespace std;

Point::Point(Data *coords) : coords{coords} {}
// Point::Point(int x, int y, int z)
// {
//     coords = new LLData(x, y, z);
// }

float Point::getDistance(Point &other)
{
    DataValue p1 = coords->getDataValue();
    DataValue p2 = other.coords->getDataValue();
    int squareDiffX = pow(p2.x - p1.x, 2);
    int squareDiffY = pow(p2.y - p1.y, 2);
    int squareDiffZ = pow(p2.z - p1.z, 2);

    return sqrt(squareDiffX + squareDiffY + squareDiffZ);
}
bool Point::isInSphere(Sphere &s)
{
    DataValue sd = s.getSphereData()->getDataValue();

    Point p{sd.x, sd.y, sd.z};
    float distance = getDistance(p);

    return sd.r > distance;
}
Point::~Point() { delete coords; }
