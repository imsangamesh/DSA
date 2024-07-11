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
  // vector<int> arr = {1, 5, 10, 20, 40, 80};
  // vector<int> brr = {6, 7, 20, 80, 100};
  // vector<int> crr = {3, 4, 15, 20, 30, 70, 80, 120};

  vector<int> arr = {3, 3, 3};
  vector<int> brr = {3, 3, 3};
  vector<int> crr = {3, 3, 3};

  int a = 0, b = 0, c = 0;
  vector<int> ans;
  set<int> st;

  //! - TC:  O(n1 + n2 + n3)
  //! - SC:  O( min(n1 + n2 + n3) )
  while (a < arr.size() && b < brr.size() && c < crr.size()) {
    if (arr[a] == brr[b] && brr[b] == crr[c]) {
      st.insert(arr[a]);
      a++, b++, c++;
    } else if (arr[a] < brr[b]) {
      a++;
    } else if (brr[b] < crr[c]) {
      b++;
    } else {
      c++;
    }
  }

  for (auto num : st) {
    ans.push_back(num);
  }

  printVector(ans);
}