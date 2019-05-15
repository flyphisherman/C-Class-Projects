/***********************
Name: Function Overloader
Author: Zach Thompson
Version: 1.0 4/6/2019
Purpose: To learn how to overload a function
Variables:
    intvar As Int
    floatvar As Float
    i As Int
************************/

#include <iostream>
#include <cmath>
using namespace std;

// My special functions
void increment(int &var, int exp = 1) {
    var += exp;
}

void increment(float &var, float exp = 1.0) {
    var += exp;
}

// The given code
int main(void) {
    int intvar = 0;
    float floatvar = 1.5;
    for(int i = 0; i < 10; i++) {
        if(i % 2) {
            increment(intvar);
            increment(floatvar, sqrt(intvar));
        }
        else {
            increment(intvar,i);
            increment(floatvar);
        }
    }
    cout << intvar * floatvar << endl;
    return 0;
}
