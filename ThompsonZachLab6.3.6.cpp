/***********************
Name: Checkers Move Checker
Author: Zach Thompson
Version: 1.0 4/24/2019
Purpose: To check to see if a move is legal.
Variables:
    movement As String
    column As Int
    row As Int
    phrase As String
    piece As String
************************/

#include <iostream>
#include <string>
#include <locale>
#include <cmath>

using namespace std;

// This is the base piece class
class Piece {
    public:
        virtual bool movePiece(string movement);
};

// This is just the basic method
bool Piece::movePiece(string movement) {
    return true;
}

// This class is for the 'Man' piece
class Man: public Piece {
    public:
        bool movePiece(string movement);
    private:
        int column = 66;
        int row = 1;
};

// This class is for the 'King' piece
class King: public Piece {
    public:
        bool movePiece(string movement);
    private:
        int column = 66;
        int row = 1;
};

// This method is to check the movement for the 'Man' piece
bool Man::movePiece(string movement) {
    int column = toupper(movement[0]);
    int row = movement.at(1) - '0';
    // Basic check to see if it is within 1
    if (((column - 1) <= this->column && (column + 1) >= this->column) && ((row - 1) <= this->row && (row + 1) >= this->row)) {
        this->row = row;
        this->column = column;
        return true;
    }
    else {
        return false;
    }
}

// This method is to check the movement for the 'King' piece
bool King::movePiece(string movement) {
    int column = toupper(movement[0]);
    int row = movement.at(1) - '0';
    // This checks to make the movement is the same number of squares in both directions
    if (abs(column - this->column) == abs(row - this->row)) {
        this->row = row;
        this->column = column;
        return true;
    }
    else {
        return false;
    }
}

// This is just to normalize the string
string modifyString(string phrase) {
    for (int i = 0; i < phrase.length(); i++) {
        phrase[i] = tolower(phrase[i]);
    }
    phrase[0] = toupper(phrase[0]);
    return phrase;
}

int main()
{
    // Setting up my variables
    string piece = "", movement = "";
    bool goodMove = false;
    // Giving a sentinel option
    while (piece != "Quit") {
        cout << "What piece would you like to play (King/Man): ";
        getline(cin,piece);
        piece = modifyString(piece);
        // Verifying that the correct string has been entered
        if (piece == "King" || piece == "Man") {
            cout << "The " << piece << " is at B1, where would you like to move: ";
            while (!goodMove) {
                getline(cin,movement);
                // Making sure that only valid places are entered
                if (movement.length() == 2) {
                    if ((tolower(movement[0]) >= 'a' && tolower(movement[0]) <= 'h') && (movement[1] >= '1' && movement[1] <= '8')) {
                        goodMove = true;
                        if (piece == "King") {
                            King king;
                            if (king.movePiece(movement)) {
                                cout << "true" << endl;
                                break;
                            }
                            else {
                                cout << "false" << endl;
                                break;
                            }
                        }
                        else if (piece == "Man") {
                            Man man;
                            if (man.movePiece(movement)) {
                                cout << "true" << endl;
                                break;
                            }
                            else {
                                cout << "false" << endl;
                                break;
                            }
                        }
                    }
                    else {
                        cout << "[!] That is not a valid move!" << endl;
                    }
                }
            }
            break;
        }
        else if (piece == "Quit") {

        }
        else {
            cout << "[!] Please try again! (To quit, enter 'quit')" << endl;
        }
    }
    return 0;
}
