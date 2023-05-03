#include <iostream>
using namespace std;
#include <vector>

bool findElement(int arr[][3], int row, int col, int key) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == key) return true;
        }
    }
    return false;
}

void print2DArray(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int findMax(int arr[][3], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}

int findMin(int arr[][3], int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min) min = arr[i][j];
        }
    }
    return min;
}

void createTranspose(int arr[][3], int rows, int cols, int trans[][3]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = arr[i][j];
        }
    }
}

void print2DVector(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int rows = 3, cols = 3;

    //! ------------------------------ LINEAR SEARCH
    // if (findElement(arr, 3, 3, 9)) {
    //     cout << "found" << endl;
    // } else {
    //     cout << "not found" << endl;
    // }

    //! ------------------------------ FIND MAX & MIN
    // cout << "Maximum is " << findMax(arr, 3, 3) << endl;
    // cout << "Minimum is " << findMin(arr, 3, 3) << endl;

    //! ------------------------------ TRANSPOSE
    // int trans[3][3];
    // createTranspose(arr, 3, 3, trans);
    // cout << "Transpose matrix is:" << endl;
    // print2DArray(trans, 3, 3);

    //! ------------------------------ 2D VECTOR PRINT
    // vector<vector<int>> newarr;
    // vector<int> brr = {1, 2, 3};
    // vector<int> crr = {4, 5, 6, 7, 8, 9};
    // vector<int> drr = {4, 50, 60, 70};

    // newarr.push_back(brr);
    // newarr.push_back(crr);
    // newarr.push_back(drr);

    // print2DVector(newarr);
}