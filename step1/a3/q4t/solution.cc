// AbstractPoint -> LLPoint, ArrayPoint...
// AbstractRadius -> LLR...
// Sphere
//      Point, Radius

// AbstractPoint: virtual methods-> layerClass -> concreteClass:

// Abstract Class는 인터페이스
#include <cmath>
#include <iostream>

using namespace std;

class Sphere;

class AbstractPoint
{
protected:
    int x, y, z; // <<<<<<<< 이렇게 가능? 아니면 struct로??
    // subclass의 ctor를 이용해서 x, y, z를 initialize시키고 abstract class에서
    // 모든 method를 implement하면 코드 양이 줄어드는데 가능한 방법??

    /*
    사용하면 안됨
    1. data structure를 사용하는 의미가 사라짐
        data structure를 사용하는 이유가 존재하는데 그것을 무시함
    2. data structure의 construction을 client에게 맡겨서 구조 노출

    By 1, 2 추상화의 이유 사라짐
    */
public:
    AbstractPoint(int x, int y, int z) : x{x}, y{y}, z{z} {}
    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
    bool isInSphere(Sphere &s);
    float getDistance(AbstractPoint *other)
    {
        int squareDiffX = pow(x - other->getX(), 2);
        int squareDiffY = pow(y - other->getY(), 2);
        int squareDiffZ = pow(z - other->getZ(), 2);

        return sqrt(squareDiffX + squareDiffY + squareDiffZ);
    }
    virtual ~AbstractPoint() = 0;
};

AbstractPoint::~AbstractPoint() {}

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next) : data{data}, next{next} {}
    ~Node() { delete next; }
};

class LLPoint : public AbstractPoint
{
    Node *point;

public:
    LLPoint(Node &node)
        : AbstractPoint{node.data, node.next->data, node.next->next->data}
    {
    }
    LLpoint(int x, int y, int z): point(new Node{
        x, Node
        {
            y, New Node { z }
        }}
} {}
~LLPoint() {}
}
;

class AbstractRadius
{
protected:
    int r;

public:
    AbstractRadius(int r) : r{r} {}
    int getRadius() { return r; }
    virtual ~AbstractRadius() = 0;
};
AbstractRadius::~AbstractRadius() {}

class LLRadius : public AbstractRadius
{
public:
    LLRadius(Node &node) : AbstractRadius{node.data} {}
    ~LLRadius() {}
};

class Sphere
{
    AbstractPoint *center;
    AbstractRadius *radius;
    // reference로 polymorphism 가능?
public:
    Sphere(AbstractPoint *c, AbstractRadius *r) : center{c}, radius{r} {}
    AbstractPoint *getCenter() { return center; }
    AbstractRadius *getRadius() { return radius; }
    bool isValid() { return radius->getRadius() > 0; }
    bool isCollide(Sphere &other)
    {
        return center->getDistance(other.getCenter()) < radius->getRadius() + other.getRadius()->getRadius();
    };
    ~Sphere()
    {
        delete center;
        delete radius;
    }
};

bool AbstractPoint::isInSphere(Sphere &s)
{
    return getDistance(s.getCenter()) < s.getRadius()->getRadius();
}

int main()
{
    Node np1{1, new Node{2, new Node{3, nullptr}}};
    Node np2{10, new Node{10, new Node{10, nullptr}}};
    AbstractPoint *p1 = new LLPoint{np1};
    AbstractPoint *p2 = new LLPoint{np2};

    cout << p1->getDistance(p2) << endl;

    Node nsp1{0, new Node{0, new Node{0, nullptr}}};
    Node nsr1{1, nullptr};
    AbstractPoint *sp1 = new LLPoint{nsp1};
    AbstractRadius *sr1 = new LLRadius{nsr1};
    Sphere s1{sp1, sr1};

    Node nsp2{1, new Node{0, new Node{0, nullptr}}};
    Node nsr2{3, nullptr};
    AbstractPoint *sp2 = new LLPoint{nsp2};
    AbstractRadius *sr2 = new LLRadius{nsr2};
    Sphere s2{sp2, sr2};

    Node nsp3{5, new Node{5, new Node{5, nullptr}}};
    Node nsr3{3, nullptr};
    AbstractPoint *sp3 = new LLPoint{nsp3};
    AbstractRadius *sr3 = new LLRadius{nsr3};
    Sphere s3{sp3, sr3};

    Node nsp4{1, new Node{2, new Node{3, nullptr}}};
    Node nsr4{3, nullptr};
    AbstractPoint *sp4 = new LLPoint{nsp4};
    AbstractRadius *sr4 = new LLRadius{nsr4};
    Sphere s4{sp4, sr4};

    cout << s1.isValid() << endl; // true

    cout << s1.isCollide(s2) << endl; // true
    cout << s1.isCollide(s3) << endl; // false

    cout << p1->isInSphere(s1) << endl; // false
    cout << p1->isInSphere(s4) << endl; // true
}

class Point
{
    int x, y, z;

public:
    Point(int x, int y, int z);
};

int main()
{
    Point p1{1, 2, 3};
    Point p2{3, 4, 5};
}
