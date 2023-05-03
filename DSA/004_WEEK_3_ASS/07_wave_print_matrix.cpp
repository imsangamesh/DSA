//*
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void wavePrintMatrix() {
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    int rows = arr.size(), cols = arr[0].size();

    for (int col = 0; col < cols; col++) {
        if (col % 2 == 0) {
            for (int row = 0; row < rows; row++) {
                cout << arr[row][col] << " ";
            }
        } else {
            for (int row = rows - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main() {
    //
    wavePrintMatrix();
}