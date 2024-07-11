#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

//! NEGATIVE MARKING METHOD - 1
//! - TC:  O(n)
//! - SC:  1
void findMissing(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int index = abs(arr[i]) - 1;
    if (arr[index] > 0) arr[index] *= -1;
  }

  printVector(arr);
  cout << endl;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > 0) cout << i + 1 << " ";
  }
}

//! SORTING + SWAPPING METHOD - 2
//! - TC:  O(n)
//! - SC:  1
void findMissing2(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int index = arr[i];
    swap(index, arr[index - 1]);
  }

  printVector(arr);
  cout << endl;

  for (int i = 0; i < arr.size(); i++) {
    if (i + 1 != arr[i]) cout << i + 1 << " ";
  }
}

int main() {
  // vector<int> arr = {1, 2, 5, 3, 2};
  // vector<int> arr = {3, 3, 3, 1, 2};
  vector<int> arr = {3, 3, 3, 3, 3};

  findMissing2(arr);
}