//?https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

int main() {
  int num = 70;
  vector<int> ans;
  ans.push_back(1);

  for (int i = 2; i <= num; i++) {
    int carry = 0;
    for (int j = 0; j <= ans.size() - 1; j++) {
      int prod = i * ans[j] + carry;
      ans[j] = prod % 10;
      carry = prod / 10;
    }
    while (carry) {
      ans.push_back(carry % 10);
      carry /= 10;
    }
  }

  reverse(ans.begin(), ans.end());
  printVector(ans);
}