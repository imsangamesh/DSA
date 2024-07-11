//*
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

int findPivot(vector<int> arr) {
  int s = 0, e = arr.size() - 1;
  int n = arr.size() - 1;

  while (s <= e) {
    int m = s + (e - s) / 2;

    if (s == e) return s;
    if (m <= n && arr[m] > arr[m + 1]) return m;
    if (m >= 0 && arr[m - 1] > arr[m]) return m - 1;

    if (arr[m] > arr[s]) {
      s = m + 1;
    } else {
      e = m - 1;
    }
  }
  return -1;
}

int binarySearch(vector<int> arr, int s, int e, int target) {
  while (s <= e) {
    int m = s + (e - s) / 2;
    if (arr[m] == target) return m;

    if (arr[m] > target) {
      e = m - 1;
    } else {
      s = m + 1;
    }
  }
  return -1;
}

int search(vector<int>& nums, int target) {
  int p = findPivot(nums);
  if (p == -1) return -1;

  if (target >= nums[0] && target <= nums[p]) {
    return binarySearch(nums, 0, p, target);
  } else {
    return binarySearch(nums, p + 1, nums.size() - 1, target);
  }

  return -1;
}

int main() {
  cout << endl;
  vector<int> arr = {8, 9, 10, 2, 4, 6};
  arr = {2, 4, 7, 8, 9, 10, 100, 1000};

  //! PIVOT element in ROTATED SORTED array
  int ans = search(arr, 10);
  cout << "\nAnswer is: " << ans;

  cout << endl << endl;
}
