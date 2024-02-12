#include <iostream>
using namespace std;

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
    int len;

  public:
    DoubleLinkedList() : head{nullptr}, tail{nullptr}, len{0} {}
    ~DoubleLinkedList() { delete head; }

    int getLength() { return len; }

    // ************************************************************ Add
    // *****************************************************************
    // Ctor에서 가능한지 시도해보기 **********************
    void addFront(int data) {
        Node *newNode = new Node{data, nullptr, head};
        if (!len && !head && !tail) {
            head = newNode;
            tail = head;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++len;
    }
    void addBack(int data) {
        Node *newNode = new Node{data, tail, nullptr};
        if (!len && !head && !tail) {
            addFront(data);
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++len;
    }
    void addByIndex(int data, int index) {
        Node *cur = head;
        if (index == 0) {
            addFront(data);
            return;
        }

        if (index == len - 1) {
            addBack(data);
            return;
        }

        Node *newNode = new Node{data};

        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;

        ++len;
    }

    // ************************************************************ Update
    void update(int data, int index) {
        if (!len && !head && !tail) {
            cerr << "The list is empty" << endl;
            return;
        }

        if (index >= len) {
            cerr << "Invalid Index" << endl;
            return;
        }

        if (index == len - 1) {
            tail->data = data;
            return;
        }

        Node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->data = data;
    }

    void print() {
        cout << "[ ";
        Node *cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) {
                cout << " -> ";
            }
            cur = cur->next;
        }
        cout << " ]" << endl;
    }

    // ************************************************************ Remove
    /*
    1. Linked list에 대한 설명 - audience의 수준에 따라 판단
        Linked List is the chain of pointers
    2. 내 코드 design에 대해서 설명
        - Design의 핵심 아이디어
            - Data structure의 디자인
            struct Node {
                int val;
                // For the simplicity, I'll just assume the data type stored in
    a node is integer;
                 Node *prev;
                 Node *next;

                ~Node{ delete next;}
            }

            // I'll define a wrapper class to avoid the use of double pointer
            class LinkedList {
                Node *head;
                Node *tail;
                int len;
            public:
                LinkedList(): head{nullptr}, tail{nullptr} {}

                void removeByIndex(int index) {
                    // edge cases


                    // remove first node

                    // remove last node

                    // remove any node in the middle
                }
            };


    */
    void removeByIndex(int index) {
        // edge cases
        if (index < 0) {
            cerr << "Invalid index: less than 0" << endl;
            return;
        }

        if (!head && !tail) {
            cerr << "The list is empty" << endl;
            return;
        }

        if (index >= len) {
            cerr << "Invalid index: larger than the length of the entire list"
                 << endl;
            return;
        }

        // remove first node
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            temp->next = nullptr;
            delete temp;
            return;
        }

        // remove last node
        if (index == len - 1) {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return;
        }

        // remove any node in the middle
        Node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->next = nullptr;
        delete cur;
    }
};

int main() {
    DoubleLinkedList l1;
    DoubleLinkedList l2;
    l1.print();
    l1.addFront(5);
    l1.addFront(4);
    l1.addFront(3);
    l1.addFront(2);
    l1.print();

    l1.addBack(9);
    l1.addBack(10);
    l1.addBack(11);
    l1.addBack(12);
    l1.print();
    l2.addBack(1);
    l2.print();

    l1.addByIndex(1, 0);
    l1.addByIndex(10000, l1.getLength() - 1);
    l1.addByIndex(6, 5);
    l1.addByIndex(7, 6);
    l1.addByIndex(8, 7);
    l1.print();

    l1.update(0, 0);
    l1.update(5, l1.getLength() - 1);
    l1.update(500, 3);
    l1.print();
}

/* 해당 구조가 효율적인지 아닌지 판단하는 방법
해당 구조를 사용하지 않았을 때에도 똑같은 효율을 낼 수 있는지 판단
ex. addBack()을 tail이 있을 때의 time complexity와 없을 때의
time complexity를 비교해서 판단
 */

// ListNode *reverseList(ListNode *head) {
//     // Base case: if the current head is nullptr, return nullptr
//     if (!head) {
//         return nullptr;
//     }

//     // Initialize newHead to the current head
//     ListNode *newHead = head;

//     // If the current head has a next node,
//     // make a recursive call to reverse the rest of the list
//     if (head->next) {

//         // 이 단계를 통해 newHead는 마지막 노드를 가리키게 된다.
//         newHead = reverseList(head->next);

//         // After the recursive call returns,
//         // update the next pointer of the next node to point to the
//         current head
//         // 현재 노드의 다음 노드의 next 포인터를 현재 노드(head)로
//         업데이트하여
//         // 역순 링크를 만든다.
//         head->next->next = head; // 내 다음 노드의 다음이 나다.
//     }
//     // Break the original link by setting the next pointer of the current
//     head
//     // to nullptr 원래 연결을 끊고 새로운 리스트의 끝을 나타낸다. 이
//     작업은
//     // 역순으로 재배치된 리스트에서 현재 노드가 마지막 노드가 되도록
//     한다. head->next = nullptr;

//     return newHead;
// }

// // recursion : 뒤에서부터 eval 시작
