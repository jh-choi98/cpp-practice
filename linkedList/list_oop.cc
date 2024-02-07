#include <exception>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) : data{data}, next{nullptr} {}
    Node(int data, Node *next) : data{data}, next{next} {}
    ~Node() { delete next; }
};

class LinkedList {
    Node *head;
    Node *tail;
    int len;

  public:
    LinkedList() : head{nullptr}, tail{nullptr}, len{0} {}
    ~LinkedList() { delete head; }
    // ************************************************************ add
    void addFront(int data) {
        ++len;
        if (!head && !tail) {
            head = new Node{data};
            tail = head;
            return;
        }

        head = new Node{data, head};
    }
    void addBack(int data) {
        if (!head && !tail) {
            addFront(data);
            return;
        }

        tail->next = new Node{data};
        tail = tail->next;
        ++len;
    }
    Node *getHead() { return head; }
    // client가 linked list의 모든 노드에 직접 접근할 수 있게 해줌.
    // 때문에 client가 주어진 메소드 이외에 직접 주소로 접근해 부적절하게
    // 데이터를 이용할 수 있게 됨.
    // 따라서 좋은 방법이 아님.
    void addByNode(int data, Node *prev) {
        if (!prev) {
            cerr << "prev Node does not exist" << endl;
            return;
        }

        Node *newNode = new Node{data, prev->next};
        prev->next = newNode;
        ++len;
    }
    // client는 linked list의 구조를 모르고 주어진 메소드로만 소통하는 것이
    // 바람직함. 하지만 addByNode는 client가 linked list 구조를 알고 있어야만 쓸
    // 수 있음. client가 linked list의 구조를 알고 접근할 수 있으면
    // 부절적한 행동을 할 수 있음. 따라서 O(1)이라는 장점이 있지만 좋은 방법은
    // 아님.
    int getLength() { return len; }
    void addByIndex(int data, int index) {
        if (index == 0) {
            addFront(data);
            return;
        }

        if (index == len - 1) {
            addBack(data);
            return;
        }

        if (index >= len) {
            cerr << "Invalid Index: larger than the length of the entire list"
                 << endl;
            return;
        }

        Node *cur = head;
        Node *prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = new Node{data, cur};
        ++len;
    } // O(n)

    /*
    Linked List insertion O(1) => map(key: node data) + dynamic array (value:
    node pointers)
    pros => insertion o(1)
    cons => delete / update o(n) bc dynamic array has to be updated
            increase space complexity

    가장 중요한 요구사항이 무엇인지에 따라 가장 효율적인 솔루션을 택한다. 완벽한
    솔루션은 없음.
    */

    // ************************************************************ update
    void update(int data, int index) {
        if (len == 0 && !head && !tail) {
            cerr << "The list is empty" << endl;
            return;
        }
        if (index >= len) {
            cerr << "Invalid Index: larger than the length of the entire list"
                 << endl;
            return;
        }
        // ***********************************************************************
        // exception^ ex. index re-enter, len notification, 빈 리스트에 넣을건지
        // 묻기
        // ++++++ line 104 - 112 메소드 두개로 나누기
        Node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->data = data;
    }
    // ************************************************************ remove
    void removeByIndex(int index) {
        if (len == 0 && !head && !tail) {
            cerr << "The list is empty" << endl;
            return;
        }

        if (index >= len) {
            cerr << "Invalid Index: larger than the length of the entire list"
                 << endl;
            return;
        }

        // --len;
        // int len = this->len;

        Node *cur = head;
        Node *prev = nullptr;

        if (index == 0) {
            Node *temp = cur;
            cur = cur->next;
            temp->next = nullptr;
            if (!cur) {
                int curLen = len - 1;
                if (curLen != 0) {
                    throw exception();
                }
                tail = nullptr;
            }
            head = cur;
            delete temp;
            --len;
            return;

            // head = head->next;
            // cur->next = nullptr;
            // delete cur;
            // if (!len) {
            //     tail = nullptr;
            //     if (head) {
            //         throw exception;
            //     }

            // }
            // return;
        }

        for (int i = 0; i < index; ++i) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == tail) {
            tail = prev;
        }

        prev->next = cur->next;
        cur->next = nullptr;
        delete cur;
        --len;
    }

    void removeByValue(int data) {
        Node *cur = head;
        Node *prev = nullptr;

        while (cur) {
            if (cur->data == data) {
                if (!prev) {
                    Node *temp = cur;
                    cur = cur->next;
                    temp->next = nullptr;
                    if (!cur) {
                        int curLen = len - 1;
                        if (curLen != 0) {
                            throw exception();
                        }
                        tail = nullptr;
                    }
                    head = cur;
                    delete temp;
                    --len;
                    return;
                }

                if (cur == tail) {
                    tail = prev;
                }

                prev->next = cur->next;
                cur->next = nullptr;
                delete cur;
                --len;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    void print() {
        Node *cur = head;

        cout << "[ ";
        while (cur) {
            cout << cur->data;
            cur = cur->next;
            if (cur) {
                cout << " -> ";
            }
        }
        cout << " ]" << endl;
    }
};

class AscendingLinkedList {
    Node *theList;

  public:
    AscendingLinkedList() : theList{nullptr} {}
    ~AscendingLinkedList() { delete theList; }
    void add(int data) {
        Node *cur = theList;
        Node *prev = nullptr;

        if (!cur) {
            theList = new Node{data};
            return;
        }

        while (cur) {
            if (cur->data > data) {
                if (!prev) {
                    theList = new Node{data, cur};
                } else {
                    prev->next = new Node{data, cur};
                }
                return;
            }

            prev = cur;
            cur = cur->next;
        }

        prev->next = new Node{data};
    }

    void print() {
        Node *cur = theList;

        cout << "[ ";
        while (cur) {
            cout << cur->data;
            cur = cur->next;
            if (cur) {
                cout << " -> ";
            }
        }
        cout << " ]" << endl;
    }
};
// User 입장에서 class 디자인

int main() {
    LinkedList list;

    list.addBack(5);
    list.addBack(6);
    list.addBack(7);
    list.getHead()->data = 50;

    list.addFront(4);
    list.addFront(3);

    list.addByIndex(8, 2);
    list.addByIndex(0, 0);
    list.addByIndex(1000, list.getLength() - 1);

    list.update(2, 1);
    list.update(1, list.getLength() - 1);
    list.update(1, 0);

    list.print();
    // list.removeByIndex(0);
    // list.print();
    // cout << "********* Length *********: " << list.getLength() << endl;

    // list.removeByIndex(list.getLength() - 1);
    // list.print();
    // cout << "********* Length *********: " << list.getLength() << endl;

    // list.removeByIndex(3);
    // list.print();
    // cout << "********* Length *********: " << list.getLength() << endl;

    // list.removeByIndex(0);
    // list.print();
    // cout << "********* Length *********: " << list.getLength() << endl;

    // list.update(10000, 1);
    // list.print();

    // cout << "********* Length *********: " << list.getLength() << endl;

    // list.removeByIndex(0);
    // list.print();
    // list.removeByIndex(0);
    // list.print();
    // list.removeByIndex(0);
    // list.print();
    // list.removeByIndex(0);
    // list.print();
    // cout << "********* Length *********: " << list.getLength() << endl;

    // list.update(10000, 0);
    // list.print();
    // cout << "********* Length *********: " << list.getLength() << endl;

    list.removeByValue(1);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
    list.removeByValue(1);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
    list.removeByValue(50);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;

    list.removeByValue(2);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
    list.removeByValue(4);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
    list.removeByValue(8);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
    list.removeByValue(8);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
    list.removeByValue(6);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
    list.removeByValue(7);
    list.print();
    cout << "********* Length *********: " << list.getLength() << endl;
}
