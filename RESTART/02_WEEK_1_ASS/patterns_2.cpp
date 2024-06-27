#include <iostream>
using namespace std;

int main() {
    //! HOLLOW INVERTED HALF PYRAMID
    // * * * * * *
    // *       *
    // *     *
    // *   *
    // * *
    // *
    int n;
    cin >> n;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n - row; col++) {
            if (row == 0 || col == 0 || row == n - 1 - col) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
