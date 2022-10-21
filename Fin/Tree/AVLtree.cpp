#include <iostream>
using namespace std;

typedef struct Node {
    int key;
    struct Node *parent, *left, *right;
    int height;
} Node;

Node* createNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->parent = node->left = node->right = NULL;
    node->height = 0;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    if (node == NULL)
        return -1;
    return node->height;
}

int getBalance(Node *node) {
    if (node == NULL)
        return -1;
    return height(node->left) - height(node->right);
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *B = y->left;
    // Perform rotation
    y->left = x;
    x->parent = y;
    x->right = B;
    if (B != NULL)
        B->parent = x;
    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    // Return new root
    return y;
}

Node* rightRotate(Node *x) {
    Node *y = x->left;
    Node *B = y->right;
    // Perform rotation
    y->right = x;
    x->parent = y;
    x->left = B;
    if (B != NULL)
        B->parent = x;
    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    // Return new root
    return y;
}

Node* insert(Node *node, int key) {
    // 1. Perform the normal BST insertion
    if (node == NULL)
        return createNode(key);
    if (key < node->key) {
        node->left = insert(node->left, key);
        node->left->parent = node;
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
        node->right->parent = node;
    }
    else // Equal keys are not allowed in BST
        return node;
    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));
    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);
    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    // return the (unchanged) node pointer
    return node;
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << "key: " << root->key << " height: " << root->height << endl;
        inOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the constructed AVL tree is " << endl;
    inOrder(root);
}