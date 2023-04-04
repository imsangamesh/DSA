#include <iostream>
#include <vector>
using namespace std;

int findSqrt(int target) {
    int s = 0, e = target;
    int ans = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;
        int sq = m * m;

        if (sq == target) {
            return m;
        } else if (sq > target) {
            e = m - 1;
        } else {
            ans = m;
            s = m + 1;
        }
    }
    return ans;
}

bool findIndexOf2D(int arr[][4], int rows, int cols, int target) {
    int s = 0, e = rows * cols - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        int ri = mid / cols;
        int ci = mid % cols;

        if (arr[ri][ci] == target) {
            cout << "Found at: " << ri << " " << ci << endl;
            return true;
        } else if (arr[ri][ci] < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return false;
}

int main() {
    //! ------------------------------ SQUARE ROOT
    // int n = 10;
    // int precision = 11;

    // int ans = findSqrt(n);
    // cout << "Rough ans is: " << ans << endl;

    // double step = 0.1;
    // double finalAns = ans;

    // for (double i = 0; i < precision; i++) {
    //     for (double j = finalAns; j * j <= n; j = j + step) {
    //         finalAns = j;
    //     }
    //     step /= 10;
    // }
    // cout << "Final ans is: " << finalAns << endl;

    //! ------------------------------ FIND INDEXs in 2D
    // int arr[5][4] = {
    //     {1, 2, 3, 4},     {5, 6, 7, 8},     {9, 10, 11, 12},
    //     {13, 14, 15, 16}, {17, 18, 19, 20},
    // };

    // int rows = 5, cols = 4;
    // int target = 19;

    // bool ans = findIndexOf2D(arr, rows, cols, target);
    // if (ans) {
    //     cout << "Found" << endl;
    // } else {
    //     cout << "Not found" << endl;
    // }
}