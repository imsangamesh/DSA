//? https://leetcode.com/problems/find-the-duplicate-number/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

//! WITH MODIFYING - 1
//* Marking visited number as -ve and it gets caught at the 2nd visit
int findDuplicate(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int index = abs(arr[i]);

    if (arr[index] < 0) return index;

    arr[index] *= -1;
  }
  return 0;
}

//! WITH MODIFYING - 2
//* Taking each number to it's position (e.g. taking 3 to index 3)
//* Will find duplicate when the number is already in it's position
int findDuplicate2(vector<int> nums) {
  // for (int i = 0; i < nums.size(); i++) {
  //   int num = nums[0];

  //   if (num == nums[num]) return num;

  //   swap(num, nums[num]);
  // }
  // return 0;

  while (nums[0] != nums[nums[0]]) {
    swap(nums[0], nums[nums[0]]);
  }
  return nums[0];
}

int main() {
  vector<int> arr = {3, 3, 3, 3, 3};

  cout << "Duplicate: " << findDuplicate2(arr);
}