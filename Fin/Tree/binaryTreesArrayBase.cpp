#include <iostream>
using namespace std;

string tree[100];
int size = 0;

void root(string key) {
    if (tree[1] == "")
        tree[1] = key;
}

string getLeft(int index) {
    return tree[index * 2];
}

string getRight(int index) {
    return tree[index * 2 + 1];
}

string getParent(int index) {
    return tree[index / 2];
}

bool isRoot(int index) {
    if (index == 1)
        return true;
    else
        return false;
}

bool isExternal(int index) {
    if (tree[index * 2] == "" && tree[index * 2 + 1] == "")
        return true;
    else
        return false;
}

int depth(int index) {
    int d = 0;
    while (index != 1) {
        index = index / 2;
        d++;
    }
    return d;
}

int height(int index) {
    if (isExternal(index))
        return 0;
    else
        return 1 + max(height(index * 2), height(index * 2 + 1));
}

void preOrder(int index) {
    if (tree[index] != "") {
        cout << tree[index] << " ";
        preOrder(index * 2);
        preOrder(index * 2 + 1);
    }
}

void postOrder(int index) {
    if (tree[index] != "") {
        postOrder(index * 2);
        postOrder(index * 2 + 1);
        cout << tree[index] << " ";
    }
}

void inOrder(int index) {
    if (tree[index] != "") {
        inOrder(index * 2);
        cout << tree[index] << " ";
        inOrder(index * 2 + 1);
    }
}

void expandExternal(int index) {
    if (isExternal(index)) {
        tree[index * 2] = "";
        tree[index * 2 + 1] = "";
    }
}

void removeAboveExternal(int index) {
    if (isExternal(index)) {
        if (index == 1)
            tree[index] = "";
        else if (index % 2 == 0)
            tree[index / 2] = "";
        else
            tree[index / 2] = "";
    }
}
int main() {
    root("1");
    expandExternal(1);
    tree[2] = "2";
    tree[3] = "3";
    expandExternal(2);
    tree[4] = "4";
    tree[5] = "5";
    expandExternal(3);
    tree[6] = "6";
    tree[7] = "7";
    cout << "getLeft(1): " << getLeft(1) << endl;
    cout << "getRight(1): " << getRight(1) << endl;
    cout << "getParent(2): " << getParent(2) << endl;
    cout << "isRoot(1): " << isRoot(1) << endl;
    cout << "isExternal(1): " << isExternal(1) << endl;
    cout << "depth(2): " << depth(2) << endl;
    cout << "height(1): " << height(1) << endl;
    cout << "preOrder: ";
    preOrder(1);
    cout << endl;
    cout << "postOrder: ";
    postOrder(1);
    cout << endl;
    cout << "inOrder: ";
    inOrder(1);
    cout << endl;
    removeAboveExternal(2);
    cout << "removeAboveExternal(2): " << tree[1] << endl;
    return 0;
}