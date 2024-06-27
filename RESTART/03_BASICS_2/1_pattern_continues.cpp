#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  //! SOLID DIAMOND

  //!     *
  //!    * *
  //!   * * *
  //!  * * * *
  //! * * * * *
  //! * * * * *
  //!  * * * *
  //!   * * *
  //!    * *
  //!     *

  //   for (int row = 0; row < n; row++) {
  //     // spaces
  //     for (int col = 0; col < n - 1 - row; col++) {
  //       cout << " ";
  //     }
  //     // stars
  //     for (int col = 0; col <= row; col++) {
  //       cout << "* ";
  //     }
  //     cout << endl;
  //   }
  //   for (int row = 0; row < n; row++) {
  //     // spaces
  //     for (int col = 0; col < row; col++) {
  //       cout << " ";
  //     }
  //     // stars
  //     for (int col = 0; col < n - row; col++) {
  //       cout << "* ";
  //     }
  //     cout << endl;
  //   }

  //! HOLLOW DIAMOND

  //!     *
  //!    * *
  //!   *   *
  //!  *     *
  //! *       *
  //! *       *
  //!  *     *
  //!   *   *
  //!    * *
  //!     *

  //   for (int row = 0; row < n; row++) {
  //     // spaces
  //     for (int col = 0; col < n - 1 - row; col++) {
  //       cout << " ";
  //     }
  //     // characters (stars + spaces)
  //     for (int col = 0; col < 2 * row + 1; col++) {
  //       if (col == 0 || col == 2 * row) {
  //         cout << "*";
  //       } else {
  //         cout << ' ';
  //       }
  //     }
  //     cout << endl;
  //   }

  //   for (int row = 0; row < n; row++) {
  //     // spaces
  //     for (int col = 0; col < row; col++) {
  //       cout << ' ';
  //     }
  //     // characters (stars + spaces)
  //     for (int col = 0; col < 2 * (n - row) - 1; col++) {
  //       if (col == 0 || col == 2 * (n - row) - 2) {
  //         cout << '*';
  //       } else {
  //         cout << ' ';
  //       }
  //     }
  //     cout << endl;
  //   }

  //! FLIPPED SOLID DIAMOND

  //! ****** ******
  //! *****   *****
  //! ****     ****
  //! ***       ***
  //! **         **
  //! *           *
  //! *           *
  //! **         **
  //! ***       ***
  //! ****     ****
  //! *****   *****
  //! ****** ******

  //   for (int row = 0; row < n; row++) {
  //     // stars
  //     for (int col = 0; col < n - row; col++) {
  //       cout << "*";
  //     }
  //     // spaces
  //     for (int col = 0; col < 2 * row + 1; col++) {
  //       cout << " ";
  //     }
  //     // stars
  //     for (int col = 0; col < n - row; col++) {
  //       cout << '*';
  //     }
  //     cout << endl;
  //   }
  //   for (int row = 0; row < n; row++) {
  //     // stars
  //     for (int col = 0; col < row + 1; col++) {
  //       cout << '*';
  //     }
  //     // spaces
  //     for (int col = 0; col < 2 * n - 2 * row - 1; col++) {
  //       cout << " ";
  //     }
  //     // stars
  //     for (int col = 0; col < row + 1; col++) {
  //       cout << '*';
  //     }
  //     cout << endl;
  //   }

  //! FANCY PATTERN

  //! 1
  //! 2*2
  //! 3*3*3
  //! 4*4*4*4
  //! 5*5*5*5*5
  //! 5*5*5*5*5
  //! 4*4*4*4
  //! 3*3*3
  //! 2*2
  //! 1

  //   for (int row = 0; row < n; row++) {
  //     for (int col = 0; col < row + 1; col++) {
  //       cout << row + 1;
  //       if (col != row) cout << '*';
  //     }
  //     cout << endl;
  //   }
  //   for (int row = 0; row < n; row++) {
  //     for (int col = 0; col < n - row; col++) {
  //       cout << n - row;
  //       if (col != n - row - 1) cout << '*';
  //     }
  //     cout << endl;
  //   }

  //! ALPHABET PALINDROME PYRAMID

  //! A
  //! ABA
  //! ABCBA
  //! ABCDCBA
  //! ABCDEDCBA

  //* First solve the inner half triangle
  //* And then move to add the rest of 'reversed' alphabets

  //! A
  //! AB         A
  //! ABC    +   BA
  //! ABCD       CBA
  //! ABCDE      DCBA

  //   for (int row = 0; row < n; row++) {
  //     int col;
  //     // printing first half triangle
  //     for (col = 0; col < row + 1; col++) {
  //       char ch = (col + 1) + 'A' - 1;
  //       cout << ch;
  //     }
  //     col = col - 1;
  //     // reverse printing
  //     for (; col > 0; col--) {
  //       char ch = col + 'A' - 1;
  //       cout << ch;
  //     }
  //     cout << endl;
  //   }

  //! NUMERIC HOLLOW HALF PYRAMID

  //! 1
  //! 1 2
  //! 1   3
  //! 1     4
  //! 1 2 3 4 5

  //   for (int row = 0; row < n; row++) {
  //     for (int col = 0; col < row + 1; col++) {
  //       if (row == n - 1 || col == 0 || col == row) {
  //         cout << col + 1 << ' ';
  //       } else {
  //         cout << "  ";
  //       }
  //     }
  //     cout << endl;
  //   }

  //! NUMERIC PALINDROME EQUILATERAL PYRAMID

  //!         1
  //!       1 2 1
  //!     1 2 3 2 1
  //!   1 2 3 4 3 2 1
  //! 1 2 3 4 5 4 3 2 1

  //   for (int row = 0; row < n; row++) {
  //     // spaces
  //     for (int col = 0; col < n - 1 - row; col++) {
  //       cout << "  ";
  //     }
  //     // stars
  //     int col;
  //     for (col = 0; col < row + 1; col++) {
  //       cout << col + 1 << ' ';
  //     }
  //     col = col - 1;
  //     for (; col > 0; col--) {
  //       cout << col << ' ';
  //     }
  //     cout << endl;
  //   }
}