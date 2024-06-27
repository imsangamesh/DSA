#include <iostream>
using namespace std;

int main() {
  //! 9
  //! *
  //! *1*
  //! *121*
  //! *12321*
  //! *1234321*
  //! *123454321*
  //! *1234321*
  //! *12321*
  //! *121*
  //! *1*
  //! *

  int n;
  cin >> n;

  cout << '*' << endl;
  for (int row = 0; row < n; row++) {
    int cond = row <= n / 2 ? 2 * row : 2 * (n - row - 1);
    cout << '*';
    for (int col = 0; col <= cond; col++) {
      if (col <= cond / 2) {
        cout << col + 1;
      } else {
        cout << cond - col + 1;
        ;
      }
    }
    cout << '*';
    cout << endl;
  }
  cout << '*';
}