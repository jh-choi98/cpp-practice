#include <cmath>
#include <iostream>

using namespace std;

struct Coord3D
{
    int x, y, z;
};

class AbstractPoint;

class AbstractRadius
{
public:
    virtual bool isValid() = 0;
    virtual int getRadius() = 0;
};

class Sphere
{
    AbstractPoint *center;
    AbstractRadius *radius;

public:
    Sphere(AbstractPoint *c, AbstractRadius *r);
    AbstractPoint *getCenter();
    AbstractRadius *getRadius();
    bool isValid();
    bool doesIncludePoint(AbstractPoint *p);
    bool isCollide(Sphere &other);
    ~Sphere();
};

// *********************** Point
class AbstractPoint
{
public:
    // virtual bool isInSphere(Sphere &s) = 0;
    virtual bool isValid() = 0;
    virtual Coord3D getCoord() = 0;
    virtual float getDistance(AbstractPoint *other) = 0;
    virtual ~AbstractPoint() {}
};

class BasePoint : public AbstractPoint
{
public:
    float computeDistance(Coord3D otherCoord)
    {
        Coord3D data = getCoord();
        int squareDiffX = pow(data.x - otherCoord.x, 2);
        int squareDiffY = pow(data.y - otherCoord.y, 2);
        int squareDiffZ = pow(data.z - otherCoord.z, 2);

        return sqrt(squareDiffX + squareDiffY + squareDiffZ);
    }
};

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next) : data{data}, next{next} {}
    ~Node() { delete next; }
};

class LLPoint : public BasePoint
{
    Node *point;

public:
    LLPoint(int x, int y, int z)
        : point{new Node{x, {new Node{y, new Node{z, nullptr}}}}} {}

    ~LLPoint() { delete point; }

    // bool isInSphere(Sphere &s)
    // {
    //     AbstractPoint *sCenter = s.getCenter();
    //     float distanceToCenter = getDistance(sCenter);
    //     return distanceToCenter <= s.getRadius()->getRadius();
    // }
    // Sphere 기능이 더 자연스러움

    bool isValid()
    {
        int count = 0;
        Node *current = point;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count == 3;
    }

    Coord3D getCoord()
    {
        return {point->data, point->next->data, point->next->next->data};
    }

    float getDistance(AbstractPoint *other)
    {
        return computeDistance(other->getCoord());
    }
};

// *********************** Radius
class LLRadius : public AbstractRadius
{
    Node *radius;

public:
    LLRadius(int r) : radius{new Node{r, nullptr}} {}
    ~LLRadius() { delete radius; }

    bool isValid() { return getRadius() > 0; }
    int getRadius()
    {
        return radius->data;
    }
};
// *********************** Sphere
Sphere::Sphere(AbstractPoint *c, AbstractRadius *r) : center{c}, radius{r} {}
AbstractPoint *Sphere::getCenter()
{
    return center;
}
AbstractRadius *Sphere::getRadius()
{
    return radius;
}
bool Sphere::isValid()
{
    return center->isValid() && radius->isValid();
}
bool Sphere::doesIncludePoint(AbstractPoint *p)
{
    float distanceToCenter = p->getDistance(center);
    return distanceToCenter <= radius->getRadius();
}
bool Sphere::isCollide(Sphere &other)
{
    AbstractPoint *otherCenter = other.getCenter();
    float distanceToOtherCenter = center->getDistance(otherCenter);
    return distanceToOtherCenter < radius->getRadius() + other.getRadius()->getRadius();
}
Sphere::~Sphere()
{
    delete center;
    delete radius;
}

int main()
{
    AbstractPoint *p1 = new LLPoint{1, 2, 3};
    AbstractPoint *p2 = new LLPoint{10, 10, 10};

    cout << p1->getDistance(p2) << endl;

    AbstractPoint *sp1 = new LLPoint{0, 0, 0};
    AbstractRadius *sr1 = new LLRadius{1};
    Sphere s1{sp1, sr1};

    AbstractPoint *sp2 = new LLPoint{1, 0, 0};
    AbstractRadius *sr2 = new LLRadius{3};
    Sphere s2{sp2, sr2};

    AbstractPoint *sp3 = new LLPoint{5, 5, 5};
    AbstractRadius *sr3 = new LLRadius{3};
    Sphere s3{sp3, sr3};

    AbstractPoint *sp4 = new LLPoint{1, 2, 3};
    AbstractRadius *sr4 = new LLRadius{3};
    Sphere s4{sp4, sr4};

    cout << s1.isValid() << endl; // true

    cout << s1.isCollide(s2) << endl; // true
    cout << s1.isCollide(s3) << endl; // false

    // cout << p1->isInSphere(s1) << endl; // false
    // cout << p1->isInSphere(s4) << endl; // true
}
