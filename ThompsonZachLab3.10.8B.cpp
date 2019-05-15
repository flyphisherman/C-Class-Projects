/***********************
Name: Brain Hurter 5000
Author: Zach Thompson
Version: 1.0 4/6/2019
Purpose: To hurt my brain. In actuality it was train us in how to
    create new and delete reserved spots on the stack.
Variables:
    Collection As Struct
    col As Struct
    elno As Int
    element As Int
    element As Int
    tempVector As Array
    elems As Int
************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Collection {
    int elno;
    int *elements;
};

// This is the function I worked on
void AddToCollection(Collection &col, int element) {
    // If there is nothing there then create an array
    if (!col.elements) {
        col.elements = new int[1];
    }
    // Else copy the existing array, delete the original, make a new one and put it all back.
    else {
        int *tempVector = new int[col.elno + 1];
        for (int i = 0; i < col.elno; i ++) {
            tempVector[i] = col.elements[i];
        }
        delete[] col.elements;
        col.elements = tempVector;
    }
    // Add the new element and increment the elno
    col.elements[col.elno] = element;
    col.elno++;
}

// Code that was given to me
void PrintCollection(Collection col) {
    cout << "[ ";
    for(int i = 0; i < col.elno; i++)
        cout << col.elements[i] << " ";
    cout << "]" << endl;
}

int main(void) {
    Collection collection = { 0, NULL };
    int elems;
    cout << "How many elements? ";
    cin >> elems;
    srand(time(NULL));
    for(int i = 0; i < elems; i++) {
        AddToCollection(collection, rand() % 100 + 1);
    }
    PrintCollection(collection);
    delete[] collection.elements;
    return 0;
}
