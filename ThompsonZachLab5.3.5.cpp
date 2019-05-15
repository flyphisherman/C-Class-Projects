/***********************
Name: Fraction Processor
Author: Zach Thompson
Version: 1.0 4/21/2019
Purpose: To be able to figure out how to write an improper fraction and the result
Variables:
    numerator As Int
    denominator As Int
    remainder As Int
    phrase As String
    improper As Int
    decimal As Double
    spaceLocation As Int
    firstSpaceLocation As Int
    ptrLocation As Int
************************/

#include <iostream>
#include <string>

using namespace std;

class Fraction{
    public:
        Fraction(int numerator, int denominator);
        string toString();
        double toDouble();
    private:
        int numerator;
        int denominator;
};

// To setup the object
Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

// Get the output of the fraction as a string
string Fraction::toString() {
    int improper = this->numerator / this->denominator;
    int remainder = this->numerator % this->denominator;
    string phrase = "";
    if (remainder != 0) {
        if (improper == 0) {
            phrase = to_string(remainder) + "/" + to_string(this->denominator);
        }
        else {
            phrase = to_string(improper) + " " + to_string(remainder) + "/" + to_string(this->denominator);
        }
    }
    else {
        phrase = to_string(improper);
    }
    return phrase;
}

// This is to get the result of the equation
double Fraction::toDouble() {
    double numerator = this->numerator;
    double denominator = this->denominator;
    double decimal = numerator / denominator;
    return decimal;
}

// This is to get the numerator out of the string
int getNumerator(string phrase) {
    int numerator = 0;
    int spaceLocation = phrase.find(" ");
    int ptrLocation = 0;
    if (spaceLocation > 1) {
        if (phrase.substr(ptrLocation, 1) == "-") {
            ptrLocation++;
            numerator = phrase.at(ptrLocation) - '0';
            numerator = numerator * -1;
        }
        else {
            numerator = phrase.at(ptrLocation) - '0';
        }
        while (spaceLocation > (ptrLocation + 1)) {
            ptrLocation++;
            int tempNumber = phrase.at(ptrLocation++) - '0';
            numerator = (numerator * 10) + tempNumber;
        }
    }
    else {
        numerator = phrase.at(ptrLocation) - '0';
    }
    return numerator;
}

// This is to get the denominator out of the string
int getDenominator(string phrase) {
    int denominator = 0;
    int firstSpaceLocation = phrase.find(" ");
    int spaceLocation = phrase.find(" ", firstSpaceLocation + 1);
    int ptrLocation = spaceLocation + 1;
    if (phrase.length() > (ptrLocation + 1)) {
        if (phrase.substr(ptrLocation, 1) == "-") {
            ptrLocation++;
            denominator = phrase.at(ptrLocation) - '0';
            denominator = denominator * -1;
        }
        else {
            denominator = phrase.at(ptrLocation) - '0';
        }
        while (phrase.length() > (ptrLocation + 1)) {
            ptrLocation++;
            int tempNumber = phrase.at(ptrLocation++) - '0';
            denominator = (denominator * 10) + tempNumber;
        }
    }
    else {
        denominator = phrase.at(ptrLocation) - '0';
    }
    return denominator;
}

// implement Fraction methods
int main() {
    int numerator, denominator;
    cout << "Enter a fraction (N / D): ";
    string phrase = "";
    getline(cin,phrase);
    // parse input and get numerator and denominator
    numerator = getNumerator(phrase);
    denominator = getDenominator(phrase);
    Fraction fraction(numerator, denominator);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    return 0;
}
