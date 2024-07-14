//?https://www.geeksforgeeks.org/problems/aggressive-cows/0
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

bool canPlaceCows(vector<int>& stalls, int k, int diff) {
  int pos = stalls[0];  // place first cow at 0 index
  int cows = 1;         // num of cows placed - place first cow at 0 index

  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] - pos >= diff) {
      cows++;
      pos = stalls[i];  // one more cow is placed
    }
    if (cows == k) return true;  // PLACED all the cows
  }

  return false;
}

int solve(int n, int k, vector<int>& stalls) {
  int stallsCount = stalls.size() - 1;
  int s = 0;
  // last stall - first stall = difference = max_search_space
  int e = stalls[stallsCount] - stalls[0];
  int ans = -1;

  while (s <= e) {
    int m = s + (e - s) / 2;

    if (canPlaceCows(stalls, k, m)) {
      // try for placing cows with more 'm' diff
      ans = m;
      s = m + 1;
    } else {
      e = m - 1;
    }
  }

  return ans;
}

int main() {
  int n = 5;
  int k = 3;
  vector<int> stalls = {1, 2, 4, 8, 9};

  cout << "Max diff between cows: " << solve(n, k, stalls);
}