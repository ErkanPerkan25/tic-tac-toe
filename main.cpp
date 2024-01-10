/**********************************************************
 * Author: Eric Hansson
 * File: main.cpp
 * Date:
 * Purpose: Create a tic-tac-toe game 3x3 grid from scratch
 * with C++
***********************************************************/
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

// Variable for X and O
#define VAR_X 'X'
#define VAR_O 'O'

// Size of the grid
#define GRIDSIZE 3
// Total of moves that can be taken
int totalMoves = GRIDSIZE*GRIDSIZE;

// Declare the grid
char grid[GRIDSIZE][GRIDSIZE];

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

// function to check if there is a row of either X or O
bool checkRow(char grid[][GRIDSIZE]){
    for (int i=0; i < GRIDSIZE; i++) {
        // loop through each row, check if the row has all X or O
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return true; 
        }
    }
    return false;
}

// function to check columns
bool checkColumn(char grid[][GRIDSIZE]){
    for (int i=0; i < GRIDSIZE; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return  true; 
        } 
    }
    return false;
}

// function to check crossed
bool checkCross(char grid[][GRIDSIZE]){
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return true; 
    } 
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return true; 
    }
    return false;
}

// not sure about thids, but another function to check for a win
bool checkWin(char grid[][GRIDSIZE]){
    for (int i=0; i < GRIDSIZE; i++) {
         if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] || 
             grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return true; 
        }
    } 
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] ||
        grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return true; 
    }
    return false;
}

// fucntion to check if there is a row, column, or diagonal, game over
bool gameOver(char grid[][GRIDSIZE]){
    return (checkRow(grid) || checkCross(grid) || checkColumn(grid));
}

// function to declare the winner
void winnerPrompt(){
}

// function to prompt a draw
void drawPrompt(){
}

// player 1 is X, player 2 is O

int main(int argc, char *argv[]){
    // Variables for players
    string playerNum;
    string playerOne;
    string playerTwo;

    // Game prompt
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << endl;
    
    // Selection of player, and name input
    while (!playerStatus) {
        cout << "Select Player 1 (X) or Player 2 (O): ";
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
    //printGrid();
    cout << endl;

    int movesMade = 0;
    
     
    // The game
    while (gameOver(grid) == false || movesMade != totalMoves) { 
        int row, col;
        printGrid();
        cout << playerOne << " enter row and column (row, column): ";
        cin >> row;
        cin >> col;
        
        if (grid[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid output! Try again." << endl;
        }
    }

    return 0;
}
