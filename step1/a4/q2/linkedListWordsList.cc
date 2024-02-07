#include "linkedListWordsList.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

Node::Node(string data) : data{data}, next{nullptr} {}
Node::Node(string data, Node *node) : data{data}, next{node} {}

LinkedListWordsList::LinkedListWordsList() : head{nullptr}, tail{nullptr} {}
LinkedListWordsList::~LinkedListWordsList() { delete head; }

void LinkedListWordsList::addWord(string str) {
    Node *newNode = new Node{str};
    if (!head && !tail) {
        head = newNode;
        tail = head;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}

void LinkedListWordsList::updateWord(string oldStr, string newStr) {
    Node *cur = head;
    while (cur) {
        if (cur->data == oldStr) {
            cur->data = newStr;
        }
        cur = cur->next;
    }
}

bool LinkedListWordsList::isSorted() {
    if (!head && !tail) {
        return true;
    }

    if (head == tail) {
        return true;
    }

    Node *cur = head;

    while (cur->next) {
        if (cur->data < cur->next->data) {
            return false;
        }
        cur = cur->next;
    }
    return true;
}

void LinkedListWordsList::removeDuplicatesExceptFirst() {
    unordered_set<string> hash;
    Node *cur = head;
    Node *prev = nullptr;

    while (cur) {
        if (hash.find(cur->data) != hash.end()) {
            prev->next = cur->next;
            cur->next = nullptr;
            delete cur;
        } else {
            hash.insert(cur->data);
            prev = cur;
        }
        cur = prev->next;
    }
}

void LinkedListWordsList::removeDuplicatesExceptLast() {
    // Node *cur = head;
    // Node *curInner = nullptr;
    // Node *prev = nullptr;

    // while (cur && cur->next) {
    //     curInner = cur->next;
    //     while (curInner) {
    //         if (cur->data == curInner->data) {
    //             prev->next = cur->next;
    //             delete cur;
    //             cur = nullptr;
    //             break;
    //         } else {
    //             curInner = curInner->next;
    //         }
    //     }
    //     if (cur) {
    //         prev = cur;
    //     }
    //     cur = prev->next;
    // }
    unordered_map<Node *, Node *> targetPair;
    unordered_map<string, Node *> hash;

    Node *cur = head;
    Node *prev = nullptr;

    while (cur) {
        if (hash.count(cur->data)) {
            Node *target = hash[cur->data];
            // cout << target->data << endl;
            Node *targetPrev = targetPair[target];
            if (!targetPrev) {
                Node *temp = head;
                head = head->next;
                temp->next = nullptr;
                delete temp;
            } else {
                targetPrev->next = target->next;
                target->next = nullptr;
                delete target;
            }
        }
        hash[cur->data] = cur;
        targetPair[cur, prev];
        prev = cur;
        cur = cur->next;
    }
}

void LinkedListWordsList::print() {
    Node *cur = head;
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
