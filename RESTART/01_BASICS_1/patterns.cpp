#include <iostream>
using namespace std;

int main() {
    //! HOLLOW RECTANGLE
    // * * * * *
    // *       *
    // *       *
    // *       *
    // * * * * *
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++) {
    //     if (row == 0 || row == n - 1) {
    //         for (int col = 0; col < n; col++) {
    //             cout << "* ";
    //         }
    //     } else {
    //         cout << "* ";
    //         for (int i = 0; i < n - 2; i++) {
    //             cout << "  ";
    //         }
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //! HALF PYRAMID
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col < row + 1; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //! INVERTED HALF PYRAMID
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    // int n;
    // cin >> n;

    // //? METHOD: 1
    // for (int row = n; row > 0; row--) {
    //     for (int col = 0; col < row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // //? METHOD: 2
    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col < n - row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //! NUMERIC HALF PYRAMID
    //* 1
    //* 1 2
    //* 1 2 3
    //* 1 2 3 4
    //* 1 2 3 4 5
    //* 1 2 3 4 5 6
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col <= row; col++) {
    //         cout << col + 1 << ' ';
    //     }
    //     cout << endl;
    // }

    //! INVERTED NUMERIC HALF PYRAMID
    //* 1 2 3 4 5 6
    //* 1 2 3 4 5
    //* 1 2 3 4
    //* 1 2 3
    //* 1 2
    //* 1
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col < n - row; col++) {
    //         cout << col + 1 << " ";
    //     }
    //     cout << endl;
    // }

    //! FULL PYRAMID
    //     *
    //    * *
    //   * * *
    //  * * * *
    // * * * * *
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++) {
    //     // spaces
    //     for (int col = 0; col < n - row - 1; col++) {
    //         cout << ' ';
    //     }
    //     // stars
    //     for (int col = 0; col <= row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //! INVERTED FULL PYRAMID
    // * * * * * *
    //  * * * * *
    //   * * * *
    //    * * *
    //     * *
    //      *
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++) {
    //     // spaces
    //     for (int col = 0; col < row; col++) {
    //         cout << ' ';
    //     }
    //     // stars
    //     for (int col = 0; col < n - row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //! NUMERIC FULL PYRAMID
    int n;
    cin >> n;

    for (int row = 0; row < n; row++) {
        // spaces
        for (int col = 0; col < n - row; col++) {
            cout << "  ";
        }
        // first half pyramid
        for (int col = 0; col <= row; col++) {
            cout << row + 1 + col << ' ';
        }
        // remaining second half pyramid
        for (int col = 0; col < row; col++) {
            cout << row + 1 + col << ' ';
        }
        cout << endl;
    }
}
