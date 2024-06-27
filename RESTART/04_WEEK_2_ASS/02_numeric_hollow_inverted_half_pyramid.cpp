#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  //! NUMERIC INVERTED HALF PYRAMID
  //* 123456
  //* 2   6
  //* 3  6
  //* 4 6
  //* 56
  //* 6

  //* MINE
  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n - row; col++) {
  //     if (col == 0 || row == 0 || row + col == 4) {
  //       cout << col + row + 1;
  //     } else {
  //       cout << " ";
  //     }
  //   }
  //   cout << endl;
  // }

  //! NUMERIC INVERTED HALF PYRAMID
  //* BETTER
  for (int row = 0; row < n; row++) {
    for (int col = row + 1; col <= n; col++) {
      if (col == row + 1 || row == 0 || col == n) {
        cout << col;
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}