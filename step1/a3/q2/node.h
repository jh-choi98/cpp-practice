// #include "input.h"
// #include "hexaDecimal.h"
// #include <iostream>

// template <typename T>
// class Node : virtual public Input, virtual public HexaDecimal
// {
//     T data;
//     Node *next;

// public:
//     Node<T>(T data);
//     Node<T>(T r, T g, T b);
//     Node<T>(T data, Node *node);
//     ~Node();
//     RGB getRgb() override;
//     bool isValid() override;

//     HexaDecimal *getHex(RGB rgb) override;
//     friend std::ostream &operator<<(std::ostream &out, const Node<T> &n);
// };

// // low coupling + high flexibility
// // array를 사용하고 싶다면 Input을 inheritance 하면 됨

#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string>

#include "input.h"
#include "hexaDecimal.h"
#include <iostream>

using namespace std;

template <typename T>
class Node : public Input, public HexaDecimal
{
    T data;
    Node *next;

public:
    Node(T data);
    Node(T r, T g, T b);
    Node(T data, Node *node);
    ~Node();
    RGB getRgb() override;
    bool isValid() override;
    Node *getNext();
    void setNext(Node *n);

    HexaDecimal *getHex(RGB rgb) override;
    friend ostream &operator<<(ostream &out, const Node<T> &n);
};

const int HEX = 16;

class InvalidRgb
{
};

template <typename T>
Node<T>::Node(T data) : data{data}, next{nullptr} {}

template <typename T>
Node<T>::Node(T r, T g, T b)
{
    Node<T> *R = new Node<T>{r}, *G = new Node<T>{g}, *B = new Node<T>{b};
    G->next = B;
    R->next = G;
}

template <typename T>
Node<T>::Node(T data, Node *node) : data{data}, next{node} {}

template <typename T>
Node<T>::~Node() { delete next; }

template <typename T>
bool Node<T>::isValid()
{
    int nodeCount = 0;
    Node *cur = this;

    while (cur->next)
    {
        if (cur->data < 0 || cur->data > 255)
        {
            return false;
        }
        cur = cur->next;
        ++nodeCount;
    }

    if (nodeCount != 3)
    {
        return false;
    }
    return true;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T> *n)
{
    this->next = n;
}
/*
valid RGB
1. The number of nodes is 3
2. The data in each node is [0, 255]
*/

template <typename T>
RGB Node<T>::getRgb()
{

    RGB rgb{this->data, this->next->data, this->next->next->data};
    return rgb;
}

void getHexString(int n, string &nHex)
{
    while (n != 0)
    {
        int rem = n % 16;
        char ch;

        if (rem < 10)
        {
            ch = rem + 48;
        }
        else
        {
            ch = rem + 55;
        }

        nHex += ch;
        n = n / 16;
    }

    int i = 0, j = nHex.size() - 1;
    while (i <= j)
    {
        swap(nHex[i], nHex[j]);
        i++;
        j--;
    }
}

template <typename T>
HexaDecimal *Node<T>::getHex(RGB rgb)
{
    auto [r, g, b] = rgb;
    string rHex = "", gHex = "", bHex = "";
    getHexString(r, rHex);
    getHexString(g, gHex);
    getHexString(b, bHex);
    string rgbHex = rHex + gHex + bHex;

    Node<char> *head = nullptr;
    Node<char> *current = nullptr;

    for (auto it = rgbHex.rbegin(); it != rgbHex.rend(); ++it)
    {
        if (!head)
        {
            head = new Node<char>(*it);
            current = head;
        }
        else
        {
            current->setNext(new Node<char>(*it));
            current = current->getNext();
        }
    }

    return head;
}

template <typename T>
ostream &operator<<(ostream &out, const Node<T> &n)
{
    for (auto it = n.begin(); it != n.end(); ++it)
    {
        out << *it << " ";
    }
    out << endl;
}

#endif
