#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
};

struct node* createRoot(int key) {
    // Allocate memory for new node
    struct node* node = (struct node*)malloc(sizeof(struct node));
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = NULL;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return(node);
}

struct node* createNode(int key, struct node* parent) {
    // Allocate memory for new node
    struct node* node = (struct node*)malloc(sizeof(struct node));
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = parent;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    // Set this node as a child to its parent
    if(node->parent != NULL) {
        if(node->parent->leftChild != NULL) {
            struct node* child = node->parent->leftChild;
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

struct node* getParent(struct node* node) {
    return node->parent;
}

struct node* getChild(struct node* node, int k) {
    struct node* child = node->leftChild;
    for(int i=1; i<k; i++) {
        child = child->rightSibling;
    }
    return child;
}

void isRoot(struct node* node) {
    if(node->parent == NULL)
        printf("Yes\n");
    else
        printf("No\n");
}

void isExternal(struct node* node) {
    if(node->leftChild == NULL)
        printf("Yes\n");
    else
        printf("No\n");
}

int depth(struct node* node) {
    int depth = 0;
    while(node->parent != NULL) {
        node = node->parent;
        depth++;
    }
    return depth;
}

int height(struct node* node) {
    if(node->leftChild == NULL)
        return 0;
    else {
        int maxHeight = 0;
        struct node* child = node->leftChild;
        while(child != NULL) {
            int h = height(child);
            if(h > maxHeight)
                maxHeight = h;
            child = child->rightSibling;
        }
        return maxHeight + 1;
    }
}

// preorder traversal
void preorder(struct node* node) {
    printf("%d ", node->key);
    if(node->leftChild != NULL) {
        struct node* child = node->leftChild;
        while(child != NULL) {
            preorder(child);
            child = child->rightSibling;
        }
    }
}

// postorder traversal
void postorder(struct node* node) {
    if(node->leftChild != NULL) {
        struct node* child = node->leftChild;
        while(child != NULL) {
            postorder(child);
            child = child->rightSibling;
        }
    }
    printf("%d ", node->key);
}

int main() {
    /*create root*/
    struct node* node1 = createRoot(1);
    struct node* node2 =createNode(2, node1);
    struct node* node3 =createNode(3, node1);
    struct node* node4 =createNode(4, node2);
    /* 4 becomes left child of 2
            1
          / \
        2    3
      /
    4
    */
    printf("%d\n", getParent(node2)->key); // output "1"
    printf("%d\n", getChild(node1,2)->key); // output “3”
    isRoot(node1); // output "Yes"
    isExternal(node2); // output "No"
    printf("%d\n", depth(node4)); // output "2"
    printf("%d\n", height(node1)); // output "2"
    return 0;
}