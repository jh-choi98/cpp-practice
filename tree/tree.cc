#include <iostream>
using namespace std;

using namespace std;

struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int data) : data{data}, left{nullptr}, right{nullptr} {}
    BSTNode(int data, BSTNode *l, BSTNode *r)
        : data{data}, left{l}, right{r} {} // Intermediate Node
    ~BSTNode() {
        delete left;
        delete right;
    }
};

class BST {
    BSTNode *root;
    int height;
    int depth;

  public:
    BST() : root{nullptr}, height{0}, depth{0} {}
    ~BST() { delete root; }

    void insert(int data) {
        /*
        search -> node의 데이터와 비교하면서 l,r 판단
        leaf -> l or r nullptr를 만나면 저기에 insert
        */

        BSTNode *subRoot = root;

        while (subRoot) {
            if (data < subRoot->data) {
                if (subRoot->left) {
                    subRoot = subRoot->left;
                } else {
                    subRoot->left = new BSTNode(data);
                    return;
                }
            } else if (subRoot->data < data) {
                if (subRoot->right) {
                    subRoot = subRoot->right;
                } else {
                    subRoot->right = new BSTNode(data);
                    return;
                }
            } else {
                cerr << "[Warning!] Inserting duplicated data" << endl;
                return;
            }
        }

        // BSTNode *cur = root;
        // BSTNode *prev = nullptr;

        // while (cur) {
        //     if (cur->data > data) {
        //         prev = cur;
        //         cur = cur->left;
        //     } else if (cur->data < data) {
        //         prev = cur;
        //         cur = cur->right;
        //     } else {
        //         cerr << "[Warning!] Inserting duplicated data" << endl;
        //         return;
        //     }
        // }

        // BSTNode *newNode = new BSTNode(data);

        // if (prev->data > data) {
        //     prev->left = newNode;
        // } else {
        //     prev->right = newNode;
        // }
    }

    void insertRecursion(int data, BSTNode *r) {
        if (!r) {

        } else if (data < r->data) {
            insertRecursion(data, r->left);
        } else if (r->data < data) {
            insertRecursion(data, r->right);
        } else {
            cerr << "[Warning!] Inserting duplicated data" << endl;
            return;
        }
    }

    bool search(int data) {
        BSTNode *subRoot = root;

        while (subRoot) {
            if (data < subRoot->data) {
                if (subRoot->left) {
                    subRoot = subRoot->left;
                } else {
                    return false;
                }
            } else if (subRoot->data < data) {
                if (subRoot->right) {
                    subRoot = subRoot->right;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        }
    }

    void remove(int data) {}
    void print() {}
};

/*
class => 데이터를 저장하는 컨테이너 + 데이터 manipulate하는 메소드 제공
*/

/*
depth & height를 구하기 위해서 o(1)의 time complexity를 가지는가?
no -> 그렇다면 data field에서 depth & height를 쥐고 있으면 효율적

The maximum number of leafs = 2^h where h is the height of a tree
*/
