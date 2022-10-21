#include <iostream>
using namespace std;

struct Node {
    string directory;
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

void postOrder(struct Node *node) {
    if (isInternal(node)) {
        struct Node *child = node->leftChild;
        while (child != NULL) {
            postOrder(child);
            child = child->rightSibling;
        }
    }
    cout << node->directory << " ";
}

int main() {
    int total_size = 0;
    // Pointer of struct Node
    struct Node *root = createRoot("/user/rt/courses/", 1);
    struct Node *cs016 = createNode("cs016/", 2, root);
    struct Node *grades = createNode("grades", 8, cs016);
    struct Node *homeWorks = createNode("homeWorks/", 1, grades);
    struct Node *hw1 = createNode("hw1/", 3, homeWorks);
    struct Node *hw2 = createNode("hw2/", 2, homeWorks);
    struct Node *hw3 = createNode("hw3/", 4, homeWorks);
    struct Node *programs = createNode("programs/", 1, cs016);
    struct Node *pr1 = createNode("pr1/", 57, programs);
    struct Node *pr2 = createNode("pr2/", 97, programs);
    struct Node *pr3 = createNode("pr3/", 74, programs);
    struct Node *cs252 = createNode("cs252/", 1, programs);
    struct Node *projects = createNode("projects/", 1, root);
    struct Node *grades1 = createNode("grades", 3, projects);
    struct Node *papers = createNode("papers/", 1, projects);
    struct Node *buylow = createNode("buylow", 26, papers);
    struct Node *sellhigh = createNode("sellhigh", 55, papers);
    struct Node *demos = createNode("demos/", 1, papers);
    struct Node *market = createNode("market", 4786, demos);
    return 0;
}