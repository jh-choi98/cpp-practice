#include "abstractBox.h"
#include "lLBox.h"

int main()
{
    Node *n1 = new Node{0, new Node{3, new Node{0, new Node{3}}}};
    AbstractBox *b1 = new LLBox{n1};

    Node *n2 = new Node{0, new Node{3, new Node{0, new Node{3}}}};
    AbstractBox *b2 = new LLBox{n2};
}
