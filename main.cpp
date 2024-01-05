/**********************************************************
 * Author: Eric Hansson
 * File: main.cpp
 * Date:
 * Purpose: Create a tic-tac-toe game 3x3 grid from scratch
 * with C++
***********************************************************/
#include <iostream>
#include <utility>

using namespace std;

// Variable for X and O
#define VAR_X 'X'
#define VAR_O 'O'

// Size of the grid
#define GRIDSIZE 3

// Declare the grid
string grid[GRIDSIZE][GRIDSIZE];

// i is row, j is column
void initGrid(){
    for (int i=0; i < GRIDSIZE; i++){
        for (int j=0; j < GRIDSIZE; j++) {
            grid[i][j] = ' ';
        }
    }
}

// Dealing with priting border to the grid
void printBorder(){
    cout << " +";
    for (int i=0; i < GRIDSIZE; i++) {
        cout << "-+";
    }
    cout << endl;
}
// Uses a 2D array for the grid
void printGrid(){
    cout << "  0" << " 1" << " 2" << endl;
    printBorder();
    for (int i=0; i < GRIDSIZE; i++){
        cout << i  << "|";
        for (int j=0; j < GRIDSIZE; j++) {
            cout << grid[i][j] << "|";
        }
        cout << endl;
        printBorder();
    }
}

// Player picking status
bool playerStatus = false;

// bool variable to keep track if the game is over or not
// false = not over
bool gameStatus = false;

// player 1 is X, player 2 is O

int main(int argc, char *argv[]){
    // Variables for players
    string playerNum;
    string playerOne;
    string playerTwo;

    // Game prompt
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << endl;
    
    while (!playerStatus) {
        cout << "Select Player 1 or Player 2: ";
        cin >> playerNum;
        if(playerNum == "1"){
           cout << "Player 1 please enter in your name: ";
           cin >> playerOne;
           cout << "Player 2 please enter in your name: ";
           cin >> playerTwo;
           playerStatus = true;
        }
        else if(playerNum == "2") {
           cout << "Player 2 please enter in your name: ";
           cin >> playerTwo;
           cout << "Player 1 please enter in your name: ";
           cin >> playerOne;
           playerStatus = true;
        }
        else {
            cout << "You have entered a invalid property! Please try again." << endl;
        }
    }

    // Initialize grid
    initGrid();

    while (!gameStatus) { 
    }



    return 0;
}
