#include <iostream>
using namespace std;

typedef struct Nodes {
    int key;
    Nodes *parent, *left, *right;
} Node;

Node* createNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->parent = node->left = node->right = NULL;
    return node;
}

Node* getParent(Node *node) {
    return node->parent;
}

Node* getLeft(Node *node) {
    return node->left;
}

Node* getRight(Node *node) {
    return node->right;
}

bool isRoot(Node *node) {
    if (node->parent == NULL)
        return true;
    else
        return false;
}

bool isExternal(Node *node) {
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

Node* getSibling(Node *node) {
    if (isRoot(node))
        return NULL;
    if (node == node->parent->left)
        return node->parent->right;
    if (node == node->parent->right)
        return node->parent->left;
}

int depth(Node *node) {
    int depth = 0;
    while (node->parent != NULL) {
        node = node->parent;
        depth++;
    }
    return depth;
}

void preOrder(Node *node) {
    if (node != NULL)
        return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node) {
    if (node != NULL)
        return;
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}

void expandExternal(Node *node) {
    Node *left = createNode(0);
    node->left = left;
    left->parent = node;
    Node *right = createNode(0);
    node->right = right;
    right->parent = node;
}

Node* removeAboveExternal(Node *node) {
    Node *parent = node->parent;
    Node *sibling = getSibling(node);
    if (parent->parent == NULL)
        sibling->parent = NULL;
    else {
        Node *grandparent = parent->parent;
        if (parent == grandparent->left)
            grandparent->left = sibling;
        else
            grandparent->right = sibling;
        sibling->parent = grandparent;
    }
    delete parent;
    delete node;
    return sibling;
}

Node* search(Node *node, int key) {
    if (node == NULL || key == node->key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

Node* minimum(Node *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* maximum(Node *node) {
    while (node->right != NULL)
        node = node->right;
    return node;
}

Node* successor(Node *node) {
    if (node->right != NULL)
        return minimum(node->right);
    Node *ancestor = node->parent;
    while (ancestor != NULL && node == ancestor->right) {
        node = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

Node* predecessor(Node *node) {
    if (node->left != NULL)
        return maximum(node->left);
    Node *ancestor = node->parent;
    while (ancestor != NULL && node == ancestor->left) {
        node = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

void insert(Node* z, Node* root) {
    Node *y = NULL;
    Node *x = root;
    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y != NULL) {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

void transplant(Node *root, Node *z, Node *v) {
    if (z->parent != NULL) {
        if (z == z->parent->left) {
            z->parent->left = v;
        } else {
            z->parent->right = v;
        }
    }
    if (v != NULL) {
        v->parent = z->parent;
    }
}

void treeDelete(Node *z, Node *root) {
    // if z has no left child
    if (z->left == NULL) {
        transplant(root, z, z->right);
    }
    // if z has just a left child
    else if (z->right == NULL) {
        transplant(root, z, z->left);
    }
    // if z has both children
    else {
        Node *y = minimum(z->right);
        if (y->parent != z) {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

int main() {
    return 0;
}