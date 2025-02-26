#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void inorder(Node *n) {
    if (nullptr == n) return;

    inorder(n->left);
    inorder(n->right);
}

void preorder(Node *n) {
    if (nullptr == n) return;

    cout << n;
    inorder(n->left);
    inorder(n->right);
}

void postorder(Node *n) {
    if (nullptr == n) return;

    inorder(n->left);
    inorder(n->right);
    cout << n;
}
