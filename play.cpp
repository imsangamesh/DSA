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

int main() {
  vector<int> arr = {12, 34, 67, 90};
  int max = 101;

  int i = 0;

  int sum = 0;
  while (true) {
    if (sum + arr[i] > max) {
      break;
    }

    sum += arr[i];
    i++;
  }
}
