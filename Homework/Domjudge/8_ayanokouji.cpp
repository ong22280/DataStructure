#include <iostream>
using namespace std;
int total = 0;
string path[100];
int c = 0;

struct Node {
    string directory;
    struct Node *parent, *leftChild, *rightSibling;
};

struct Node* createRoot(string directory) {
    struct Node *node = new Node;
    node->directory = directory;
    node->parent = node->leftChild = node->rightSibling = NULL;
    return node;
}

struct Node* createNode(string directory, struct Node *parent) {
    struct Node *node = new Node;
    node->directory = directory;
    node->parent = parent;
    node->leftChild = node->rightSibling = NULL;
    if (node->parent != NULL) {
        if (node->parent->leftChild != NULL) {
            struct Node *child = node->parent->leftChild;
            while (child->rightSibling != NULL) {
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

bool isRoot(struct Node *node) {
    if (node->parent == NULL) {
        return true;
    } else {
        return false;
    }
}

void getParent(struct Node *node) { 
    if (isRoot(node->parent)) {
        return;
    }
    path[c] = node->parent->directory;
    c++;
    getParent(node->parent);    
}

void travel(struct Node *node, string checkFile) {
    if (node == NULL) {
        return;
    }
    if (node->directory == checkFile) {
        total++;
    }
    travel(node->leftChild, checkFile);
    travel(node->rightSibling, checkFile);
}

int main() {
    struct Node *nodes[100];
    int count = 0;
    string parent;
    string child;
    string checkFile;
    nodes[0] = createRoot("/");
    int i = 1;
    while (1) {
        cin >> parent;
        if (parent == "<`~`?>") {
            break;
        }
        cin >> child;
        for (int j = 0; j < i; j++) {
            if (nodes[j]->directory == parent) {
                nodes[i] = createNode(child, nodes[j]);
                count++;
            }
        }
        i++;
    }
    cin >> checkFile;
    for(int i = 1; i <= count; i++) {
        travel(nodes[i], checkFile);
    }
    if (checkFile == "/") {
        cout << "/";
    }
    else if (total>=1) {
        for (int i = 1; i <= count; i++) {
            if (nodes[i]->directory == checkFile) {
                getParent(nodes[i]);
            }
        }
        for (int i = c-1; i >= 0; i--) {
            cout << "/" << path[i];
        }
        cout << "/" << checkFile;
    }
    else {
        cout << "(╯°□°）╯︵ ┻━┻ - Not found, Alas!!!" << endl;
        cout << "┬─┬ /( ゜-゜/) - Calm down bro." << endl;
    }
}