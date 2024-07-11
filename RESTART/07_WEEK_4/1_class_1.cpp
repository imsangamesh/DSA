//*
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

//! - TC:  O(log n)
/*
 * - in 1st iteration, there will be n elements
 * in 2nd -> n/2, 3rd -> n/4, 4th -> n/8 ... and for the Kth iteration,
 * there will be 1 item left. here is the iteration mapped to elements count:
 * Iteration: elements left
 * 1: n/2^0 = n
 * 2: n/2^1 = n/2
 * 3: n/2^2 = n/4
 * 4: n/2^3 = n/8
 * ... ...
 * ... ...
 * k: n/2^k = n/2^k
 * now, we know that after k iterations, element = 1 = (n/2^k).
 * so, if we now equate n / 2^k = 1
 * => n = 2 ^ k
 * => log(n) = k | k = log(n)
 * => so, we have traversed k iterations and so, TC = k = log(n)
 */
//! - SC:  O()
int binarySearch(vector<int> arr, int key) {
  int s = 0, e = arr.size() - 1;

  while (s <= e) {
    int mid = s + e / 2;

    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return -1;
}

int firstOccurenace(vector<int> arr, int key) {
  int s = 0, e = arr.size() - 1;
  int ans = -1;

  while (s <= e) {
    int mid = (s + e) / 2;

    if (arr[mid] == key) {
      ans = mid;
      e = mid - 1;
    } else if (arr[mid] > key) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return ans;
}

int lastOccurenace(vector<int> arr, int key) {
  int s = 0, e = arr.size() - 1;
  int ans = -1;

  while (s <= e) {
    int mid = (s + e) / 2;

    if (arr[mid] == key) {
      ans = mid;
      s = mid + 1;
    } else if (arr[mid] > key) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return ans;
}

//? https://leetcode.com/problems/find-peak-element/
int peakElement(vector<int> arr) {
  int s = 0, e = arr.size() - 1;

  /*
   * first we check if [mid] is less than [mid+1], if it is, then we know that
   * [mid] is already smaller than some number, so, we are sure that our peak
   * element is not mid and we will definitely find it in the right side
   *
   * (else case) if [mid] is not smaller than [mid+1] then, it means that mid is
   * larger than [mid+1], this means that [mid] may be a peak element, so, to
   * not loose that number, we search in the left side INCLUDING MID.
   * -> so, [e = mid]
   *
   * cuz, of [e = mid], we had to check only till [s < e]
   */

  while (s < e) {
    int mid = s + (e - s) / 2;

    cout << mid << endl;

    if (arr[mid] < arr[mid + 1]) {
      s = mid + 1;
    } else {
      e = mid;
    }
  }

  return s;
}

int main() {
  //! BINARY SEARCH INTRO
  // vector<int> arr = {2, 4, 6, 8, 10, 12, 16, 50};
  // int key = 50;

  // cout << "Found at: " << binarySearch(arr, key);

  //! find the FIRST & LAST & TOTAL OCCURENCE
  // vector<int> arr = {1, 3, 4, 4, 4, 4, 4, 4, 4, 6, 7, 9};
  // int key = 4;

  // cout << "First occ at: " << firstOccurenace(arr, key);
  // cout << endl;
  // cout << "Last occ at: " << lastOccurenace(arr, key);
  // cout << endl;
  // cout << "Total occ: "
  //      << lastOccurenace(arr, key) - firstOccurenace(arr, key) + 1;

  //! find MISSING Number - HW

  //! find PEAK element in an array
  vector<int> arr = {0, 10, 5, 2};
  arr = {1, 2, 1, 3, 5, 6, 4};
  arr = {1};

  cout << "Peak Element: " << peakElement(arr);
}
