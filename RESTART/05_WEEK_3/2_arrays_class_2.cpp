#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

int findUnique(vector<int> arr) {
  int ans = 0;
  for (int i = 0; i < arr.size(); i++) {
    ans = ans ^ arr[i];
  }
  return ans;
}

int main() {
  //! EVERYTHING about VECTORS
  // vector<int> arr;

  // cout << arr.size() << endl;
  // cout << arr.capacity() << endl;

  // // Push
  // arr.push_back(5);
  // arr.push_back(6);

  // for (int i = 0; i < arr.size(); i++) {
  //   cout << arr[i] << " ";
  // }

  // vector<int> brr(10, -100);
  // printVector(brr);

  //! 31 - FIND UNIQUE ELEMENT
  // vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 10};
  // cout << "Unique number: " << findUnique(arr);

  //! 42 - UNION of 2 ARRAYS
  // vector<int> arr{2, 4, 6, 8};
  // vector<int> brr{1, 3, 7, 9};
  // vector<int> ans;

  // for (int i = 0; i < arr.size(); i++) {
  //   ans.push_back(arr[i]);
  // }
  // for (int i = 0; i < arr.size(); i++) {
  //   ans.push_back(brr[i]);
  // }

  // printVector(ans);

  //! 49 - INTERSECTION of 2 ARRAYS
  // vector<int> arr{2, 4, 6, 8};
  // vector<int> brr{1, 2, 3, 4, 7, 9};
  // vector<int> ans;

  // for (int i = 0; i < arr.size(); i++) {
  //   for (int j = 0; j < brr.size(); j++) {
  //     if (arr[i] == brr[j]) ans.push_back(arr[i]);
  //   }
  // }

  // cout << "Intersection array is: ";
  // printVector(ans);

  //! 1:06 - PAIR SUM of 9
  // vector<int> arr{1, 3, 5, 7, 2, 4, 6};
  // for (int i = 0; i < arr.size() - 1; i++) {
  //   for (int j = i + 1; j < arr.size(); j++) {
  //     if (arr[i] + arr[j] == 9) {
  //       cout << arr[i] << " " << arr[j] << endl;
  //     }
  //   }
  // }

  //! 1:17 - TRIPLET SUM of 100
  // vector<int> arr{10, 20, 30, 40, 50, 60, 70, 80, 90};
  // for (int i = 0; i < arr.size(); i++) {
  //   for (int j = i + 1; j < arr.size() - 1; j++) {
  //     for (int k = j + 1; k < arr.size() - 2; k++) {
  //       if (arr[i] + arr[j] + arr[k] == 100) {
  //         cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
  //       }
  //     }
  //   }
  // }

  //! SORT 0s and 1s
  vector<int> arr{1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0};
  int i = 0, j = arr.size() - 1;

  while (i <= j) {
    if (arr[i] == 1 && arr[j] == 0) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
    if (arr[i] == 0) i++;
    if (arr[j] == 1) j--;
  }

  printVector(arr);
}