/***********************
Name: Ingredient Class Header
Author: Zach Thompson
Version: 1.0 4/30/2019
Purpose: To be able to handle the class and methods related to
    the ingredients.
Variables:
    next As Ingredient Object
    amount As Float
    unitOfMeasurement As String
    name As String
    current As Ingredient Object
    previous As Ingredient Object
    new_step As Ingredient Object
    head As Ingredient Object
************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// This is the ingredient class, like a node
class Ingredient {
    public:
        Ingredient(float amount, string unitOfMeasurement, string name);
        string name;
        float amount;
        string unitOfMeasurement;
        Ingredient* next;
};

// Ingredient class's constructor
Ingredient::Ingredient(float amount = 0, string unitOfMeasurement = "", string name = "") {
    this->name = name;
    this->amount = amount;
    this->unitOfMeasurement = unitOfMeasurement;
    this->next = nullptr;
}

// This is the ingredient list class
class IngredientList {
    public:
        IngredientList();
        bool add_ingredient(float amount, string unitOfMeasurement, string name);
        Ingredient * find_ingredient(string name);
        bool remove_ingredient(string name);
        bool print_ingredient_list(ofstream &outputFile);
    private:
        Ingredient* head;
};

IngredientList::IngredientList() {
    this->head = nullptr;
}

// This is to print out the list of ingredients
bool IngredientList::print_ingredient_list(ofstream &outputFile) {
    Ingredient* current = new Ingredient();
    current = this->head;
    while (current != nullptr) {
        cout << current->amount << "\t" << current->unitOfMeasurement << "\t-\t" << current->name << endl;
        outputFile << current->amount << "\t" << current->unitOfMeasurement << "\t-\t" << current->name << endl;
        current = current->next;
    }
}

// This is to add an ingredient to the list
// I made it so that rather than pushing to the top of the stack, it adds it to the end
bool IngredientList::add_ingredient(float amount, string unitOfMeasurement, string name) {
    if (this->head == nullptr) {
        Ingredient* new_ingredient = new Ingredient(amount, unitOfMeasurement, name);
        new_ingredient->next = this->head;
        this->head = new_ingredient;
    }
    else {
        Ingredient* new_step = new Ingredient(amount, unitOfMeasurement, name);
        Ingredient* current = new Ingredient();
        current = this->head;
        Ingredient* previous = new Ingredient();
        previous = this->head;
        while (current != nullptr) {
            previous = current;
            current = current->next;
        }
        previous->next = new_step;
    }
}

// To be able to find the ingredient I am looking for and return it
Ingredient * IngredientList::find_ingredient(string name) {
    Ingredient* current = new Ingredient();
    current = this->head;
    while (current != nullptr) {
        if (current->name == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Deleting the ingredient that I need to delete
bool IngredientList::remove_ingredient(string name) {
    Ingredient* current = new Ingredient();
    Ingredient* previous = new Ingredient();
    current = this->head;
    while (current != nullptr) {
        if (current->name == name) {
            previous->next = current->next;
            delete current;
        }
        previous = current;
        current = current->next;
    }
}
