#include "abstractBox.h"

struct Node
{
    int data;
    Node *next;

    Node(int data);
    Node(int data, Node *next);
    ~Node();
};

class LLBox : public AbstractBox
{
public:
    LLBox(Node *node);
    ~LLBox();
};
