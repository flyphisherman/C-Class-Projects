/***********************
Name: Pangram Determiner
Author: Zach Thompson
Version: 1.0 4/12/2019
Purpose: To find out if a sentence is a pangram.
Variables:
    sentence As String
    letters As Int Array
    alphabet As Char Array
    letterVal As Int
    lettersFound As Int
    letter As Char
************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Setting up the variables
    string sentence;
    int letters[26] = { };
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'w', 'v', 'x', 'y', 'z'};
    int letterVal = 0, lettersFound = 0;
    char letter;
    // Getting the sentence
    cout << "Please enter your sentence: ";
    getline(cin, sentence);
    // Looping through the letters
    for (int i = 0; i < sentence.length(); i++) {
        letter = tolower(sentence.at(i));
        letterVal = int(letter) - 97;
        if (letters[letterVal] == 0) {
            lettersFound++;
        }
        letters[letterVal] += 1;
    }
    // If it found 26 unique letters it must be a Pangram
    if (lettersFound == 26) {
        cout << "Pangram" << endl;
    }
    else {
        cout << "Not pangram" << endl;
    }
    // Looping through the letters of the alphabet
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << "-" << letters[i] << endl;
    }

    return 0;
}
