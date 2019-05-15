/***********************
Name: The Not-Gambler
Author: Zach Thompson
Version: 1.0 4/6/2019
Purpose: To attempt to predict the numbers drawn
Variables:
    randomNumber As Int
    maxball As Int
    ballsno As Int
    rnd As Int
    drawnBalls As Array
    i As int
    j As Int
    n As Int
************************/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

// My poor attempt to use a function
inline int drawBall(int max) {
    int randomNumber = rand() % max + 1;
    return randomNumber;
}


int main()
{
    // Declaring the variables and getting user input
    int maxball;
    int ballsno;
    int rnd;
    cout << "Max ball number? ";
    cin >> maxball;
    cout << "How many balls? ";
    cin >> ballsno;
    srand(time(NULL));

    int drawnBalls[ballsno] = { };

    // Looping through everything to get the correct number of items
    for (int j = 0; j < ballsno; j++) {
        bool found = true;
        // Testing to sure the number has not already been added
        while (found) {
            rnd = drawBall(maxball);
            for (int i = 0; i < ballsno; i++) {
                if (drawnBalls[i] != rnd) {
                    found = false;
                }
                else {
                    found = true;
                    break;
                }
            }
        }
        drawnBalls[j] = rnd;
    }

    // Printing results
    for (int n = 0; n < ballsno; n++) {
        cout << n + 1 << ") " << drawnBalls[n] << endl;
    }
    return 0;
}
