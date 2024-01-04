/**********************************************************
 * Author: Eric Hansson
 * File: main.cpp
 * Date:
 * Purpose: 
***********************************************************/
#include <iostream>
#include <utility>

using namespace std;

#define VAR_X 'X'
#define VAR_O 'O'

#define GRIDSIZE 3

string grid[GRIDSIZE][GRIDSIZE];

// i is row, j is column
void initGrid(){
    for (int i=0; i < GRIDSIZE; i++){
        for (int j=0; j < GRIDSIZE; j++) {
            grid[i][j] = ' ';
        }
    }
}

void printBorder(){
    cout << "+";
    for (int i=0; i < GRIDSIZE; i++) {
        cout << "-+";
    }
    cout << endl;
}
// Use a 2D array for the grid
void printGrid(){
    printBorder();
    for (int i=0; i < GRIDSIZE; i++){
        cout << "|";
        for (int j=0; j < GRIDSIZE; j++) {
            cout << grid[i][j] << "|";
        }
        cout << endl;
        printBorder();
    }
}

int main(int argc, char *argv[]){
    
    initGrid();
    printGrid();
    return 0;
}
