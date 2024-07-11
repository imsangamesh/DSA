//?https://leetcode.com/problems/k-diff-pairs-in-an-array/
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
//* -------------------------------------------

bool binarySearch(vector<int> arr, int s, int key) {
  int e = arr.size() - 1;
  int found = false;

  while (s <= e) {
    int m = s + (e - s) / 2;

    if (arr[m] == key) {
      found = true;
      break;
    } else if (arr[m] > key) {
      e = m - 1;
    } else {
      s = m + 1;
    }
  }

  return found;
}

//! BETTER METHOD
int kDiffUniquePairs1(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  set<pair<int, int>> ans;
  int i = 0, j = 1;

  while (j < nums.size()) {
    int diff = nums[j] - nums[i];

    if (diff == k) {
      ans.insert({nums[i], nums[j]});
      i++, j++;
    } else if (diff > k) {
      i++;
    } else {
      j++;  // diff < k
    }
    if (i == j) j++;
  }
  return ans.size();
}

int kDiffUniquePairs2(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  set<pair<int, int>> ans;

  for (int i = 0; i < nums.size(); i++) {
    if (binarySearch(nums, i + 1, nums[i] + k) == true) {
      ans.insert({nums[i], nums[i] + k});
    }
  }

  return ans.size();
}

int main() {
  cout << endl;
  vector<int> arr = {1, 1, 3, 4, 5};
  int k = 2;

  // int ans = kDiffUniquePairs1(arr, k);
  int ans = kDiffUniquePairs2(arr, k);
  cout << "\nAnswer is: " << ans;

  cout << endl << endl;
}