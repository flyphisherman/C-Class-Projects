/***********************
Name: Date Stater
Author: Zach Thompson
Version: 1.0 4/6/2019
Purpose: To print today's date.
Variables:
    Date As Struct
    year As Int
    month As Int
    day As Int
    tempDate As Date
    t As Date
************************/

#include <iostream>
#include <ctime>
using namespace std;

// Creating the Date structure
struct Date {
    int year;
    int month;
    int day;
};

// Creating the magical function
Date today(void) {
    Date tempDate;
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    tempDate.year = tl.tm_year+1900;
    tempDate.month = tl.tm_mon+1;
    tempDate.day = tl.tm_mday;
    return tempDate;
}

// The code provided
int main(void) {
    Date t = today();
    cout << t.year << "-" << t.month << "-" << t.day << endl;
    return 0;
}
