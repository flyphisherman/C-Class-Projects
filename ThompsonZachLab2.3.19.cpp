/***********************
Name: Pi Calculator
Author: Zach Thompson
Version: 1.0 3/27/2019
Summary: This is a program to be able to figure out Pi
    within a certain amount of accuracy
Variables:
    pi4 As Double
    number As Long
    whileCounter As Long
    denominator As Double
************************/

#include <iostream>
using namespace std;
int main(void) {

    // I use whileCounter to be able to keep track of
    //      how many times through the loop I have been
    //      Denominator is the denominator
    double pi4 = 0.;
    long number;
    long whileCounter = 1;
    double denominator = 1.;

    cout << "Number of iterations? ";
    cin >> number;

    // This is to loop through the required number of times
    while (whileCounter <= number) {
        // This is to figure out whether to add or subtract
        if ((whileCounter % 2) == 0) {
            pi4 -= 1 / denominator;
        }
        else {
            pi4 += 1 / denominator;
        }
        // Increment counter and denominator
        denominator += 2;
        whileCounter++;
    }

    cout.precision(20);
    cout << "Pi = " << (pi4 * 4.) << endl;

    return 0;
}
