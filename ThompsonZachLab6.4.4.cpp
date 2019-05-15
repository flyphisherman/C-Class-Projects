/***********************
Name: Tic-Tac-Toe
Author: Zach Thompson
Version: 1.0 4/27/2019
Purpose: To win
Variables:
    name As String
    piece As Int
    boardLoc As Int Array
    isThereWinner As Boolean
    winner As Int
    players As Player Object Array
    playerToMove As Int
    new_player As PLayer Object
    playerPiece As Int
    name1 As String
    name2 As String
    i As Int
    j As Int
    row As Int
    column As Int
    board As Board
************************/

#include <iostream>
#include <string>

using namespace std;

// This is my player class
class Player {
    public:
        Player(string name, int piece);
        string getName();
        int getPiece();
    private:
        string name;
        int piece;
};

// Setting up player
Player::Player(string name, int piece) {
    this->name = name;
    this->piece = piece;
}

// Returning player name
string Player::getName() {
    return this->name;
}

// Returning player piece
int Player::getPiece() {
    return this->piece;
}

// This is the board class
class Board {
    public:
        Board();
        bool placePiece(string phrase);
        bool checkWinner();
        void showBoard();
        void getPlayers();
        string getPlayerName();
        string getWinner();
    private:
        int boardLoc [3][3] = { };
        bool isThereWinner;
        int winner;
        Player* players[2];
        int playerToMove;
};

// This returns the player's name
string Board::getPlayerName() {
    return this->players[this->playerToMove]->getName();
}

// This returns the winner's name or that it is a draw
string Board::getWinner() {
    if (this->winner != -1) {
        return this->players[this->winner]->getName();
    }
    else {
        return "It is a draw!";
    }
}

// This sets up a new board object
Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->boardLoc[i][j] = -1;
        }
    }
    this->isThereWinner = false;
    this->playerToMove = 0;
    this->winner = -1;
};

// This gets the players that will be playing
void Board::getPlayers() {
    string name1 = "";
    string name2 = "";
    cout << "First Player Name: ";
    getline(cin, name1);
    cout << "Second Player Name: ";
    getline(cin, name2);
    Player* new_player = new Player(name1, 0);
    this->players[0] = new_player;
    Player* new_player2 = new Player(name2, 1);
    this->players[1] = new_player2;
}

// This is to put the piece into the array
bool Board::placePiece(string phrase) {
    int piece = players[this->playerToMove]->getPiece();
    string playerPiece = "";
    if (piece == 0) {
        playerPiece = "X";
    }
    else {
        playerPiece = "O";
    }
    string name = players[this->playerToMove]->getName();
    int row = phrase.at(0) - '0';
    int column = phrase.at(1) - '0';
    // Making sure the spot is open and in range
    if (boardLoc[row][column] == -1 && row <= 2 && row >= 0 && column <= 2 && column >= 0) {
        cout << name << " plays their " << playerPiece << " in position: " << phrase << endl;
        boardLoc[row][column] = piece;
        if (this->playerToMove == 0) {
            this->playerToMove++;
        }
        else {

        this->playerToMove--;
        }
        return true;
    }
    else {
        cout << "[!] That move is invalid! Please try again!" << endl;
        return false;
    }
}

// This is the long method to see if there is a winner
bool Board::checkWinner() {
    if (this->boardLoc[0][0] != -1 && this->boardLoc[0][0] == this->boardLoc[0][1] && this->boardLoc[0][0] == this->boardLoc[0][2]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[0][0];
    }
    else if (this->boardLoc[1][0] != -1 && this->boardLoc[1][0] == this->boardLoc[1][1] && this->boardLoc[1][0] == this->boardLoc[1][2]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[1][0];
    }
    else if (this->boardLoc[2][0] != -1 && this->boardLoc[2][0] == this->boardLoc[2][1] && this->boardLoc[2][0] == this->boardLoc[2][2]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[2][0];
    }
    else if (this->boardLoc[0][0] != -1 && this->boardLoc[0][0] == this->boardLoc[1][0] && this->boardLoc[0][0] == this->boardLoc[2][0]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[0][0];
    }
    else if (this->boardLoc[0][1] != -1 && this->boardLoc[0][1] == this->boardLoc[1][1] && this->boardLoc[0][1] == this->boardLoc[2][1]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[0][1];
    }
    else if (this->boardLoc[0][2] != -1 && this->boardLoc[0][2] == this->boardLoc[1][2] && this->boardLoc[0][2] == this->boardLoc[2][2]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[0][2];
    }
    else if (this->boardLoc[0][0] != -1 && this->boardLoc[0][0] == this->boardLoc[1][1] && this->boardLoc[0][0] == this->boardLoc[2][2]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[0][1];
    }
    else if (this->boardLoc[0][2] != -1 && this->boardLoc[0][2] == this->boardLoc[1][1] && this->boardLoc[0][2] == this->boardLoc[2][0]) {
        this->isThereWinner = true;
        this->winner = this->boardLoc[0][2];
    }
    else if (this->boardLoc[0][0] != -1 && this->boardLoc[0][1] != -1 && this->boardLoc[0][2] != -1 && this->boardLoc[1][0] != -1 && this->boardLoc[1][1] != -1 && this->boardLoc[1][2] != -1 && this->boardLoc[2][0] != -1 && this->boardLoc[2][1] != -1 && this->boardLoc[2][2] != -1) {
        this->isThereWinner = true;
        this->winner = -1;
    }
    return this->isThereWinner;
}

// This prints the board on the screen
void Board::showBoard() {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\t";
        for (int j = 0; j < 3; j++) {
            if (this->boardLoc[i][j] != -1) {
                if (this->boardLoc[i][j] == 0) {
                    cout << "  X ";
                }
                else {
                    cout << "  O ";
                }
            }
            else {
                cout << " " << i << j << " ";
            }
            if (j < 2) {
                cout << "|";
            }
        }
        if (i < 2) {
            cout << endl << "\t -- + -- + --" << endl;
        }
        else {
            cout << endl << endl;
        }
    }
}

// This is the main function
int main() {
    Board board;
    board.getPlayers();
    string playerMove = "";
    // We keep looping through until there is a winner
    while (!board.checkWinner()) {
        board.showBoard();
        cout << board.getPlayerName() << " what is your move: ";
        getline(cin, playerMove);
        board.placePiece(playerMove);
    }
    cout << "The winner is: " << board.getWinner() << endl;
    return 0;
}
