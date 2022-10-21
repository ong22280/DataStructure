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

int height(struct Node *node) {
    if (node == NULL) {
        return -1;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

void preOrder(struct Node *node) {
    if (node == NULL) {
        return;
    }
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(struct Node *node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}

void postOrder(struct Node *node) {
    if (node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << " ";
}

// insert function
void insert(struct Node* z, struct Node* root) {
    struct Node *y = NULL;
    struct Node *x = root;
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

int main() {
    int parent, child;
    struct Node *tree = createNode();
    cin >> parent;
    tree->key = parent;
    if ( parent == 0 ) {
        cout << "What is emptier, my heart or this tree?" << endl;
        return 0;
    }
    while (true) {
        cin >> child;
        if ( child == 0 ) {
            break;
        }
        struct Node *node = createNode();
        node->key = child;
        insert(node, tree);
    }
    cout << "Height: ";
    cout << height(tree) << endl;
    cout << "Preorder: ";
    preOrder(tree);
    cout << endl;
    cout << "Inorder: ";
    inOrder(tree);
    cout << endl;
    cout << "Postorder: ";
    postOrder(tree);
    return 0;
}