//?https://www.geeksforgeeks.org/problems/set-kth-bit3724/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;

int setKthBit(int n, int k) {
  int mask = 1 << k;
  return n | mask;
}

int main() {
  int n;
  cin >> n;

  int k;
  cin >> k;

  cout << "Answer is: " << setKthBit(n, k);
}