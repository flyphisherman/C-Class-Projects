/***********************
Name: Function Argument Modifier
Author: Zach Thompson
Version: 1.0 4/6/2019
Purpose: To learn how to modify the argument
Variables:
    var As Int
    i As Int
************************/

#include <iostream>
using namespace std;

// My special function
void increment(int &var, int exp = 1) {
    var += exp;
}

// The given code
int main(void) {
    int var = 0;
    for(int i = 0; i < 10; i++) {
        if(i % 2)
            increment(var);
        else
            increment(var,i);
    }
    cout << var << endl;
    return 0;
}
