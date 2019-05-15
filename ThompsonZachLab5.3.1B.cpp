/***********************
Name: Singly Linked List Part 2
Author: Zach Thompson
Version: 1.0 4/20/2019
Purpose: To practice working with Linked Lists
Comments: I moved where the cout statements are because I am using an
    existing couple of functions that I made last lab that creates and
    deletes extra nodes.
Variables:
    value As Int
    next As Pointer
************************/

#include <iostream>

using namespace std;

class Node {
    public:
        Node(int val);
        ~Node();
        int value;
        Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {

}

Node::~Node() {

}

class List {
    public:
        List();
        ~List();
        void push_front(int value);
        bool pop_front();
    private:
        Node* head;
};

List::List() {
    this->head = nullptr;
}

List::~List() {
    while (this->pop_front()) {
        cout << "-Node" << endl;
        continue;
    }
    cout << "-Node" << endl;
}

void List::push_front(int value) {
    cout << "+Node" << endl;
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

    return 0;
}
