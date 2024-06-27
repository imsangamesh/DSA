#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  //! NUMERIC INVERTED HALF PYRAMID
  //*        1
  //*       121
  //*      12321
  //*     1234321
  //*    123454321
  //*   12345654321
  //*  1234567654321
  for (int row = 0; row < n; row++) {
    // spaces
    for (int col = 0; col < n - row; col++) {
      cout << " ";
    }
    // first triangle
    for (int col = 0; col < row + 1; col++) {
      cout << col + 1;
    }
    // second triangle
    for (int col = row; col > 0; col--) {
      cout << col;
    }
    cout << endl;
  }
}