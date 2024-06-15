#include <iostream>
using namespace std;

int main() {
    //! HOLLOW INVERTED HALF PYRAMID
    int n;
    cin >> n;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n - row; col++) {
            if (row == 0 || row == n - 1) {
                cout << "* ";
            } else {
                cout << "* ";
                for (int i = 0; i < n - row - 2; i++) {
                    cout << "  ";
                }
                cout << '*';
            }
        }
        cout << endl;
    }
}