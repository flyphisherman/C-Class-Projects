/***********************
Name: Mediocre Password Validation
Author: Zach Thompson
Version: 1.0 4/27/2019
Purpose: To validate a password
Variables:
    maxLength As Int
    minLength As Int
    reqChar As String
    input As String
    reg As Regex Object
    min As MinLengthValidator Object
    max As MaxLengthValidator Object
    digit As PatternValidator Object
************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Base class
class StringValidator {
    public:
        //virtual ~StringValidator() {};
        virtual bool isValid(string input) {};
    protected:
        int maxLength = 0;
        int minLength = 0;
        string reqChar;
};

// The Min Length class
class MinLengthValidator: public StringValidator {
    public:
        MinLengthValidator(int minLength);
        bool isValid(string input);
};

MinLengthValidator::MinLengthValidator(int minLength) {
    this->minLength = minLength;
}

bool MinLengthValidator::isValid(string input) {
    if (input.length() >= this->minLength) {
        return true;
    }
    else {
        false;
    }
}

// Max Length Class
class MaxLengthValidator: public StringValidator {
    public:
        MaxLengthValidator(int maxLength);
        bool isValid(string input);
};

MaxLengthValidator::MaxLengthValidator(int maxLength) {
    this->maxLength = maxLength;
}

bool MaxLengthValidator::isValid(string input) {
    if (input.length() >= this->maxLength) {
        return true;
    }
    else {
        false;
    }
}

// Checking to see if it matches a pattern
class PatternValidator: public StringValidator {
    public:
        PatternValidator(string reqChar);
        bool isValid(string input);
};

PatternValidator::PatternValidator(string reqChar) {
    this->reqChar = reqChar;
}

bool PatternValidator::isValid(string input) {
    if (this->reqChar == "D") {
        regex reg("([0-9]+)");
        if (regex_search(input.begin(), input.end(), reg)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }
}

// Printing the results
void printValid(StringValidator &validator, string input) {
    cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid");
}

int main() {
    cout << "MinLengthValidator" << endl;
    MinLengthValidator min(6);
    printValid(min, "hello");
    printValid(min, "welcome");
    cout << endl;

    cout << "MaxLengthValidator" << endl;
    MaxLengthValidator max(6);
    printValid(max, "hello");
    printValid(max, "welcome");
    cout << endl;

    cout << "PatternValidator" << endl;
    PatternValidator digit("D");
    printValid(digit, "there are 2 types of sentences in the world");
    cout << endl;
    printValid(digit, "valid and invalid ones");
    cout << endl;

    return 0;
}
