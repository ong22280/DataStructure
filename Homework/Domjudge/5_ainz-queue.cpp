#include<iostream>
using namespace std;
#define MAX 100

string queue[MAX];
int front = - 1;
int rear = - 1;

void enqueue(string name) {
    if ((rear == MAX -1 && front == 0) || (rear + 1 == front)) {
        return;
    }
    if (front == MAX -1) {
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = name;
    if (front == -1) {
        front = 0;
    }
}

string dequeue() {
    string name;
    if (front == -1) {
        return NULL;
    }
    else {
        name = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            if (front == MAX - 1) {
                front = 0;
            }
            front++;
        }
    }
    return name;
}

void peek() {
    if (front == -1) {
        return;
    }
    else {
        cout << queue[front] << endl;
    }
}

void empty() {
    if (front == -1) {
        cout << "EmPTy" << endl;
    }
    else {
        cout << "nOT EmpTY" << endl;
    }
}

int main() {
    string choice;
    while (true) {
        cin >> choice;
        if (choice == "enqueue") {
            cin >> choice;
            enqueue(choice);
        }
        else if (choice == "dequeue") {
            cout << dequeue() << endl;
        }
        else if (choice == "peek") {
            peek();
        }
        else if (choice == "empty?") {
            empty();
        }
        else if (choice == "exit") {
            break;
        }
    }
    return 0;
}