#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

vector<int> multiply(vector<int> n1, int n2) {
  int carry = 0;
  vector<int> ans;
  for (int i = 0; i < n1.size(); i++) {
    int prod = n2 * n1[i] + carry;
    ans.push_back(prod % 10);
    carry = prod / 10;
  }
  while (carry) {
    ans.push_back(carry % 10);
    carry /= 10;
  }

  return ans;
}

int main() {
  int num = 100;
  vector<int> ans;
  ans.push_back(1);

  for (int n = 2; n <= num; n++) {
    ans = multiply(ans, n);
  }

  reverse(ans.begin(), ans.end());
  printVector(ans);
}
