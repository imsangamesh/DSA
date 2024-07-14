//?
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

/*
 * - EXPONENTIAL - DOUBLING - GALLOPING - STRAZIK search
 * search in 'infinity' array
 * better than BS if 'target' is near 0
 */

//! EXPONENTIAL SEARCH
int exponentialSearch(vector<int> arr, int target) {
  if (arr[0] == target) return 0;
  int n = arr.size() - 1;
  int i = 1;

  while (arr[i] <= target && i <= n) {
    i = i << 1;  // left shift => i = i * 2
  }

  int s = i / 2, e = min(n, i);

  while (s <= e) {
    int m = s + (e - s) / 2;

    if (arr[m] == target) return m;
    if (arr[m] > target) {
      e = m - 1;
    } else {
      s = m + 1;
    }
  }

  cout << i;
  return -1;
}

//! BRUTE FORCE INFINITY SEARCH on INFINITY array
/*
 * - to find the 'm*2' which is JUST_greater than target, it takes log(m) where
 * 'm' is that JUST_greater index.
 * - now, the search_space for BS is: [2 ^ (log m) - 2 ^ (log m-1)], cuz, we
 * have to search from m to m/2
 * => 2 ^ (log m) - 2 ^ (log m-1)
 * => 2 ^ (log m) - (2 ^ log m) * (2 ^ -1)
 * => 2 ^ log m (1 - 2 ^ -1) // taking common
 * => 2 ^ log m (1  - 1/2)
 * => (2 ^ log m) / 2
 * => (2 ^ log m) * (2 ^ -1) // taking 2 to numerator
 * => 2 ^ (log m - 1)
 * => So, search space is: 2 ^ (log m - 1)
 * => But, TC of BS is log(n), so, subtituting above equation in 'n':
 */
//! - TC : log (2 ^ (log m-1))
//! - SC :

int bruteForceInfinityArrLinearSearch(vector<int> arr, int target) {
  for (int i = 0; true; i++) {
    if (arr[i] == target) return i;
    if (arr[i] > target) break;
  }
  return -1;
}

int unboundedSearch(vector<int> arr, int target) {
  if (arr[0] == target) return 0;
  int i = 1;

  while (arr[i] < target) {
    i = i << 1;  // left shift => i = i * 2
  }

  int s = i / 2, e = i;
  while (s <= e) {
    int m = s + (e - s) / 2;

    if (arr[m] == target) return m;
    if (arr[m] > target) {
      e = m - 1;
    } else {
      s = m + 1;
    }
  }

  cout << i;
  return 0;
}

int main() {
  cout << endl;
  vector<int> arr = {3, 4, 5, 6, 11, 13, 15, 56, 70};
  int target = 13;

  // int ans = exponentialSearch(arr, target);
  // int ans = bruteForceInfinityArrLinearSearch(arr, target);
  int ans = unboundedSearch(arr, target);

  cout << "\nAnswer is: " << ans;
  cout << endl << endl;
}