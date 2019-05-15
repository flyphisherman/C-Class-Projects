/***********************
Name: Grade Calculator
Author: Zach Thompson
Version: 1.0 4/12/2019
Purpose: To calculate the grade of a student and show a summary
Variables:
    item As String
    numberOfGrades As Int
    gradeList As Array
    itemList As Array
    gradeString As Array
    numberOfCourses As Int
    overallAverage As Double
    tempArray As Array
    finalTotal As Int
    finalAverage As Double
************************/

#include <iostream>
#include <string>

using namespace std;
// Here is a function to take a string and get the numbers from it
int * addItem(string item) {
    int numberOfGrades = item.length() / 2;
    int* gradeList = new int[numberOfGrades];
    for (int x = 0; x < (numberOfGrades); x++) {
        gradeList[x] = item[x*2] - '0';
    }
    gradeList[numberOfGrades] = item.at(item.length()-1) - '0';
    return gradeList;
}

// Here is the main function
int main() {
    // Setting up the variables
    int **itemList;
    string gradeString;
    int numberOfCourses;
    double overallAverage = 0;
    // Getting input
    cout << "How many courses would you like to enter the grades for: ";
    cin >> numberOfCourses;
    itemList = new int * [numberOfCourses];
    cin.ignore();
    // Getting the grades
    for (int i = 0; i < numberOfCourses; i++){
        cout << "Please enter the grades: ";
        getline(cin, gradeString);
        if (gradeString != "") {
            itemList[i] = new int[(gradeString.length() / 2 + 1)];
            int* tempArray = addItem(gradeString);
            itemList[i] = tempArray;
        }
    }
    // Finding the averages
    for (int i = 0; i < numberOfCourses; i++) {
        int finalTotal = 0;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "Course " << i + 1 << ": final ";
        for (int x = 1; x <= itemList[i][0]; x++){
            finalTotal += itemList[i][x];
        }
        double finalAverage = double(finalTotal) / double((itemList[i][0]));
        cout << finalAverage << ", grades: ";
        for (int x = 1; x <= itemList[i][0]; x++){
            cout << itemList[i][x] << " ";
        }
        cout << endl;
        overallAverage += finalAverage;
    }
    overallAverage = overallAverage / numberOfCourses;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Overall final " << overallAverage << endl;
    return 0;
}
