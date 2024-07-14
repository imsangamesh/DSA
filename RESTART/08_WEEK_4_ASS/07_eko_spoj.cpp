//?
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

bool isWoodCollectedEnough(vector<int> arr, int w, int sawHeight) {
  int totalWood = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > sawHeight) {
      totalWood += arr[i] - sawHeight;
    }
  }
  return totalWood >= w;
}

int main() {
  cout << endl;
  vector<int> arr = {20, 15, 10, 17};
  int n = arr.size() - 1;
  int w = 7;
  int ans = -1;

  // arr = {4, 42, 40, 26, 46};
  // w = 20;

  // finding the search_space, seeking where the wood is no longer available
  int i = 1;
  while (isWoodCollectedEnough(arr, w, i)) {
    i *= 2;
  }

  int s = i / 2, e = i;
  while (s <= e) {
    int m = s + ((e - s) >> 1);
    if (isWoodCollectedEnough(arr, w, m)) {
      ans = m;
      s = m + 1;
    } else {
      e = m - 1;
    }
  }

  cout << "\nAnswer is: " << ans;
  cout << endl << endl;
}