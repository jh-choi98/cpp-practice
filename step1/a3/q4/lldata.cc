#include "lldata.h"

struct Node
{
    int data;
    Node *next;

    Node(int data) : data{data}, next{nullptr} {}
    Node(int data, Node *next) : data{data}, next{next} {}
    ~Node() { delete next; }
};

LLData::LLData(int x, int y, int z, int r)
{
    node = new Node{x, new Node{y, new Node{z, new Node{r, nullptr}}}};
}

LLData::LLData(int x, int y, int z)
{
    node = new Node{x, new Node{y, new Node{z, new Node{0, nullptr}}}};
}

DataValue LLData::getDataValue()
{
    int x = node->data;
    int y = node->next->data;
    int z = node->next->next->data;
    int r = node->next->next->next->data;
    return {x, y, z, r};
}

LLData::~LLData() { delete node; }
