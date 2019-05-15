/***********************
Name: Direction Class Header
Author: Zach Thompson
Version: 1.0 4/30/2019
Purpose: To be able to handle the class and methods related to
    the directions.
Variables:
    next As Step Object
    step As String
    current As Step Object
    previous As Step Object
    new_step As Step Object
    head As Step Object
    stepNumber As Int
************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// This is the step class, like a node
class Step {
    public:
        Step(string step);
        string step;
        Step* next;
};

// This is the step class, like a node
Step::Step(string step = "") {
    this->step = step;
    this->next = nullptr;
}

// This is the steps list class
class StepList {
    public:
        StepList();
        bool add_step(string step, int stepNumber);
        bool print_step_list(ofstream &outputFile);
    private:
        Step* head;
};

StepList::StepList() {
    this->head = nullptr;
}

// This is to print out the list of steps
bool StepList::print_step_list(ofstream &outputFile) {
    Step* current = new Step();
    current = this->head;
    while (current != nullptr) {
        cout << current->step << endl;
        outputFile << current->step << endl;
        current = current->next;
    }
}

// This is to add an step to the list
// I made it so that rather than pushing to the top of the stack, it adds it to the end
bool StepList::add_step(string step, int stepNumber) {
    step = to_string(stepNumber) + ") " + step;
    if (this->head == nullptr) {
        Step* new_step = new Step(step);
        new_step->next = this->head;
        this->head = new_step;
    }
    else {
        Step* new_step = new Step(step);
        Step* current = new Step();
        current = this->head;
        Step* previous = new Step();
        previous = this->head;
        while (current != nullptr) {
            previous = current;
            current = current->next;
        }
        previous->next = new_step;
    }
}


