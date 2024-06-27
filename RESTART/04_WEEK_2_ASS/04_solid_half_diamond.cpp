#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  //! SOLID HALF DIAMOND
  //* 6
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  // *****
  // ****
  // ***
  // **
  // *

  for (int row = 0; row < 2 * n - 1; row++) {
    if (row < n) {  //* growing phase
      for (int col = 0; col <= row; col++) {
        cout << '*';
      }
    } else {  //* shrinking phase
      for (int col = 0; col < 2 * n - 1 - row; col++) {
        cout << '*';
      }
    }
    cout << endl;
  }
}