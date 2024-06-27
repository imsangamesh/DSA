#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  //! NUMERIC HALF PYRAMID
  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col <= row; col++) {
  //     cout << col + 1;
  //   }
  //   cout << endl;
  // }

  //! NUMERIC HOLLOW HALF PYRAMID
  //* 1
  //* 12
  //* 1 3
  //* 1  4
  //* 1   5
  //* 123456

  //* WHEN are we printing the stars?
  //* - col = 0
  //* - col == row
  //* - row == n - 1
  for (int row = 0; row < n; row++) {
    for (int col = 0; col <= row; col++) {
      if (col == 0 || col == row || row == n - 1) {
        cout << col + 1;
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}