#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

//! USING HASH_MAP to store the count of number
//! - TC:  O(n)
//! - SC:  O(n)
int findFirstRepeatingElement(vector<int> arr) {
  unordered_map<int, int> hash;

  for (int i = 0; i < arr.size(); i++) {
    hash[arr[i]]++;
  }

  for (int i = 0; i < arr.size(); i++) {
    if (hash[arr[i]] > 1) return i + 1;
  }

  return -1;
}

//! WITHOUT HASH_MAP but ARRAY_MAP
int findFirstRepeatingElement2(vector<int> arr) {
  int maxi = INT_MIN;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > maxi) maxi = arr[i];
  }

  int hash[maxi] = {0};

  for (int i = 0; i < arr.size(); i++) {
    hash[arr[i]]++;
  }

  for (int i = 0; i < arr.size(); i++) {
    if (hash[arr[i]] > 1) return i + 1;
  }

  return -1;
}

int main() {
  vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
  cout << "First repeating: " << findFirstRepeatingElement2(arr);
}