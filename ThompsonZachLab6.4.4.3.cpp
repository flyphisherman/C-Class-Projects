/***********************
Name: Better Password Validation
Author: Zach Thompson
Version: 1.0 4/27/2019
Purpose: To test if a password is valid
Variables:
    reg As Regex Object
    length As Int
    upperReq As Int
    lowerReq As Int
    digit As Int
    specialChar As Int
    valid As Boolean
    input As String
************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

// My class for this program
class StringValidator {
    public:
        ~StringValidator() {};
        bool isValid(string input);
    private:
        int length = 8;
        int upperReq = 1;
        int lowerReq = 1;
        int digit = 1;
        int specialChar = 1;
};
/*
!T3sasdf
*/
// This checks to see if the string is a valid password
bool StringValidator::isValid(string input) {
    // Setting the valid status to false
    bool valid = false;
    // Checking length
    if (this->length = input.length()) {
        valid = true;
    }

    // Every if statement for the rest of the time must have the valid value be true
    // This checks the uppercase requirements
    if (valid && this->upperReq > 0) {
        string pattern = "([A-Z]{" + to_string(this->upperReq) + ",})";
        regex reg(pattern);
        if (regex_search(input, reg)) {
            valid = true;
        }
        else {
            valid = false;
        }
    }

    // This checks the lowercase requirements
    if (valid && this->lowerReq > 0) {
        string pattern = "([a-z]{" + to_string(this->lowerReq) + ",})";
        regex reg(pattern);
        if (regex_search(input, reg)) {
            valid = true;
        }
        else {
            valid = false;
        }
    }

    // This checks the digit requirements
    if (valid && this->digit > 0) {
        string pattern = "([0-9]{" + to_string(this->digit) + ",})";
        regex reg(pattern);
        if (regex_search(input, reg)) {
            valid = true;
        }
        else {
            valid = false;
        }
    }

    // This checks the special character requirements
    if (valid && this->specialChar > 0) {
        string pattern = "([$&+,:;=?@#|'<>.^*()%!-]{" + to_string(this->specialChar) + ",})";
        regex reg(pattern);
        if (regex_search(input, reg)) {
            valid = true;
        }
        else {
            valid = false;
        }
    }
    return valid;
}

// Printing out the results
void printValid(StringValidator &validator, string input) {
    cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid");
}

int main() {
    StringValidator validator;
    string input;
    cout << "Please enter a password to test: ";
    getline(cin, input);
    printValid(validator, input);
}
