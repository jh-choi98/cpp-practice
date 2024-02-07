#include "node.h"
#include "iostream"
using namespace std;

int main()
{
    Node n{5, 6, Direction::WEST};
    Node n2{7, 8, Direction::NORTH};

    cout << n.getStateValue() << endl;
    cout << n2.getStateValue() << endl;
}
