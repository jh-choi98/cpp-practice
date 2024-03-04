#include <iostream>
using namespace std;

struct BinNode {
    int data;
    BinNode *left;
    BinNode *right;
    BinNode(int d) : data{d}, left{nullptr}, right{nullptr} {}
    BinNode(int d, BinNode *l, BinNode *r) : data{d}, left{l}, right{r} {}
    ~BinNode() {
        delete left;
        delete right;
    }
};

class BinTree {
    BinNode *root;

  public:
    BinTree() : root{nullptr} {}
    BinTree(BinNode *r) : root{r} {}
    ~BinTree() { delete root; }

    // Preorder traversal (root -> left -> right)
    void preorderTraversal(BinNode *node) {
        if (!node) {
            return;
        }

        cout << node->data << " -> ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
    // Postorder traversal (left -> right -> root)
    void postorderTraversal(BinNode *node) {
        if (!node) {
            return;
        }

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " -> ";
    }
    // Inorder traversal (left -> root -> right)
    void inorderTraversal(BinNode *node) {
        if (!node) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->data << " -> ";
        inorderTraversal(node->right);
    }
};
