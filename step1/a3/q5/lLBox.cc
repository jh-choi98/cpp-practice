#include "lLBox.h"

Node::Node(int data) : data{data}, next{nullptr} {}
Node::Node(int data, Node *next) : data{data}, next{next} {}
Node::~Node() { delete next; }

LLBox::LLBox(Node *node)
    : AbstractBox{node->data, node->next->data, node->next->next->data, node->next->next->next->data} {}

LLBox::~LLBox() {}
