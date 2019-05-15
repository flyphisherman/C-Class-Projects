/***********************
Name: Multiplication Table Builder
Author: Zach Thompson
Version: 1.0 4/6/2019
Purpose: To create a multiplication table in a matrix
Variables:
    matrix As Multidimensional Array
    ptrY As Int *
    ptrX As Int *
    i As Int
    j As Int
************************/

#include <iostream>
using namespace std;

int main(void) {

    // Declaring the matrix
    int matrix[10][10] = { };

    // Setting up the pointers as needed
    int (*ptrY)[10] = matrix;
    int *ptrX = *ptrY;

    // Going through the pointers to set each value
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            *ptrX = (i + 1) * (j + 1);
            ptrX++;
        }
        ptrY++;
    }

    // Printing the results
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
