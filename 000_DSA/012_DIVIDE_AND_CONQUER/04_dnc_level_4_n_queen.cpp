//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//* -------------------------------------------
//! /////// /////// /////// /////// /////// /////// ///////  N QUEEN

void printSolution(vector<vector<char>> board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

bool isSafe(int row, int col, vector<vector<char>> board, int n) {
    // can I place queen in the this current_cell
    //* you only need to check 3 left_directions only, cuz
    //* there won't be any QUEENS placed on the right.
    //
    //* 1. upper_left diagonal
    //* 2. left_side row
    //* 2. bottom_left diagonal
    int i = row, j = col;

    //? check ROW
    while (j >= 0) {
        if (board[i][j--] == 'Q') return false;
    }

    //? check UPPER_LEFT diagonal
    i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') return false;
        i--;
        j--;
    }

    //? check UPPER_LEFT diagonal
    i = row, j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == 'Q') return false;
        i++;
        j--;
    }

    // no queen found
    return true;
}

void solve(vector<vector<char>> board, int col, int n) {
    //? base case
    if (col >= n) {
        printSolution(board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            //? solve 1 case
            board[row][col] = 'Q';  // placed queen

            //? recursion
            solve(board, col + 1, n);

            //? backtracking
            // removing placed queen, cuz we now know that, that_place was
            // invalid
            board[row][col] = '-';
        }
    }
}

//* /////// /////// /////// /////// /////// /////// optimised 'ISSAFE' method
unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftCheck;
unordered_map<int, bool> bottomLeftCheck;

bool isSafeOptimised(int row, int col, vector<vector<char>> board, int n) {
    //
    if (rowCheck[row] == true) return false;
    if (upperLeftCheck[n - 1 + col - row] == true) return false;
    if (bottomLeftCheck[row + col] == true) return false;

    return true;
}

void solveOptimised(vector<vector<char>> board, int col, int n) {
    //? base case
    if (col >= n) {
        printSolution(board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            //? solve 1 case
            board[row][col] = 'Q';  // placed queen

            rowCheck[row] = true;
            upperLeftCheck[n - 1 + col - row] = true;
            bottomLeftCheck[row + col] = true;

            //? recursion
            solve(board, col + 1, n);

            //? backtracking
            // removing placed queen, cuz we now know that, that_place was
            // invalid
            board[row][col] = '-';

            rowCheck[row] = false;
            upperLeftCheck[n - 1 + col - row] = false;
            bottomLeftCheck[row + col] = false;
        }
    }
}

//* /////// /////// /////// /////// /////// /////// /////// /////// ///////
//? /////// /////// /////// /////// /////// /////// /////// /////// ///////
//! /////// /////// /////// /////// /////// /////// /////// /////// ///////

int main() {
    cout << endl;
    //
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;

    // solve(board, col, n);
    solveOptimised(board, col, n);

    cout << endl << endl;
}