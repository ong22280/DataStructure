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

struct Node* search(int key, struct Node* node) {
    if ((node == NULL) || (key == node->key)) {
        return node;
    }
    if (key < node->key) {
        return search(key, node->left);
    } else {
        return search(key, node->right);
    }
}

bool isBST(struct Node* node) {
	if (node == NULL)
		return true;
	if (node->left != NULL && node->left->key > node->key)
		return false;
	if (node->right != NULL && node->right->key < node->key)
		return false;
	if (!isBST(node->left) || !isBST(node->right))
		return false;
	return true;
}

int main() {
    int root, parent, child;
    string side;
    struct Node *tree = createNode();
    cin >> root;
    tree->key = root;
    while (true) {
        cin >> parent >> child >> side;
        struct Node *node = createNode();
        node->key = child;
        if ( parent == 0 && child == 0 && side == "end" ) {
            break;
        } else if (side == "L") {
            // if duplicate node
            if (search(child, tree) == NULL && search(parent, tree)->left == NULL) {
                node->parent = search(parent, tree);
                node->parent->left = node;
            } else {
                cout << "Not what I am looking for, I am afraid." << endl;
                return 0;
            }
        } else if (side == "R") {
            // if duplicate node
            if (search(child, tree) == NULL && search(parent, tree)->right == NULL) {
                node->parent = search(parent, tree);
                node->parent->right = node;
            } else {
                cout << "Not what I am looking for, I am afraid." << endl;
                return 0;
            }
        }
    }
    if (tree->left == NULL && tree->right == NULL) {
        cout << "This tree is lonely, give them a hug." << endl;
    } else if (isBST(tree)) {
        cout << "A binary search tree, this is." << endl;
    } else {
        cout << "This tree is illegal." << endl;
    }
    return 0;
}