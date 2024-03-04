#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;
    int depth; // From root to this Node

    BSTNode(int data) : data{data}, left{nullptr}, right{nullptr}, depth{0} {}
    BSTNode(int data, BSTNode *left, BSTNode *right)
        : data{data}, left{left}, right{right}, depth{0} {}
    BSTNode(int data, int depth)
        : data{data}, left{nullptr}, right{nullptr}, depth{depth} {}
    BSTNode(int data, BSTNode *left, BSTNode *right, int depth)
        : data{data}, left{left}, right{right}, depth{depth} {}

    ~BSTNode() {
        delete left;
        delete right;
    }
};

class BST {
    BSTNode *root;
    int height;

  public:
    BST() : root{nullptr}, height{-1} {}
    BST(BSTNode *root) : root{root}, height{0} {
        //
    }
    ~BST() { delete root; }

    int calcDepth(BSTNode *target) { return calcDepthHelp(root, target, 0); }

    int calcDepthHelp(BSTNode *r, BSTNode *target, int depth) {
        if (!r) {
            cerr << "The target Node does not exist" << endl;
            return -1;
        }

        if (r == target) {
            return depth;
        } else if (r->data < target->data) {
            return calcDepthHelp(r->left, target, depth + 1);
        } else if (target->data < r->data) {
            return calcDepthHelp(r->right, target, depth + 1);
        }
        // Call stack이 안 쌓여서 stack overflow 방지
        // tail recursion
    }

    // 필드에 height가 없을 때, 혹은 remove 등에서 노드가 사라졌을 때 height
    // update용?
    int calcHeight() { return calcHeightHelp(root, 0); }

    int calcHeightHelp(BSTNode *r, int depth) {
        if (!r) {
            return depth - 1;
        }

        int leftDepth = calcHeightHelp(r->left, depth + 1);
        int rightDepth = calcHeightHelp(r->right, depth + 1);
        return max(leftDepth, rightDepth);
    }

    // *****************************************
    // calcHeight logic 이해부터
    void insert(int data) {}
};
