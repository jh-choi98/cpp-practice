#include "abstractCardList.h"
#include "enum.h"

struct Node {
    Card val;
    Node* next;

    Node(Card val) : val{ val }, next{ nullptr } {}
    Node(Card val, Node* next) : val{ val }, next{ next } {}
};

class LLCardList : public AbstractCardList {
    Node* head;

public:
    LLCardList() : head{ nullptr } {}
    LLCardList(Node* head) : head{ head } {}
};