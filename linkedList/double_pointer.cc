#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) : data{data}, next{nullptr} {}
    Node(int data, Node *node) : data{data}, next{node} {}
    ~Node() { delete next; }
};

void addAscending(Node **list, int data) {
    if (!(*list)) {
        *list = new Node{data};
        return;
    }

    Node *head = *list;
    Node *newNode = nullptr;

    if (head->data > data) {
        newNode = new Node{data, head};
        *list = newNode;
        return;
    }

    Node *prev = head;
    head = head->next;

    while (head) {
        if (head->data > data) {
            newNode = new Node{data, head};
            prev->next = newNode;
            return;
        }
        prev = head;
        head = head->next;
    }

    prev->next = new Node{data};
}
// *****************************************
void addAscending2(Node **list, int data) {
    if (!(*list)) {
        *list = new Node{data};
        return;
    }

    Node *head = *list;
    Node *newNode = nullptr;
    Node *prev = nullptr;

    while (head) {
        if (head->data > data) {
            newNode = new Node(data, head);
            if (!prev) {
                *list = newNode;
                // *list가 새로 생성된 노드 주소 (첫 노드의 주소)를
                // 가리키도록 업데이트 함
            } else {
                prev->next = newNode;
            }
            return;
        }
        prev = head;
        head = head->next;
    }
    prev->next = new Node{data};
}
// *****************************************

void print(Node *list) {
    Node *cur = list;
    cout << "[ ";
    while (cur) {
        cout << cur->data;
        if (cur->next) {
            cout << " -> ";
        }
        cur = cur->next;
    }
    cout << " ]" << endl;
}

int main() {
    Node *list = new Node{10};
    // addAscending(&list, 5);
    // addAscending(&list, 7);
    // addAscending(&list, 6);
    // addAscending(&list, 15);

    addAscending2(&list, 5);
    addAscending2(&list, 7);
    addAscending2(&list, 6);
    addAscending2(&list, 15);
    addAscending2(&list, 19);
    addAscending2(&list, 20);
    addAscending2(&list, 17);
    addAscending2(&list, 1);

    print(list);
    delete list;
}

/*
코드에서 데이터는 변수에 저장되어 있다. 변수에 저장된 데이터를 수정하고 싶을 때
함수에 그 변수의 주소를 전달해 데이터를 업데이트한다. 어떤 타입의 데이터가
저장되어있는지는 중요하지 않다. 그 데이터를 함수 호출을 통해 업데이트하고 싶으면
무조건 그 데이터의 주소를 이용해야 한다.

Suppose I want to update int a = 3 by a function call
then one of the function parameter must be int * type.

Similary, for Node *node = new Node{}, the function must have
Node ** as its parameter type because what we want to change is
the address value stored inside a node variable; therefore you need to
pass the address of the node variable so that the function must hold
the address of the node variable in a parameter variable of type Node **
*/
