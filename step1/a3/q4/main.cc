#include "sphere.h"
#include "point.h"
#include <iostream>
using namespace std;

int main()
{

    Point p1{1, 2, 3};
    Point p2{10, 10, 10};

    cout << p1.getDistance(p2) << endl;

    Sphere s1{0, 0, 0, 1};
    Sphere s2{1, 0, 0, 3};
    Sphere s3{5, 5, 5, 3};
    Sphere s4{1, 2, 3, 3};

    cout << s1.isValid() << endl; // true

    cout << s1.isCollide(s2) << endl; // true
    cout << s1.isCollide(s3) << endl; // false

    cout << p1.isInSphere(s1) << endl; // false
    cout << p1.isInSphere(s4) << endl; // true
}
