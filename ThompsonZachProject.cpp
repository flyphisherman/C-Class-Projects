/***********************
Name: Recipe Creator Program
Author: Zach Thompson
Version: 1.0 4/30/2019
Purpose: To be able to create digital files of your recipes
Variables:
    buffer As Character
    amount As Int
    tempNumber As Int
    phrase As String
    ptrLocation As Int
    spaceLocation As Int
    wordLength As Int
    unitOfMeasurement As String
    name As String
    recipe As IngredientList Object
    outputFile As Ofstream Object
    steps As StepList Object
    numberOfSteps As Int
************************/

#include <windows.h>
#include <iostream>
#include <string>
#include "ingredient.h"
#include "direction.h"
#include <cmath>
#include <fstream>

using namespace std;

// This is a function that I am using to get the current working directory
string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

// This function is to get the ingredient out of the entered string
bool getIngredients(string phrase, IngredientList &recipe) {
    // First we find the amount of the ingredient
    float amount = 0;
    int spaceLocation = phrase.find(" ");
    int ptrLocation = 0;
    if (spaceLocation > 1) {
        if (phrase.substr(ptrLocation, 1) == ".") {
            ptrLocation++;
            amount = phrase.at(ptrLocation) - '0';
            amount = amount / 10;
            float counter = 1;
            while (spaceLocation > (ptrLocation + 1)) {
                counter++;
                ptrLocation++;
                float tempNumber = phrase.at(ptrLocation++) - '0';
                amount = amount + (tempNumber / pow(10, counter));
            }
        }
        else {
            if (phrase.substr(ptrLocation, 1) == "-") {
                ptrLocation++;
                amount = phrase.at(ptrLocation) - '0';
                amount = amount * -1;
            }
            else {
                amount = phrase.at(ptrLocation) - '0';
            }
            while (spaceLocation > (ptrLocation + 1)) {
                ptrLocation++;
                float tempNumber = phrase.at(ptrLocation++) - '0';
                amount = (amount * 10) + tempNumber;
            }
        }
    }
    else {
        amount = phrase.at(ptrLocation) - '0';
    }
    ptrLocation = spaceLocation + 1;
    spaceLocation = phrase.find(" ", ptrLocation);
    int wordLength = spaceLocation - ptrLocation;
    // Next we find the unit of measurement
    string unitOfMeasurement = phrase.substr(ptrLocation, wordLength);
    ptrLocation = spaceLocation + 1;
    spaceLocation = phrase.find(" ", ptrLocation);
    wordLength = spaceLocation - ptrLocation;
    // Last we figure out the ingredient
    string name = phrase.substr(ptrLocation);
    recipe.add_ingredient(amount, unitOfMeasurement, name);
}

// This function is for getting the step entered
void getSteps(string phrase, StepList &steps, int stepNumber) {
    steps.add_step(phrase, stepNumber);
}

// Making sure that the phrase is entered correctly
bool validatePhrase(string phrase) {
    int spaceLocation = phrase.find(" ");
    if (phrase.find(" ", spaceLocation + 1) != string::npos) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    // Setting up the variables and objects needed
    IngredientList recipe;
    ofstream outputFile;
    StepList steps;
    string phrase;
    string name;
    int numberOfIngredients;
    // Getting the name for the recipe and to be able to name the file
    cout << "what is the name of the recipe: ";
    getline(cin, name);
    string fileName = ExePath() + "\\" + name + ".txt";
    outputFile.open(fileName);
    // Verifying that the file is opened
    if (!outputFile) {
        cout << "Crumb!" << endl;
    }
    cin.sync();
    // Getting the number of ingredients and then getting the ingredients
    cout << "How many ingredients are there: ";
    cin >> numberOfIngredients;
    cin.ignore();
    for (int i = 0; i < numberOfIngredients; i++) {
        cout << "Ingredient: ";
        getline(cin, phrase);
        if (validatePhrase(phrase)) {
            getIngredients(phrase, recipe);
        }
        else {
            i--;
            cout << "[!] Please enter a number, unit of measurement and the ingredient, each separated by a space" << endl;
        }
    }
    // Getting the number of steps and then getting the steps
    int numberOfSteps;
    cout << "How many steps are there: ";
    cin >> numberOfSteps;
    cin.ignore();
    for (int i = 0; i < numberOfSteps; i++) {
        cout << "Step " << i + 1 << ": ";
        getline(cin, phrase);
        getSteps(phrase, steps, i + 1);
    }
    // Printing the results to the screen and to the file
    cout << endl << endl;
    cout << "\t" << name << endl;
    outputFile << endl << endl;
    outputFile << "\t" << name << endl;
    recipe.print_ingredient_list(outputFile);
    cout << endl;
    outputFile << endl;
    steps.print_step_list(outputFile);
    outputFile.close();
    return 0;
}
