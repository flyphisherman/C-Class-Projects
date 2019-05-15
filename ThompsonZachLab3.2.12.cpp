/***********************
Name: Lowest Number Finder
Author: Zach Thompson
Version: 1.0 4/6/2019
Purpose: To find the smallest number in a array.
Variables:
    vector As Array
    n As Int
    ptr As Int *
    lowest As Int
    i As Int
************************/

#include <iostream>

using namespace std;

int main(void) {
    // Defining the array and getting the size of it
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };

    int n = sizeof(vector) / sizeof(vector[0]);
    // Setting the pointer and setting the starting lowest number which is just
    //  the first number
    int *ptr = vector;

    int lowest = *ptr;

    // Using a for loop to go through the items
    for (int i = n; i > 0; i--) {
            // Using the ? operator for fun
            lowest = lowest > *ptr ? *ptr:lowest;
            // Incrementing the pointer
            ptr++;
    }

    cout << lowest;

    return 0;
}
