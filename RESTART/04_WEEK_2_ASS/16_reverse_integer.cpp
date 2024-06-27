//? https://leetcode.com/problems/reverse-integer

#include <iostream>
using namespace std;

int reverse(int x) {
  int num = x < 0 ? x * -1 : x;
  int ans = 0;

  while (num > 0) {
    ans = ans * 10 + (num % 10);
    num = num / 10;
  }

  return x < 0 ? ans * -1 : ans;
}

int main() {
  int n;
  cin >> n;

  cout << "Reverse number is: " << reverse(n);
}