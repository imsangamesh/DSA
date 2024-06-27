#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  //! 7
  //! 1
  //! 1 1
  //! 1 2 1
  //! 1 3 3 1
  //! 1 4 6 4 1
  //! 1 5 10 10 5 1
  //! 1 6 15 20 15 6 1

  for (int row = 1; row <= n; row++) {
    int c = 1;
    for (int col = 1; col <= row; col++) {
      cout << c << ' ';
      c = c * (row - col) / col;
    }
    cout << endl;
  }
}