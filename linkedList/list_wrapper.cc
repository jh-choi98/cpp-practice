#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) : data{data}, next{nullptr} {}
    Node(int data, Node *next) : data{data}, next{next} {}
    ~Node() { delete next; }
};

struct List {
    Node *head;

    List() : head{nullptr} {}
    ~List() { delete head; }
};

void addAscending(List *list, int data) {
    if (!list->head) {
        list->head = new Node{data};
        return;
    }

    Node *head = list->head;
    Node *prev = nullptr;
    Node *newNode = nullptr;

    while (head) {
        if (head->data > data) {
            newNode = new Node{data, head};
            if (!prev) {
                list->head = newNode;
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

void print(List *list) { // pass by value is fine as well
    Node *cur = list->head;

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
    List *list = new List;
    addAscending(list, 5);
    addAscending(list, 9);
    addAscending(list, 7);
    addAscending(list, 12);
    print(list);

    delete list;
}

/*
첫 번째 노드의 주소가 wrapper 안에 저장되어 있는 데이터.
그래서 wrapper는 노드의 주소를 감싸고 있는 컨테이너 역할.
때문에 노드 주소에 접근하기 위해 필요한 것은 wrapper 오브젝트가 저장된 메모리
주소. wrapper 주소만 있으면 wrapper 오브젝트에 접근 가능하고 그 안에 노드의
주소가 있기 때문

Wrapper *wrapper = new Wrapper;
void add(Wrapper *wrapper);
add(wrapper);
*/
