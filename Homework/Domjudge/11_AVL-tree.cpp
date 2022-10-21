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

// make balance function
void makeBalance(struct Node* node) {
    if (node == NULL) {
        return;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight - rightHeight > 1) {
        if (height(node->left->left) >= height(node->left->right)) {
            // left-left case
            struct Node *y = node->left;
            struct Node *z = y->left;
            struct Node *b = z->right;
            struct Node *c = y->right;
            struct Node *d = node->right;
            struct Node *p = node->parent;
            if (p != NULL) {
                if (p->left == node) {
                    p->left = y;
                } else {
                    p->right = y;
                }
            }
            y->parent = p;
            y->left = z;
            z->parent = y;
            z->right = b;
            if (b != NULL) {
                b->parent = z;
            }
            y->right = node;
            node->parent = y;
            node->left = c;
            if (c != NULL) {
                c->parent = node;
            }
            node->right = d;
            if (d != NULL) {
                d->parent = node;
            }
        } else {
            // left-right case
            struct Node *y = node->left;
            struct Node *z = y->right;
            struct Node *a = y->left;
            struct Node *b = z->left;
            struct Node *c = z->right;
            struct Node *d = node->right;
            struct Node *p = node->parent;
            if (p != NULL) {
                if (p->left == node) {
                    p->left = z;
                } else {
                    p->right = z;
                }
            }
            z->parent = p;
            z->left = y;
            y->parent = z;
            y->right = b;
            if (b != NULL) {
                b->parent = y;
            }
            z->right = node;
            node->parent = z;
            node->left = c;
            if (c != NULL) {
                c->parent = node;
            }
            node->right = d;
            if (d != NULL) {
                d->parent = node;
            }
        }
    } else if (rightHeight - leftHeight > 1) {
        if (height(node->right->right) >= height(node->right->left)) {
            // right-right case
            struct Node *y = node->right;
            struct Node *z = y->right;
            struct Node *a = node->left;
            struct Node *b = y->left;
            struct Node *c = z->left;
            struct Node *d = z->right;
            struct Node *p = node->parent;
            if (p != NULL) {
                if (p->left == node) {
                    p->left = z;
                } else {
                    p->right = z;
                }
            }
            z->parent = p;
            z->left = node;
            node->parent = z;
            node->left = a;
            if (a != NULL) {
                a->parent = node;
            }
            node->right = b;
            if (b != NULL) {
                b->parent = node;
            }
            z->right = c;
            if (c != NULL) {
                c->parent = z;
            }
            y->parent = z;
            y->left = d;
            if (d != NULL) {
                d->parent = y;
            }
        } else {
            // right-left case
            struct Node *y = node->right;
            struct Node *z = y->left;
            struct Node *a = node->left;
            struct Node *b = z->left;
            struct Node *c = z->right;
            struct Node *d = y->right;
            struct Node *p = node->parent;
            if (p != NULL) {
                if (p->left == node) {
                    p->left = z;
                } else {
                    p->right = z;
                }
            }
            z->parent = p;
            z->left = node;
            node->parent = z;
            node->left = a;
            if (a != NULL) {
                a->parent = node;
            }
            node->right = b;
            if (b != NULL) {
                b->parent = node;
            }
            z->right = y;
            y->parent = z;
            y->left = c;
            if (c != NULL) {
                c->parent = y;
            }
            y->right = d;
            if (d != NULL) {
                d->parent = y;
            }
        }
    }
    makeBalance(node->parent);
}

// isAVLtree function
bool isAVLtree(struct Node *node) {
    if (node == NULL) {
        return true;
    } else if (height(node->left) - height(node->right) > 1
            || height(node->right) - height(node->left) > 1) {
        return false;
    }
    return isAVLtree(node->left) && isAVLtree(node->right);
}

int main() {
    int parent, child;
    struct Node *tree = createNode();
    cin >> parent;
    tree->key = parent;
    if ( parent == 0 ) {
        cout << "empty tree" << endl;
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
    makeBalance(tree);
    if (isAVLtree(tree)) {
        cout << "This tree has AVL property" << endl;
    } else {
        cout << "This tree doesn't have AVL property" << endl;
    }
}