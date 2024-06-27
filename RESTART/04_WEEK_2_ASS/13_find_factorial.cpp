#include <iostream>
using namespace std;

int findFactorial(int n) {
  int prod = 1;
  for (int i = 1; i <= n; i++) {
    prod = prod * i;
  }
  return prod;
}

int main() {
  int n;
  cin >> n;

  cout << "Factorial is: " << findFactorial(n);
}