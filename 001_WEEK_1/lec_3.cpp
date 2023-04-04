#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // cout << "Enter the value of n: ";
    // cin >> n;

    //! ------------------------------ RECTANGLE
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j < n) {
    //         cout << "* ";
    //         j += 1;
    //     }

    //     cout << endl;
    //     i += 1;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *

    //! ------------------------------ HOLLOW RECTANGLE
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     if (i == 0 || i == n - 1) {
    //         int j = 0;
    //         while (j < n) {
    //             cout << "* ";
    //             j++;
    //         }
    //     } else {
    //         int j = 0;
    //         cout << "* ";
    //         while (j < n - 2) {
    //             cout << "  ";
    //             j++;
    //         }
    //         cout << "* ";
    //     }
    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     if (i == 0 || i == n - 1) {
    //         for (int j = 0; j < n; j++) {
    //             cout << "* ";
    //         }
    //         cout << endl;
    //     } else {
    //         cout << "* ";
    //         for (int j = 0; j < n - 2; j++) {
    //             cout << "  ";
    //         }
    //         cout << "* " << endl;
    //     }
    // }
    // * * * * *
    // *       *
    // *       *
    // *       *
    // * * * * *

    //! ------------------------------ HALF PYRAMID
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j <= i) {
    //         cout << "* ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *

    //! ------------------------------ HALF PYRAMID - NOS
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j <= i) {
    //         cout << j + 1 << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << j + 1 << " ";
    //     }
    //     cout << endl;
    // }
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5

    //! ------------------------------ HALF PYRAMID - REV
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j < n - i) {
    //         cout << "* ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n - i; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *

    //! ------------------------------ HALF PYR - INV - NOS
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j < n - i) {
    //         cout << j + 1 << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n - i; j++) {
    //         cout << j + 1 << " ";
    //     }
    //     cout << endl;
    // }
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1

    //! ------------------------------ FULL PYR
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j < n - 1 - i) {
    //         cout << "  ";
    //         j++;
    //     }

    //     j = 0;
    //     while (j <= i) {
    //         cout << " *  ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n - i - 1; j++) {
    //         cout << "  ";
    //     }
    //     for (int j = 0; j <= i; j++) {
    //         cout << " *  ";
    //     }
    //     cout << endl;
    // }
    //         *
    //       *   *
    //     *   *   *
    //   *   *   *   *
    // *   *   *   *   *

    //! ------------------------------ FULL PYR - INV
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j < i) {
    //         cout << "  ";
    //         j++;
    //     }

    //     j = 0;
    //     while (j < n - i) {
    //         cout << " *  ";
    //         j++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < i + 1; j++) {
    //         cout << "  ";
    //     }

    //     for (int j = 0; j < n - i; j++) {
    //         cout << " *  ";
    //     }
    //     cout << endl;
    // }
    // *   *   *   *   *
    //   *   *   *   *
    //     *   *   *
    //       *   *
    //         *

    //! ------------------------------ FULL PYR - NOS - 1
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j < n - 1 - i) {
    //         cout << "  ";
    //         j++;
    //     }

    //     j = 0;
    //     while (j <= i) {
    //         cout << j + 1 << " ";
    //         j++;
    //     }

    //     j = i;
    //     while (j > 0) {
    //         cout << j << " ";
    //         j--;
    //     }

    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int row = 0; row < n; row++) {
    //     for (int space = n - 1; space > row; space--) {
    //         cout << "  ";
    //     }

    //     for (int col = 0; col <= row; col++) {
    //         cout << col + 1 << " ";
    //     }

    //     for (int col = row; col > 0; col--) {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }
    //         1
    //       1 2 1
    //     1 2 3 2 1
    //   1 2 3 4 3 2 1
    // 1 2 3 4 5 4 3 2 1

    //! ------------------------------ FULL PYR - NOS - 2
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     int j = 0;
    //     while (j < n - 1 - i) {
    //         cout << "_ ";
    //         j++;
    //     }

    //     j = 0;
    //     int k = i + 1;
    //     while (j <= i) {
    //         cout << k++ << " ";
    //         j++;
    //     }

    //     k = k - 2;
    //     j = 0;
    //     while (j < i) {
    //         cout << k-- << " ";
    //         j++;
    //     }

    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         cout << "  ";
    //     }

    //     int k = i + 1;
    //     for (int j = 0; j < i + 1; j++) {
    //         cout << k++ << " ";
    //     }

    //     k -= 2;
    //     for (int j = 0; j < i; j++) {
    //         cout << k-- << " ";
    //     }

    //     cout << endl;
    // }
    //         1
    //       2 3 2
    //     3 4 5 4 3
    //   4 5 6 7 6 5 4
    // 5 6 7 8 9 8 7 6 5

    //! ------------------------------ HOLLOW PYR
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     //* printing space
    //     int j = 0;
    //     while (j < n - 1 - i) {
    //         cout << " ";
    //         j++;
    //     }

    //     if (i == n - 1) {  //* for last row
    //         j = 0;
    //         while (j < n) {
    //             cout << j + 1 << " ";
    //             j++;
    //         }
    //     } else {  //* for other rows
    //         cout << 1;

    //         j = 0;
    //         while (j < (2 * (i - 1)) + 1) {
    //             cout << " ";
    //             j++;
    //         }

    //         if (i != 0) cout << i + 1;  //* printing last digits except 1st
    //         row
    //     }

    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         cout << "_";
    //     }

    //     if (i == n - 1) {
    //         for (int j = 0; j < n; j++) {
    //             cout << j + 1 << " ";
    //         }
    //     } else {
    //         cout << 1;

    //         for (int j = 0; j < (2 * (i - 1) + 1); j++) {
    //             cout << "_";
    //         }
    //     }
    //     cout << endl;
    // }
}
