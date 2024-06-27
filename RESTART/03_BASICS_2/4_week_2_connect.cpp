#include <iostream>
using namespace std;

int main() {
  //! PRINT DIGITS OF THE NUMBER
  // int n = 528;
  // while (n != 0) {
  //   int rem = n % 10;
  //   cout << rem << endl;
  //   n = n / 10;
  // }
  // cout << endl;

  // for (int n = 528; n != 0; n = n / 10) {
  //   cout << n % 10 << endl;
  // }

  //! COMBINING DIGITS TO FORM A NUMBER
  // int n;
  // cout << "Print the number of digits: ";
  // cin >> n;

  // int finalNumber = 0;
  // for (int i = 0; i < n; i++) {
  //   int digit;
  //   cout << "Print the " << i + 1 << " digit: ";
  //   cin >> digit;

  //   finalNumber = finalNumber * 10 + digit;
  // }

  // cout << "Your number is: " << finalNumber;

  //! 1:41 - FIND NUMBER OF SET BITS in a number
  int n;
  cin >> n;
  int count = 0;

  while (n != 0) {
    if (n & 1 == 1) {
      count++;
    }
    n = n >> 1;
  }

  cout << "SET BITS: " << count;
}