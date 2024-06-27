#include <math.h>

#include <iostream>
using namespace std;

int decimalToBinary(int n) {
  int binaryNo = 0;
  int i = 0;

  while (n != 0) {
    int bit = n & 1;
    binaryNo = bit * pow(10, i++) + binaryNo;
    n = n >> 1;
  }
  return binaryNo;
}

int binaryToDecimal(int n) {
  int decimal = 0;
  int i = 0;

  while (n != 0) {
    int digit = n % 10;
    decimal += digit * pow(2, i++);
    n = n / 10;
  }

  return decimal;
}

int main() {
  //! DECIMAL to BINARY
  // int n;
  // cin >> n;
  // cout << "Binary no is: " << decimalToBinary(n);

  //! BINARY to DECMIAL
  int binaryNo;
  cin >> binaryNo;
  cout << "Decimal no is: " << binaryToDecimal(binaryNo);
}