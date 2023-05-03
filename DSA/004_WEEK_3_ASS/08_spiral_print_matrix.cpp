//*
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void spiralPrintMatrix() {
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    arr = {
        {1, 2, 3, 4, 5},      {6, 7, 8, 9, 10},     {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25},
    };
    arr = {
        {1, 2},
        {3, 4},
    };

    int rows = arr.size(), cols = arr[0].size();
    int n = rows * cols;

    int sr = 0, er = rows - 1;
    int sc = 0, ec = cols - 1;

    while (n) {
        //? starting row
        for (int col = sc; col <= ec && n; col++) {
            cout << arr[sr][col] << " ";
            n--;
        }

        //? ending column
        for (int row = sr + 1; row <= er && n; row++) {
            cout << arr[row][ec] << " ";
            n--;
        }

        //? ending row
        for (int col = ec - 1; col >= sc && n; col--) {
            cout << arr[er][col] << " ";
            n--;
        }

        //? starting col
        for (int row = er - 1; row >= sr + 1 && n; row--) {
            cout << arr[row][sc] << " ";
            n--;
        }

        sr++;
        sc++;
        er--;
        ec--;
    }
}

int main() {
    //
    spiralPrintMatrix();
}