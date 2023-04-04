#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // cout << "Enter the value of n: ";
    // cin >> n;

    //! ------------------------------ DIAMOND PYR
    // //? using for
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j <= i; j++) {
    //         cout << "* ";
    //     }

    //     cout << endl;
    // }
    // for (int i = n - 1; i >= 0; i--) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j <= i; j++) {
    //         cout << "* ";
    //     }

    //     cout << endl;
    // }
    //     *
    //    * *
    //   * * *
    //  * * * *
    // * * * * *
    //  * * * *
    //   * * *
    //    * *
    //     *

    //! ------------------------------ HOLLOW DIAMOND PYR
    //? using for
    //* here we're considering the total length of each row which will be:
    //* 1, 3, 5, 7, 9.... which are odd
    //* and then we're just check if it is last or first character

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n - i - 1; j++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j < 2 * i + 1; j++) {
    //         if (j == 0 || j == 2 * i) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //     }

    //     cout << endl;
    // }
    // for (int i = n - 1; i >= 0; i--) {
    //     for (int j = 0; j < n - i - 1; j++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j < 2 * i + 1; j++) {
    //         if (j == 0 || j == 2 * i) {
    //             cout << "*";
    //         } else {
    //             cout << " ";
    //         }
    //     }

    //     cout << endl;
    // }
    //     *
    //    * *
    //   *   *
    //  *     *
    // *       *
    // *       *
    //  *     *
    //   *   *
    //    * *
    //     *

    //! ------------------------------ FULL PYR - NUMS
    // int row = 0;
    // while (row < n) {
    //     int col = 0;
    //     while (col < n - 1 - row) {
    //         cout << " ";
    //         col++;
    //     }

    //     //* first method
    //     col = 0;
    //     while (col <= row) {
    //         cout << col + 1 + row;
    //         col++;
    //     }

    //     col = 0;
    //     while (col < row) {
    //         cout << 2 * row - col;
    //         col++;
    //     }

    //     //* second method
    //     col = 0;
    //     int k = 1 + row;
    //     while (col <= row) {
    //         cout << k;
    //         col++;
    //         k++;
    //     }

    //     k -= 2;
    //     col = 0;
    //     while (col < row) {
    //         cout << k;
    //         k--;
    //         col++;
    //     }

    //     cout << endl;
    //     row++;
    // }
}