//?https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-two-arrays2408/1

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
  vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 9, 5, 3, 4};
  vector<int> brr = {9, 9, 6, 6, 9, 9, 1, 6, 2};
  int a = arr.size() - 1;
  int b = brr.size() - 1;

  int prod = 1, carry = 0;
  vector<int> ans;

  while (a >= 0 || b >= 0) {
    int num1 = a < 0 ? 0 : arr[a];
    int num2 = b < 0 ? 0 : brr[b];

    int sum = num1 + num2 + carry;
    ans.push_back(sum % 10);
    carry = sum / 10;

    a--, b--;
  }

  ans.push_back(carry);
  while (ans[ans.size() - 1] == 0) {
    ans.pop_back();
  }

  reverse(ans.begin(), ans.end());
  printVector(ans);
}
