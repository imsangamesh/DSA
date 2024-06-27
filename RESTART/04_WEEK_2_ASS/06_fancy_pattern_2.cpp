#include <iostream>
using namespace std;

int main() {
  //! 1
  //! 2*3
  //! 4*5*6
  //! 7*8*9*10
  //! 7*8*9*10
  //! 4*5*6
  //! 2*3
  //! 1

  int n;
  cin >> n;

  int c = 1;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < row + 1; col++) {
      cout << c++;
      if (col < row) cout << "*";
    }
    cout << endl;
  }
  // cout << "C: " << c << endl;
  int start = c - n;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n - row; col++) {
      cout << start + col;
      if (col < n - 1 - row) cout << "*";
    }
    start = start - (n - row - 1);
    cout << endl;
  }
}