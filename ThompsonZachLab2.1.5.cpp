/********************
Name: Leap Year Deducer
Author: Zach Thompson
Version: 1.0 3/26/2019
Summary: This program is designed to be able
    to tell you whether a year is a leap year
    or not.
Variables:
    year As Int
    leapYear As Bool
*********************/

#include <iostream>

using namespace std;

int main(void) {
    //Variable 'year' is to store the year the user has entered
    int year;
    //Variable 'leapYear' is to store the result
    bool leapYear;

    //Basic user input and storage
    cout << "Enter a year: ";
    cin >> year;

    //A series of control statements to be able figure out whether the year is leap or common
    //I use the modulus to be able to figure out if it divides evenly or not
    if ((year % 4) == 0) {
        if ((year % 400) == 0) {
            leapYear = true;
        }
        else if ((year % 100) != 0) {
            leapYear = true;
        }
        else {
            leapYear = false;
        }
    }
    else {
        leapYear = false;
    }

    //This is just using the results from the 'brains' of the program
    if (leapYear) {
        cout << "Leap Year";
    }
    else {
        cout << "Common Year";
    }
    return 0;
}
