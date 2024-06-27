//? https://leetcode.com/problems/sort-colors/

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
  vector<int> arr{-1, 2, 0, -11, 20, 0, 2, -3, 4, -5, 6, 34, -7, 0};

  //! DUTCH NATIONAL FLAG - 2 POINTER APPROACH
  //! TC:  O(n)

  int l = 0, h = arr.size() - 1;

  while (l < h) {
    if (arr[l] < 0) {
      l++;
    } else if (arr[h] >= 0) {
      h--;
    } else {
      swap(arr[l], arr[h]);
      l++;
      h--;
    }
  }

  // while (l < h) {
  //   if (arr[l] < 0) {
  //     l++;
  //   } else {
  //     swap(arr[l], arr[h]);
  //     h--;
  //   }
  // }

  printVector(arr);
}