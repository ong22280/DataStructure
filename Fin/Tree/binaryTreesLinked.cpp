#include <iostream>
using namespace std;

struct Node {
    int key;
    struct Node *parent, *left, *right;
};

struct Node* createNode() {
    struct Node *node = new Node;
    node->key = 0;
    node->parent = node->left = node->right = NULL;
    return node;
}

struct Node* getParent(struct Node *node) {
    return node->parent;
}

struct Node* getLeft(struct Node *node) {
    return node->left;
}

struct Node* getRight(struct Node *node) {
    return node->right;
}

bool isRoot(struct Node *node) {
    if (node->parent == NULL)
        return true;
    else
        return false;
}

bool isExternal(struct Node *node) {
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

bool isInternal(struct Node *node) {
    if (node->left != NULL || node->right != NULL)
        return true;
    else
        return false;
}

struct Node* getSibling(struct Node *node) {
    if (isRoot(node))
        return NULL;
    if (node == node->parent->left)
        return node->parent->right;
    if (node == node->parent->right)
        return node->parent->left;
}

int depth(struct Node *node) {
    if (isRoot(node))
        return 0;
    return 1 + depth(node->parent);
}

int height(struct Node *node) {
    if (node == NULL)
        return -1;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

void preOrder(struct Node *node) {
    if (node == NULL)
        return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(struct Node *node) {
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}

void postOrder(struct Node *node) {
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << " ";
}

void expandExternal(struct Node *node) {
    node->left = createNode();
    node->right = createNode();
    node->left->parent = node;
    node->right->parent = node;
}

struct Node* removeAboveExternal(struct Node *node) {
    struct Node *parent = node->parent;
    struct Node *siblings = getSibling(node);
    if (parent->parent == NULL)
        siblings->parent = NULL;
    else {
        struct Node *grandparent = parent->parent;
        if (parent == grandparent->left)
            grandparent->left = siblings;
        else
            grandparent->right = siblings;
        siblings->parent = grandparent;
    }
    delete parent;
    delete node;
    return siblings;
}

int main() {
    return 0;
}