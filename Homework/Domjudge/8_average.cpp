#include <iostream>
using namespace std;

struct Node {
    string directory;
    int size;
    struct Node *parent, *leftChild, *rightSibling;
};

struct Node* createRoot(string directory, int size) {
    struct Node *node = new Node;
    node->directory = directory;
    node->size = size;
    node->parent = node->leftChild = node->rightSibling = NULL;
    return node;
}

struct Node* createNode(string directory, int size, struct Node *parent) {
    struct Node *node = new Node;
    node->directory = directory;
    node->size = size;
    node->parent = parent;
    node->leftChild = node->rightSibling = NULL;
    if (node->parent->leftChild == NULL) {
        node->parent->leftChild = node;
    } else {
        struct Node *child = node->parent->leftChild;
        while (child->rightSibling != NULL) {
            child = child->rightSibling;
        }
        child->rightSibling = node;
    }
    return node;
}

struct Node* getParent(struct Node *node) {
    return node->parent;
}

struct Node* getChild(struct Node *node, int k) {
    struct Node *child = node->leftChild;
    for (int i = 1; i < k; i++) {
        child = child->rightSibling;
    }
    return child;
}

int getSize(struct Node *node) {
    return node->size;
}

string getDirectory(struct Node *node) {
    return node->directory;
}

bool isRoot(struct Node *node) {
    if (node->parent == NULL) {
        return true;
    } else {
        return false;
    }
}

bool isExternal(struct Node *node) {
    if (node->leftChild == NULL) {
        return true;
    } else {
        return false;
    }
}

bool isInternal(struct Node *node) {
    if (node->leftChild != NULL) {
        return true;
    } else {
        return false;
    }
}

int depth(struct Node *node) {
    int depth = 0;
    while (node->parent != NULL) {
        depth += node->size;
        node = node->parent;
    }
    return depth;
}

// max function
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int height(struct Node *node) {
    if (isExternal(node)) {
        return 0;
    } else {
        int heightValue = 0;
        struct Node *child = node->leftChild;
        while (child != NULL) {
            heightValue = max(heightValue, height(child));
            child = child->rightSibling;
        }
        return heightValue + 1;
    }
}

void preOrder(struct Node *node) {
    cout << node->directory << " ";
    if (isInternal(node)) {
        struct Node *child = node->leftChild;
        while (child != NULL) {
            preOrder(child);
            child = child->rightSibling;
        }
    }
}

void postOrder(struct Node *node, int &total_size) {
    struct Node *child = node->leftChild;
    while (child != NULL) {
        postOrder(child, total_size);
        child = child->rightSibling;
    }
}

int main() {
    double total_size = 0;
    int number_external_nodes = 0;
    double average_size = 0;
    // array of nodes
    struct Node *nodes[100];
    // create root
    nodes[0] = createRoot("0", 0);
    // create nodes
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string parent;
        string directory;
        int size;
        cin >> parent >> directory >> size;
        for (int j = 0; j < i; j++) {
            if (getDirectory(nodes[j]) == parent) {
                nodes[i] = createNode(directory, size, nodes[j]);
            }
        }
    }
    // find average size of external nodes
    for (int i = 0; i <= n; i++) {
        if (isExternal(nodes[i])) {
            total_size += depth(nodes[i]);
            number_external_nodes++;
        }
    }
    // print average size
    average_size = total_size / number_external_nodes;
    printf("%.2f", average_size);
}