/***********************
Name: Comparing Floating Numbers
Author: Zach Thompson
Version: 1.0 4/12/2019
Purpose: To see if a float is within range of another float
************************/

#include <iostream>
#include <math.h>
using namespace std;

bool is_close(double a, double b, double tolerance){
    // STARTING HERE
    // This is all of the code I wrote.
    // It is a simple comparison
    if ((a + tolerance >= b) && (a - tolerance <= b)) {
        return true;
    }
    else {
        return false;
    }
    // ENDS HERE
}

int main(void) {
    if (0.3 == 3 * 0.1) {
        cout << "The numbers are equal";
    } else {
        cout << "The numbers are not equal";
    }
        cout << endl;
    if (is_close(0.3, 3 * 0.1, 0.00000001)) {
        cout << "The numbers are close enough";
    } else {
        cout << "The numbers are not close enough";
    }
        cout << endl;
    // this should work regardless of the argument order
    if (is_close(3 * 0.1, 0.3, 0.00000001)) {
        cout << "The numbers are still close enough";
    } else {
        cout << "The numbers are not close enough";
    }
        cout << endl;
    if (is_close(3 * 0.1, 0.31, 0.00000001)) {
        cout << "The numbers are still close enough";
    } else {
        cout << "The numbers are not close enough";
    }
        cout <<endl;
    return 0;
}
