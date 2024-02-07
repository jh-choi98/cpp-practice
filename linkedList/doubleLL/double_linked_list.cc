#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data{ data }, prev{ nullptr }, next{ nullptr } {}
    Node(int data, Node* prev, Node* next)
        : data{ data }, prev{ prev }, next{ next } {}
    ~Node() { delete next; }
};

class DoubleLinkedList {
    Node* head;
    Node* tail;
    int len;

public:
    DoubleLinkedList() : head{ nullptr }, tail{ nullptr }, len{ 0 } {}
    ~DoubleLinkedList() { delete head; }

    int getLength() { return len; }

    void addFront(int data) {
        Node* newNode = new Node{ data, nullptr, head };
        if (!len && !head && !tail) {
            head = newNode;
            tail = head;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++len;
    }
    void addBack(int data) {
        Node* newNode = new Node{ data, tail, nullptr };
        if (!len && !head && !tail) {
            addFront(data);
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++len;
    }
    void addByIndex(int data, int index) {
        Node* cur = head;
        if (index == 0) {
            addFront(data);
            return;
        }

        if (index == len - 1) {
            addBack(data);
            return;
        }

        Node* newNode = new Node{ data };

        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;

        ++len;

    }
    void print() {
        cout << "[ ";
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) {
                cout << " -> ";
            }
            cur = cur->next;
        }
        cout << " ]" << endl;
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
}

/* 해당 구조가 효율적인지 아닌지 판단하는 방법
해당 구조를 사용하지 않았을 때에도 똑같은 효율을 낼 수 있는지 판단
ex. addBack()을 tail이 있을 때의 time complexity와 없을 때의
time complexity를 비교해서 판단
 */
