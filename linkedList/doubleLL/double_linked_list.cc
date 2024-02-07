
struct Node {
    int data;
    Node *prev;
    Node *next;

    Node(int data) : data{data}, prev{nullptr}, next{nullptr} {}
    Node(int data, Node *prev, Node *next)
        : data{data}, prev{prev}, next{next} {}
    ~Node() { delete next; }
};

class DoubleLinkedList {
    Node *head;
    Node *tail;

  public:
    DoubleLinkedList() : head{nullptr}, tail{nullptr} {}
    ~DoubleLinkedList() { delete head; }

    void addFront(int data) {}
    void addBack(int data) {}
    void addByIndex(int data, int index) {}
};

/* 해당 구조가 효율적인지 아닌지 판단하는 방법
해당 구조를 사용하지 않았을 때에도 똑같은 효율을 낼 수 있는지 판단
ex. addBack()을 tail이 있을 때의 time complexity와 없을 때의
time complexity를 비교해서 판단
 */
