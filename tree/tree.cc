#include <iostream>
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
    BST(BSTNode *root) : root{root}, height{0}, depth{0} {}
    ~BST() { delete root; }

    int calcDepth() { return calcDepthHelp(root, 0); }

    int calcDepthHelp(BSTNode *r, int a) {
        if (!root) {
            return a;
        } else {
            return calcDepthHelp(r->left, a + 1);
        }
        // Call stack이 안 쌓여서 stack overflow를 방지
        // tail recursion
    }

    int calcHeight(BSTNode *r, int depth) {
        if (!r) {
            return depth - 1;
        }

        // left, root, rigth
        int leftDepth = calcHeight(r->left, depth + 1);
        int rightDepth = calcHeight(r->right, depth + 1);
        return max(leftDepth, rightDepth);

        /*
                             4
                        2.          6
                    1.     3.   5.      7
                                            8



        */
    }
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

    // bool search(int data) {
    //     BSTNode *subRoot = root;

    //     while (subRoot) {
    //         if (data < subRoot->data) {
    //             if (subRoot->left) {
    //                 subRoot = subRoot->left;
    //             } else {
    //                 return false;
    //             }
    //         } else if (subRoot->data < data) {
    //             if (subRoot->right) {
    //                 subRoot = subRoot->right;
    //             } else {
    //                 return false;
    //             }
    //         } else {
    //             return true;
    //         }
    //     }
    // }
    // *********************************************************
    // void remove(int data) {
    //     BSTNode *subRoot = root;
    //     BSTNode *prev = nullptr;

    //     while (subRoot) {
    //         if (data < subRoot->data) {
    //             if (subRoot->left) {
    //                 prev = subRoot;
    //                 subRoot = subRoot->left;
    //             } else {
    //                 cout << "This value does not exist in the tree" << endl;
    //                 return;
    //             }
    //         } else if (subRoot->data < data) {
    //             if (subRoot->right) {
    //                 prev = subRoot;
    //                 subRoot = subRoot->right;
    //             } else {
    //                 cout << "This value does not exist in the tree" << endl;
    //                 return;
    //             }
    //         } else {

    //         }
    //     }
    // }

    void inorderTraverse() {
        if (!root) {
            return;
        }
        inorderTraverseHelper(root);
        cout << endl;
    }
    void inorderTraverseHelper(BSTNode *node) {
        if (!node) {
            return;
        }
        inorderTraverseHelper(node->left);
        cout << node->data << " ";
        inorderTraverseHelper(node->right);
    }

    void preorderTraverse(BSTNode *node) {
        if (!node) {
            return;
        }
        cout << node->data << " ";
        preorderTraverse(node->left);
        preorderTraverse(node->right);
    }

    void postorderTraverse(BSTNode *node) {
        if (!node) {
            return;
        }
        postorderTraverse(node->left);
        postorderTraverse(node->right);
        cout << node->data << " ";
    }

    void insertR(int data) {
        if (root) {
            insertRecursion(data, root);
        } else {
            root = new BSTNode(data);
        }
        cout << "Insertion is successful" << endl;
    }

    void insertRecursion(int data, BSTNode *r) {
        cout << "insertRecursion" << endl;
        if (data < r->data) {
            if (!(r->left)) {
                r->left = new BSTNode{data};
            } else {
                insertRecursion(data, r->left);
            }
        } else if (r->data < data) {
            if (!(r->right)) {
                r->right = new BSTNode{data};
            } else {
                insertRecursion(data, r->right);
            }
        } else {
            cerr << "[Warning!] Inserting duplicated data" << endl;
            return;
        }
    }

    void insertR2(int data) {
        if (root) {
            insertRecursion2(data, &root);
        } else {
            root = new BSTNode(data);
        }
    }

    void insertRecursion2(int data, BSTNode **r) {
        if (!(*r)) {
            (*r) = new BSTNode{data};
        } else if (data < (*r)->data) {
            insertRecursion2(data, &((*r)->left));
        } else if ((*r)->data < data) {
            insertRecursion2(data, &((*r)->right));
        } else {
            cerr << "[Warning!] Inserting duplicated data" << endl;
            return;
        }
    }

    BSTNode *insertRecursion3(int data, BSTNode *r) {
        if (!r) {
            return new BSTNode{data};
        }

        if (data < r->data) {
            r->left = insertRecursion3(data, r->left);
        } else if (r->data < data) {
            r->right = insertRecursion3(data, r->right);
        } else {
            cerr << "[Warning!] Inserting duplicated data" << endl;
        }
        return r;
    }

    void insertR3(int data) {
        if (root) {
            root = insertRecursion3(data, root);
        } else {
            root = new BSTNode(data);
        }
    }

    BST *search(int data) {
        if (root) {
            return new BST{searchHelp(data, root)};
        } else {
            cerr << "The BST is empty" << endl;
            return nullptr;
        }
    }

    BSTNode *searchHelp(int data, BSTNode *r) {
        if (!r) {
            cerr << "This data does not exist in this bst" << endl;
            return nullptr;
        }

        if (data < r->data) {
            return searchHelp(data, r->left);
        } else if (r->data < data) {
            return searchHelp(data, r->right);
        } else {
            return r;
        }
    }
};

class Test {
  protected:
    int elems[7] = {4, 2, 1, 3, 6, 5, 7};
    BST *bst;

  public:
    Test() : bst{new BST} {}
    virtual void insertR() = 0;
    virtual ~Test(){};
};

class TestInsertR1 : public Test {
  public:
    void insertR() {
        for (int i = 0; i < 7; i++) {
            bst->insertR(elems[i]);
        }
        bst->inorderTraverse();
    }

    BST *serarch(int data) { return bst->search(data); }

    ~TestInsertR1() { delete bst; }
};

class TestInsertR2 : public Test {
    void insertR() {
        for (int i = 0; i < 7; i++) {
            bst->insertR2(elems[i]);
        }
        bst->inorderTraverse();
    }

  public:
    ~TestInsertR2() { delete bst; }
};

class TestInsertR3 : public Test {
    void insertR() {
        for (int i = 0; i < 7; i++) {
            bst->insertR3(elems[i]);
        }
        bst->inorderTraverse();
    }

  public:
    ~TestInsertR3() { delete bst; }
};

void testInsersion1() {

    Test *tests[] = {new TestInsertR1, new TestInsertR2, new TestInsertR3};

    for (int i = 0; i < 3; i++) {
        tests[i]->insertR();
    }

    for (int i = 0; i < 3; i++) {
        delete tests[i];
    }
}

void testSearch() {
    TestInsertR1 t;
    t.insertR();
    BST *bst = t.serarch(7);
    bst->inorderTraverse();
}

int main() {
    // testInsersion1();
    testSearch();
}

/*
class => 데이터를 저장하는 컨테이너 + 데이터 manipulate하는 메소드 제공
*/

/*
depth & height를 구하기 위해서 o(1)의 time complexity를 가지는가?
no -> 그렇다면 data field에서 depth & height를 쥐고 있으면 효율적

The maximum number of leafs = 2^h where h is the height of a tree
*/

/*
left recursion

print data

right recursion


 --data-data----- data -----data------


   null data null data null data null data
*/
