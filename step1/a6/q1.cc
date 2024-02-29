#include <iostream>
#include <optional>

using namespace std;

class AbstractIntList {
  public:
    virtual void addFront(int data) = 0;
    virtual void sort() = 0;
    virtual int getLength() = 0;
};

struct Node {
    int data;
    Node *next;

  public:
    Node(int d) : data{d}, next{nullptr} {}
    Node(int d, Node *n) : data{d}, next{n} {}
    ~Node() { delete next; }
};

class LLIntList : public AbstractIntList {
    Node *head;
    int len;

  public:
    LLIntList() : head{nullptr} {}
    ~LLIntList() { delete head; }

    void addFront(int data) {
        Node *newNode = new Node{data};
        if (!head) {
            head = newNode;
            ++len;
            return;
        }
        newNode->next = head;
        head = newNode;
        ++len;
    }
    void sort() {}
    int getLength() { return len; }
};

class IntListProcessor {
  public:
    virtual optional<int> getElementByIndex(AbstractIntList *list,
                                            int index) = 0;
    virtual AbstractIntList *zip(AbstractIntList *l1, AbstractIntList *l2) = 0;
    virtual AbstractIntList *buildXorIntList(AbstractIntList *l1,
                                             AbstractIntList *l2) = 0;
};

class LLIntListProcessor : public IntListProcessor {
  public:
    std::optional<int> getElementByIndex(AbstractIntList *list, int index) {
        if (index >= list->getLength()) {
            cerr << "[ERROR] Invalid Index: The given index should be less "
                    "than the length of the list"
                 << endl;
            return;
        }
        }
    AbstractIntList *zip(AbstractIntList *l1, AbstractIntList *l2) {}
    AbstractIntList *buildXorIntList(AbstractIntList *l1, AbstractIntList *l2) {
    }
};
