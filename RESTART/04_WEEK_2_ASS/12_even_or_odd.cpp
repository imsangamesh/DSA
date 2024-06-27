#include <iostream>
using namespace std;

bool isEven(int n) { return n % 2 == 0; }

bool isEvenByBitwise(int n) {
  //* Least Significant Bit (LSB) is 0 for even &
  //* Least Significant Bit (LSB) is 1 for odd
  if ((n & 1) == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n;
  cin >> n;

  if (isEven(n)) {
    cout << "Number is Even!" << endl;
  } else {
    cout << "Number is Odd!" << endl;
  }

  if (isEvenByBitwise(n)) {
    cout << "Number is Even!" << endl;
  } else {
    cout << "Number is Odd!" << endl;
  }
}