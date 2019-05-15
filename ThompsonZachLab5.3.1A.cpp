/***********************
Name: Singly Linked List Part 1
Author: Zach Thompson
Version: 1.0 4/20/2019
Purpose: To practice working with Linked Lists
Variables:
    value As Int
    next As Pointer
************************/

#include <iostream>

using namespace std;

class Node {
    public:
        Node(int val);
        int value;
        Node* next;
};

Node::Node(int val) {
    this->value = val;
    this->next = nullptr;
}

class List {
    public:
        List();
        void push_front(int value);
        bool pop_front();
    private:
        Node* head;
};

List::List() {
    this->head = nullptr;
}

void List::push_front(int value) {
    Node* new_head = new Node(value);
    new_head->next = head;
    head = new_head;
}

bool List::pop_front() {
    // This is the code that I created
    // It makes a temporary node to store the head node's data
    Node *temp = new Node(0);
    temp = this->head;
    // Then it deletes the head node
    delete this->head;
    // It then replaces the head node with the second node
    this->head = temp->next;
    cout << temp->value << endl;
    // Then deletes the temporary copy
    delete temp;
    // To see if we should continue
    if (this->head != nullptr) {
        return true;

    } else {
        return false;
    }
}

int main() {
    List list;
    //
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    while (list.pop_front()) {
        continue;
    }
    return 0;
}
