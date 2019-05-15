/***********************
Name: Set Bit Counter
Author: Zach Thompson
Version: 1.0 3/27/2019
Summary: This program is designed to be able to tell
    you how many bits are set in any given number.
Variables:
    number As Unsigned Long
    exponent As Unsigned Long
    result As Unsigned Long
    bitCounter As Unsigned Long
************************/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    unsigned long number = 0;
    unsigned long exponent = 1;
    unsigned long result = 0;
    unsigned long bitCounter = 0;

    cout << "Please enter a number: ";
    cin >> number;

    /*************
    I decided to do a while loop because I can change
        the variables tested by it in the same loop.
        It simply goes through until it find a power
        of 2 that is equal to or greater than the number
        left or is equal to 1.  Then it records that there
        is a bit set and then adjusts itself and moves on.
    **************/
    while (result < number) {
        result = pow(2, exponent);
        // If the number is equal then there is no point
        //      in continuing
        if (result == number) {
            bitCounter++;
            break;
        }
        // If the number is equal to 1
        else if (number == 1) {
            bitCounter++;
            break;
        }
        // If the result is bigger than the number
        else if (result > number) {
            bitCounter++;
            // We have to decrease the power by one to
            //      compensate for the last line of the
            //      while statement
            result = pow(2, (exponent - 1));
            // Resetting the variables
            number -= result;
            result = 0;
            exponent = 1;
        }
        else {
            exponent++;
        }
    }

    cout << bitCounter;
    return 0;
}
