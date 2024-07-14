//?https://leetcode.com/problems/find-k-closest-elements/
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

/*
 * - We'll set a 'l' and 'h' on extreme ends of array, and one among the both
 * by checking the difference between the numbers and the target_no.
 * - We check for which number has the more-difference, it is farthest one,
 * and so we move that
 */
/*
 ? 45ms - 76.53% | 31mb - 59.9%
*/
//! - TC : n - k
//! - SC : k
vector<int> _2PointerApproach(vector<int> arr, int x, int k) {
  int s = 0, e = arr.size() - 1;

  while (e - s >= k) {
    if (arr[e] - x > x - arr[s]) {  // end-diff > start-diff
      e--;
    } else {
      s++;
    }
  }
  return vector<int>(arr.begin() + s, arr.begin() + e + 1);
}

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
KINDA GOT THE LOGIC - didn't understand Lower bound
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
? 53 ms - 61.59% | 31 mb - 73%
*/
int lowerBound(vector<int> arr, int target) {
  int s = 0, e = arr.size() - 1;
  int ans = -1;

  while (s <= e) {
    int m = s + (e - s) / 2;

    if (arr[m] == target) return m;
    if (arr[m] < target) {
      ans = m;
      s = m + 1;
    } else {
      e = m - 1;
    }
  }

  return ans;
}

int main() {
  cout << endl;
  vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
  int x = 35, k = 4;

  //! 2 POINTER APPROACH
  // vector<int> ans = _2PointerApproach(arr, x, k);
  // printVector(ans);

  //! BINARY SEARCH - LOWER BOUND
  int index = lowerBound(arr, x);
  int s = index;
  int e = index;

  while (k > 1) {
    if (s < 0)
      e++;
    else if (e > arr.size() - 1)
      s--;
    if (x - arr[s] > arr[e] - x) {
      e++;
    } else {
      s--;
    }

    k--;
  }

  for (int i = s; i <= e; i++) {
    cout << arr[i] << " ";
  }

  cout << endl << endl;
}