/***********************
Name: Gym Membership Program
Author: Zach Thompson
Version: 1.0 4/21/2019
Purpose: To keep track of gym memberships
Variables:
    memberID As Int
    name As String
    memberLength As Int
    next As Pointer
    head As Pointer
    new_head As Node
    current As Node
    previous As Node
    memberIDPlacement As Int
    namePlacement As Int
    phrase As String
    extensionPlacement As Int
    extension As Int
************************/

#include <iostream>
#include <string>

using namespace std;

// Slightly tweaked node to hold more data
class Node {
    public:
        Node(int memberID, string name, int memberLength);
        int memberID;
        string name;
        int memberLength;
        Node* next;
};

Node::Node(int memberID, string name, int memberLength) {
    this->memberID = memberID;
    this->name = name;
    this->memberLength = memberLength;
    this->next = nullptr;
}

// Added more methods to the List class
class List {
    public:
        List();
        void push_front(int memberID, string name, int memberLength);
        Node * find_node(int memberID);
        void delete_node(int memberID);
        bool pop_front();
        void processPhrase(string phrase);
    private:
        Node* head;
};

List::List() {
    this->head = nullptr;
}

void List::push_front(int memberID, string name, int memberLength) {
    Node* new_head = new Node(memberID, name, memberLength);
    new_head->next = this->head;
    this->head = new_head;
}

// To be able to find the node I am looking for and return it
Node * List::find_node(int memberID) {
    Node* current = new Node(0, "John", 0);
    current = this->head;
    while (current != nullptr) {
        if (current->memberID == memberID) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Deleting the node that I need to delete
void List::delete_node(int memberID) {
    Node* current = new Node(0, "John", 0);
    Node* previous = new Node(0, "John", 0);
    current = this->head;
    while (current != nullptr) {
        if (current->memberID == memberID) {
            previous->next = current->next;
            delete current;
        }
        previous = current;
        current = current->next;
    }
}

bool List::pop_front() {
    // This is the code that I created
    // It makes a temporary node to store the head node's data
    Node *current = new Node(0, "John", 0);
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

// This is to get the Member ID number
int getMemberID(string phrase) {
    int memberIDPlacement = phrase.find(" ") + 1;
    int memberID = phrase.at(memberIDPlacement) - '0';
    return memberID;
}

// This is to get the name of the Member
string getName(string phrase) {
    int namePlacement = phrase.find(" ") + 3;
    return phrase.substr(namePlacement);
}

// This is to get how long to increase the membership for
int getExtension(string phrase) {
    int extensionPlacement = phrase.find(" ") + 3;
    int extension = 0;
    // This is if it is longer that one digit
    if (phrase.length() > (extensionPlacement + 1)) {
        extension = phrase.at(extensionPlacement) - '0';
        while (phrase.length() > (extensionPlacement + 1)) {
            extensionPlacement++;
            int tempNumber = phrase.at(extensionPlacement) - '0';
            extension = (extension * 10) + tempNumber;
            cout << extension << endl;
        }
    }
    else {
        extension = phrase.at(extensionPlacement) - '0';
    }
    return extension;
}

// This is the big function to process the phrase to figure out what to do
void List::processPhrase(string phrase) {
    string keyword = getKeyword(phrase);
    if (keyword == "create") {
        Node *test = new Node(0, "John", 0);
        string name = getName(phrase);
        int memberID = getMemberID(phrase);
        this->push_front(memberID, name, 0);
        test = this->find_node(memberID);
        cout << "Member " << test->memberID << ": " << test->name << ", subscription valid for " << test->memberLength << " months" << endl;
    }
    else if ( keyword == "extend") {
        Node *test = new Node(0, "John", 0);
        int memberID = getMemberID(phrase);
        int extension = getExtension(phrase);
        test = this->find_node(memberID);
        test->memberLength += extension;
        cout << "Member " << test->memberID << ": " << test->name << ", subscription valid for " << test->memberLength << " months" << endl;
    }
    else if (keyword == "cancel") {
        Node *test = new Node(0, "John", 0);
        int memberID = getMemberID(phrase);
        test = this->find_node(memberID);
        test->memberLength = 0;
        cout << "Member " << test->memberID << ": " << test->name << ", subscription valid for " << test->memberLength << " months" << endl;
    }

    else if (keyword == "delete") {
        Node *test = new Node(0, "John", 0);
        int memberID = getMemberID(phrase);
        this->delete_node(memberID);
    }
    else if (keyword == "quit") {
        exit(0);
    }
    else {
        cout << "[!] Cannot perform this operation" << endl;
    }
}

int main()
{
    string phrase;
    List list;
    while (true) {
        cout << "Enter Phrase: ";
        getline(cin, phrase);
        list.processPhrase(phrase);
    }
    return 0;
}
