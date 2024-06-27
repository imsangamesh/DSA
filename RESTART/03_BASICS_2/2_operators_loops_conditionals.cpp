#include <iostream>
using namespace std;

int main() {
  // int n;
  // cin >> n;

  //! NUMERIC FULL PYRAMID

  //!         1
  //!       2 3 2
  //!     3 4 5 4 3
  //!   4 5 6 7 6 5 4
  //! 5 6 7 8 9 8 7 6 5

  // for (int row = 0; row < n; row++) {
  //   // Spaces
  //   for (int col = 0; col < n - 1 - row; col++) {
  //     cout << "  ";
  //   }
  //   // 1st numbers triange
  //   for (int col = 0; col < row + 1; col++) {
  //     cout << row + 1 + col << " ";
  //   }
  //   // 2nd numbers triangle
  //   for (int col = 0; col < row; col++) {
  //     cout << 2 * row - col << " ";
  //   }
  //   cout << endl;
  // }

  //! NUMERIC HOLLOW PYRAMID

  //!     1
  //!    1 2
  //!   1   3
  //!  1     4
  //! 1 2 3 4 5

  // for (int row = 0; row < n; row++) {
  //   // Spaces
  //   for (int col = 0; col < n - 1 - row; col++) {
  //     cout << ' ';
  //   }
  //   // Hollow pyramid
  //   if (row == n - 1) {
  //     for (int col = 0; col < n; col++) {
  //       cout << col + 1 << ' ';
  //     }
  //   } else {
  //     for (int col = 0; col < 2 * row + 1; col++) {
  //       if (col == 0) {
  //         cout << 1;
  //       } else if (col == 2 * row) {
  //         cout << row + 1;
  //       } else {
  //         cout << ' ';
  //       }
  //     }
  //   }
  //   cout << endl;
  // }

  //! AND - OR - XOR - NEGATION
  //   &    |     ^       ~

  //! LEFT SHIFT & RIGHT SHIFT
  // << : Left shift doubles the value
  // >> : Right shift halves the value

  int a = 12;
  cout << (a >> 1) << endl;  // right shift
  cout << (a << 1) << endl;  // left shift

  a = 5;
  cout << (++a) * (++a);
}

// 1:16