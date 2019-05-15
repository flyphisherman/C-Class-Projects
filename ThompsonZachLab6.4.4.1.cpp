/***********************
Name: Really Bad Password Checker
Author: Zach Thompson
Version: 1.0 4/27/2019
Purpose: To check to see if the stored password is correct.
Variables:
    input As String
    secret As String
    dummy As DummyValidator
    exact As ExactValidator
************************/

#include <iostream>
#include <string>

using namespace std;

// Here is the class that checks to see if the stored variable matches the new input
class ExactValidator {
    public:
        ExactValidator(string input);
        virtual ~ExactValidator() {};
        virtual bool isValid(string input);
    private:
        string secret = "";
};

ExactValidator::ExactValidator(string input = "") {
    this->secret = secret;
}

// Matching returns true else false
bool ExactValidator::isValid(string input) {
    if (this->secret == input) {
        return true;
    }
    else {
        return false;
    }
}

// This is the class that just says everything is true
class DummyValidator: public ExactValidator {
    public:
        DummyValidator(string input);
        virtual ~DummyValidator() {};
        virtual bool isValid(string input);
    private:
        string secret = "";
};

DummyValidator::DummyValidator(string input = "") {
    this->secret = secret;
}

// Just a bad move...
bool DummyValidator::isValid(string input) {
    return true;
}

void printValid(ExactValidator &validator, string input) {
    cout << "The string '" << input << "' is " << (validator.isValid("hello") ? "valid" : "invalid") << endl;
}

int main() {
    DummyValidator dummy;
    printValid(dummy, "hello");
    cout << endl;
    ExactValidator exact("secret");
    printValid(exact, "hello");
    printValid(exact, "secret");
    return 0;
}
