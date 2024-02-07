#include "node.h"
#include <memory>
#include <iostream>
using namespace std;

Node::Node(NodeData data) : data{data}, next{nullptr}
{
}

Node::Node(int x, int y, Direction dir)
{
    data = x;
    next = make_unique<Node>(y);
    next->next = make_unique<Node>(dir);
}

Node::~Node() {}

StateValue Node::getStateValue()
{
    try
    {
        int x = get<int>(data);
        cout << x << endl;
        int y = get<int>(next->data);
        cout << y << endl;
        Direction dir = get<Direction>(next->next->data);
        cout << dir << endl;
        StateValue st{x, y, dir};
        return st;
    }
    catch (bad_variant_access &e)
    {
        cerr << e.what() << endl;
        return {-1, -1, Direction::NORTH};
    }
}

unique_ptr<State> Node::getNewState(int x, int y, Direction dir)
{
    return make_unique<Node>(x, y, dir);
}
