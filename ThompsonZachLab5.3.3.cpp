/***********************
Name: Flight Booking Program
Author: Zach Thompson
Version: 1.0 4/21/2019
Purpose: To be able to create, edit and delete flights
Variables:
    id As Int
    capacity As Int
    reserved As Int
    next As Node
    head As Node
    flightCounter As Int
    new_head As Node
    current As Node
    previous As Node
    wordLength As Int
    phrase As String
    firstSpacePlacement As Int
    secondSpacePlacement As Int
    wordLength As Int
    ptrPlacement As Int
    tempNumber As Int
    quantity As Int
    spacePlacement As Int
    percentage As Int
    command As String
Notes:
    I decided to use a Singly Linked List because it seemed like a better
option than the solution that was presented in the lab.
************************/

#include <iostream>
#include <string>

using namespace std;

// Setting up the Node class
class Node {
    public:
        Node(int id, int capacity, int reserved);
        int id;
        int capacity;
        int reserved;
        Node* next;
};

Node::Node(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
    this->next = nullptr;
}

// Setting up the List class to keep track of the Nodes
class List {
    public:
        List();
        void push_front(int id, int capacity, int reserved);
        Node * find_node(int id);
        void delete_node(int id);
        bool pop_front();
        void processPhrase(string phrase);
    private:
        Node* head;
        int flightCounter = 0;
};

List::List() {
    this->head = nullptr;
}

void List::push_front(int id, int capacity, int reserved) {
    Node* new_head = new Node(id, capacity, reserved);
    new_head->next = this->head;
    this->head = new_head;
    this->flightCounter++;
}

// To be able to find the node I am looking for and return it
Node * List::find_node(int id) {
    Node* current = new Node(0, 0, 0);
    current = this->head;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Deleting the node that I need to delete
void List::delete_node(int id) {
    Node* current = new Node(0, 0, 0);
    Node* previous = new Node(0, 0, 0);
    current = this->head;
    while (current != nullptr) {
        if (this->flightCounter > 1) {
            if (current->id == id) {
                previous->next = current->next;
                delete current;
                this->flightCounter--;
            }
            previous = current;
            current = current->next;
        }
        else {
            delete current;
            this->head = nullptr;
            break;
        }
    }
}

bool List::pop_front() {
    // This is the code that I created
    // It makes a temporary node to store the head node's data
    Node *current = new Node(0, 0, 0);
    current = this->head;
    // Then it deletes the head node
    delete this->head;
    // It then replaces the head node with the second node
    this->head = current->next;
    // Then deletes the temporary copy
    delete current;
    // To see if we should continue
    if (this->head != nullptr) {
        return true;

    } else {
        return false;
    }
}

// A series of functions to be able to process the string input
// This is to get the keyword
string getKeyword(string phrase) {
    int wordLength = phrase.find(" ");
    string keyword = phrase.substr(0, wordLength);
    return keyword;
}

// This is to get the ID number
int getId(string phrase) {
    int firstSpacePlacement = phrase.find(" ");
    int secondSpacePlacement = phrase.find(" ", firstSpacePlacement + 1);
    int wordLength = secondSpacePlacement - firstSpacePlacement - 1;
    int id = 0;
    if (wordLength > 1) {
        id = phrase.at(firstSpacePlacement + 1) - '0';
        int ptrPlacement = firstSpacePlacement + 1;
        while ((secondSpacePlacement - 1) > ptrPlacement) {
            ptrPlacement++;
            int tempNumber = phrase.at(ptrPlacement) - '0';
            id = (id * 10) + tempNumber;
        }
    }
    else {
        id = phrase.at(firstSpacePlacement + 1) - '0';
    }
    return id;
}

// This is to get the quantity out of the phrase
int getQuantity(string phrase) {
    int spacePlacement = phrase.find(" ");
    spacePlacement = phrase.find(" ", spacePlacement + 1);
    int ptrPlacement = spacePlacement + 1;
    int quantity = 0;
    // This is if it is longer that one digit
    if (phrase.length() > (ptrPlacement + 1)) {
        quantity = phrase.at(ptrPlacement) - '0';
        while (phrase.length() > (ptrPlacement + 1)) {
            ptrPlacement++;
            int tempNumber = phrase.at(ptrPlacement) - '0';
            quantity = (quantity * 10) + tempNumber;
        }
    }
    else {
        quantity = phrase.at(ptrPlacement) - '0';
    }
    return quantity;
}

// This is the big function to process the phrase to figure out what to do
void List::processPhrase(string phrase) {
    string keyword = getKeyword(phrase);
    if (keyword == "create") {
        if (this->flightCounter <= 10) {
            Node *test = new Node(0, 0, 0);
            int quantity = getQuantity(phrase);
            int id = getId(phrase);
            this->push_front(id, quantity, 0);
            test = this->find_node(id);
            int percentage = (test->reserved / test->capacity);
            cout << "Flight " << test->id << ": " << test->reserved << "/" << test->capacity << " (" << percentage << "%) seats reserved" << endl;
        }
        else {
            cout << "Cannot perform this operation: Too many flights are booked";
        }
    }
    else if ( keyword == "add") {
        Node *test = new Node(0, 0, 0);
        int id = getId(phrase);
        int quantity = getQuantity(phrase);
        test = this->find_node(id);
        if (test != nullptr) {
            if ((test->reserved + quantity) <= test->capacity) {
                test->reserved += quantity;
                int percentage = (test->capacity / test->reserved);
                cout << "Flight " << test->id << ": " << test->reserved << "/" << test->capacity << " (" << percentage << "%) seats reserved" << endl;
            }
            else {
                cout << "Cannot perform this operation: flight " << id << " does not have enough seats" << endl;
            }
        }
        else {
            cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
    }
    else if (keyword == "cancel") {
        Node *test = new Node(0, 0, 0);
        int id = getId(phrase);
        int quantity = getQuantity(phrase);
        test = this->find_node(id);
        if (test != nullptr) {
            if (quantity <= test->reserved) {
                test->reserved = quantity;
                int percentage = (test->capacity / test->reserved);
                cout << "Flight " << test->id << ": " << test->reserved << "/" << test->capacity << " (" << percentage << "%) seats reserved" << endl;
            }
            else {
                cout << "Cannot perform this operation: flight " << id << " does not have enough reserved seats" << endl;
            }
        }
        else {
            cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
    }

    else if (keyword == "delete") {
        Node *test = new Node(0, 0, 0);
        int id = getId(phrase);
        this->delete_node(id);
    }
    else if (keyword == "quit") {
        exit(0);
    }
    else {
        cout << "[!] Cannot perform this operation" << endl;
    }
}



// ...

int main() {
    List list;
    string command = "";
    while (command != "quit") {
        cout << "Command: ";
        getline(cin, command);
        list.processPhrase(command);
    }
    return 0;
}
