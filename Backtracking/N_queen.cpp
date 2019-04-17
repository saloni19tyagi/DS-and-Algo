//Author : Saloni Tyagi
//Problem Statement : Given a chess board having  cells, you need to place N queens on the board in such a way that no queen attacks any other queen.
//Pre-requisite : BackTracking

#include <iostream>

using namespace std;

bool is_filled(int x, int y, bool board[][12], int n){
    for (int i = 0; i < n; i++){
        if (board[x][i] == 1)    // Checking for row
            return 1;
    }
    for (int i = 0; i < n; i++){
        if (board[i][y] == 1)   //Checking for Columns
            return 1;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ((board[i][j] == 1) && ((i + j == x + y) || (i - j == x - y))) //Checking for diagonal
                return 1;
        }
    }
    return false;
}

bool queen(bool board[][12], int n, int level){
    if (level == 0) {
        return true; // ALL queens have been placed
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if (is_filled(i, j, board, n) == 1)
                continue;
            board[i][j] = 1;     // Place queen at (i, j)th Cell
            if (queen(board, n, level - 1) == true)
                return true;
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){

    int n, level;
    cin >> n;
    level = n;

    bool board[12][12], ans = 0;
    memset(board, 0, sizeof(board));

    ans = queen(board, n, level);
    if (ans == 0){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}