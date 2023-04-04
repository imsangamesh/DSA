#include <iostream>
using namespace std;

int main() {
    int n = 5;

    //! ------------------------------ HOLLOW HALF PYR - INV
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     if (i == 0 || i == n - 1) {
    //         int j = 0;
    //         while (j < n - i) {
    //             cout << "* ";
    //             j++;
    //         }
    //     } else {
    //         cout << "* ";

    //         int j = 0;
    //         while (j < n - 2 - i) {
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
    //         for (int j = 0; j < n - i; j++) {
    //             cout << "* ";
    //         }
    //     } else {
    //         cout << "* ";

    //         for (int j = 0; j < n - 2 - i; j++) {
    //             cout << "  ";
    //         }

    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // * * * * *
    // *     *
    // *   *
    // * *
    // *

    //! ------------------------------ HOLLOW FULL PYR - INV
    // //? using while
    // int i = 0;
    // while (i < n) {
    //     if (i == n - 1) {
    //         int j = 0;
    //         while (j < n) {
    //             cout << "* ";
    //             j++;
    //         }
    //     } else {
    //         int j = 0;
    //         while (j < n - 1 - i) {
    //             cout << " ";
    //             j++;
    //         }

    //         cout << "*";

    //         j = 0;
    //         while (j < (2 * (i - 1) + 1)) {
    //             cout << " ";
    //             j++;
    //         }

    //         if (i != 0) cout << "* ";
    //     }

    //     cout << endl;
    //     i++;
    // }

    // //? using for
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         cout << " ";
    //     }

    //     if (i == n - 1) {
    //         for (int j = 0; j < n; j++) {
    //             cout << "* ";
    //         }
    //     } else {
    //         cout << "*";

    //         for (int j = 0; j < (2 * (i - 1) + 1); j++) {
    //             cout << " ";
    //         }

    //         if (i != 0) cout << "* ";
    //     }

    //     cout << endl;
    // }

    //     *
    //    * *
    //   *   *
    //  *     *
    // * * * * *
}
