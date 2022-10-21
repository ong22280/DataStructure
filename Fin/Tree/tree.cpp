#include <iostream>
using namespace std;

typedef struct Nodes {
    string key;
    int size;
    Nodes *parent, *leftChild, *rightSibling;
} Node;

Node* createRoot(string key, int size) {
    Node *node = new Node;
    node->key = key;
    node->size = size;
    node->parent = node->leftChild = node->rightSibling = NULL;
    return node;
}

Node* createNode(string key, int size, Node *parent) {
    Node *node = new Node;
    node->key = key;
    node->size = size;
    node->parent = parent;
    node->leftChild = node->rightSibling = NULL;
    // Set this node as a child to its parent
    if(node->parent != NULL) {
        if(node->parent->leftChild != NULL) {
            Node* child = node->parent->leftChild;
            while(child->rightSibling != NULL) {
                child = child->rightSibling;
            }
            child->rightSibling = node;
        }
        else {
            node->parent->leftChild = node;
        }
    }
    return node;
}

Node* getParent(Node *node) {
    return node->parent;
}

Node* getChild(Node *node, int k) {
    Node *child = node->leftChild;
    for (int i = 1; i < k; i++)
        child = child->rightSibling;
    return child;
}

bool isRoot(Node *node) {
    if (node->parent == NULL)
        return true;
    else
        return false;
}

bool isExternal(Node *node) {
    if (node->leftChild == NULL)
        return true;
    else
        return false;
}

int depth(Node *node) {
    int depth = 0;
    while (!isRoot(node)) {
        depth += node->size;
        node = node->parent;
    }
    return depth;
}

void preOrder(Node *node) {
    if (node != NULL) {
        cout << node->key << " ";
        Node *child = node->leftChild;
        while (child != NULL) {
            preOrder(child);
            child = child->rightSibling;
        }
    }
}

void postOrder(Node *node) {
    if (node != NULL) {
        Node *child = node->leftChild;
        while (child != NULL) {
            postOrder(child);
            child = child->rightSibling;
        }
        cout << node->key << " ";
    }
}

int main() {
    Node *root = createRoot("root", 1);
    Node *node1 = createNode("1", 1, root);
    Node *node2 = createNode("2", 1, root);
    Node *node3 = createNode("3", 1, node1);
        /* 3 becomes left child of 1
          root
          / \
        1    2
      /
    3
    */
    Node *parent = getParent(node1); // output: root
    Node *child = getChild(root, 2); // output: 2
    bool isRootNode = isRoot(node1); // output: false
    bool isExternalNode = isExternal(node3); // output: true
    int depthNode = depth(node3); // output: 2
    preOrder(root); // output: root 1 3 2
    postOrder(root); // output: 3 1 2 root
    return 0;
}