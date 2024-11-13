#include <iostream>

#define X 'X'
#define O 'O'
#define SIZE 3

using namespace std;

void print_boder(char game_board[SIZE][SIZE]){
    cout << " +";
    for(int i=0; i < SIZE; i++){
        cout << "-+";
    }
    cout << endl;
}

void print_board(char game_board[SIZE][SIZE]){
    cout << "  0 1 2" << endl;
    print_boder(game_board);
    for(int i=0; i < SIZE; i++){
        cout << i << "|";
        for(int j=0; j < SIZE; j++){
            cout << game_board[i][j];
            cout << "|";
        }
        cout << endl;
        print_boder(game_board);
    }
}

bool check_space(char game_board[SIZE][SIZE], int row, int col){
    if(game_board[row][col] != ' '){
        return false;
    }

    return true;
}

bool check_win(char game_board[SIZE][SIZE]){
    if ((game_board[0][0] == X && game_board[1][1] == X && game_board[2][2] == X) 
        ||(game_board[0][0] == O && game_board[1][1] == O && game_board[2][2] == O)){

        return  true; 
    }

    for(int row=0; row < SIZE; row++){
        int count_X_row = 0;
        int count_O_row = 0;

        for(int col=0; col < SIZE; col++){
            if (game_board[row][col] == X) {
                count_X_row++;
            }
            else if (game_board[row][col] == O) {
                count_O_row++; 
            }

            if (count_X_row == 3 || count_O_row == 3) {
                return true; 
                break;
            }
        }

    }

    for(int col=0; col < SIZE; col++){
        int count_X_col = 0;
        int count_O_col = 0;
        for(int row=0; row < SIZE; row++){
            if (game_board[row][col] == X) {
                count_X_col++;
            }
            else if (game_board[row][col] == O) {
                count_O_col++; 
            }

            if (count_X_col == 3 || count_O_col == 3) {
                return true; 
                break;
            }
        }
    }

    return false;
}


int main(int argc, char* argv[]){
    int moves_total = SIZE*SIZE;

    cout << "######################" << endl;
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "X's starts first" << endl;
    cout << "######################" << endl;
    cout << endl;
    
    bool player1 = true;
    bool player2 = false;


    char board[SIZE][SIZE];

    // Initialize board
    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            board[i][j] = ' ';
        }
    }


    while (moves_total != 0) {
        int row, col;
        print_board(board);
        if (player1 == true && player2 == false) {
            cout << "Player X's turn (row, col)" << endl;
            cout << "Enter board cordinatet: ";
            cin >> row >> col;


            while (!check_space(board, row, col)) {
                cerr << "Can't do that move! Space is filled. Try again."  << endl;
                cout << "Enter board cordinates" << endl;
                cin >> row >> col;

                check_space(board, row, col);
            }

            board[row][col] = X;

            if(check_win(board)){
                cout << "X's WINS!!!!" << endl;
                return 0;
            }

            player1 = false;
            player2 = true;

            moves_total--;

        }
        else{
            cout << "Player O's turn (row, col)" << endl;
            cout << "Enter board cordinates: ";
            cin >> row >> col;

           while (!check_space(board, row, col)) {
                cerr << "Can't do that move! Space is filled. Try again."  << endl;
                cout << "Enter board cordinates" << endl;
                cin >> row >> col;

                check_space(board, row, col);
            }

            board[row][col] = O;

            if(check_win(board)){
                cout << "O's WINS!!!!" << endl;
                return 0;
            }

            player1 = true;
            player2 = false;

            moves_total--;
        }
    }
     
    return 0;
}
