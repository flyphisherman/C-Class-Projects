/***********************
Name: Singly Linked List Part 1
Author: Zach Thompson
Version: 1.0 4/20/2019
Purpose: To practice working with Linked Lists
Variables:
    value As Int
    next As Pointer
    numberOfElements As Int
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
        int size();
        int get_value();
    private:
        int numberOfElements = 0;
        Node* head;
};

List::List() {
    this->head = nullptr;
}

// Created this to output the number of nodes
List::size() {
    return this->numberOfElements;
}

// This is to get the value out of the head node
List::get_value() {
    return this->head->value;
}

void List::push_front(int value) {
    this->numberOfElements++;
    Node* new_head = new Node(value);
    new_head->next = head;
    head = new_head;
}

bool List::pop_front() {
    // This is the code that I created
    // It makes a temporary node to store the head node's data
    this->numberOfElements--;
    Node *temp = new Node(0);
    temp = this->head;
    // Then it deletes the head node
    delete this->head;
    // It then replaces the head node with the second node
    this->head = temp->next;
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
    for (int i = 0; i <= 5; i++) {
        list.push_front(i);
        cout << "pushed " << i << ", size: " << list.size() << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        // Getting the value of the node before I pop it
        int value = list.get_value();
        list.pop_front();
        cout << "popped " << value << ", size: " << list.size() << endl;
    }

    return 0;
}
