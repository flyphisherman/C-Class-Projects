/***********************
Name: Text Manipulation
Author: Zach Thompson
Version: 1.0 4/12/2019
Purpose: To be able to fill out a sentence with a template
Variables:
    stringToReplace As String
    values As String
    keyLocation As Int
    valueLocation As Int
    wordLength As Int
    replacement As String
    sentence As String
    bracketLocationA As Int
    bracketLocationB As Int
************************/

#include <string>
#include <iostream>

using namespace std;

// Here is to find the replacement string and return it
string replacementFind(string stringToReplace, string values) {
    cout << stringToReplace << endl;
    int keyLocation = values.find(stringToReplace);
    int valueLocation = values.find("=", keyLocation + 1);
    int wordLength = values.find(",", valueLocation + 1) - (valueLocation + 1);
    string replacement = values.substr(valueLocation + 1, wordLength);
    return replacement;
}

// Here is my main function
int main(){
    // Setting up variables and getting values
    string values;
    cout << "Please enter the values: ";
    getline(cin, values);
    string sentence;
    cout << "Please enter the template: ";
    getline(cin, sentence);

    // Finding the first location
    int bracketLocationA = sentence.find("["), bracketLocationB = sentence.find("]");
    int wordLength = 0;

    // Looping through the sentence to find the keys
    while (bracketLocationA != string::npos && bracketLocationB != string::npos) {
        wordLength = bracketLocationB - bracketLocationA;
        sentence.replace(bracketLocationA, wordLength + 1, replacementFind(sentence.substr(bracketLocationA + 1, wordLength - 1), values));
        bracketLocationA = sentence.find("[", bracketLocationA + 1);
        bracketLocationB = sentence.find("]", bracketLocationB + 1);
    }

    // Printing out the final sentence
    cout << sentence << "\n";
}
