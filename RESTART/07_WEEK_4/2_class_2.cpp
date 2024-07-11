//*
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

int squareRoot(int n) {
  int s = 0, e = n;
  int ans = -1;

  while (s <= e) {
    int m = (s + e) / 2;

    if (m * m == n) {
      return m;
    } else if (m * m > n) {
      e = m - 1;
    } else if (m * m < n) {
      ans = m;
      s = m + 1;
    }
  }
  return ans;
}

bool binarySearch2D(vector<vector<int>> arr, int key) {
  int rows = arr.size(), cols = arr[0].size();
  int s = 0, e = rows * cols - 1;

  while (s <= e) {
    int m = (s + e) / 2;
    int rowIndex = m / cols;
    int colIndex = m % cols;
    int element = arr[rowIndex][colIndex];

    if (element == key) {
      cout << rowIndex << " " << colIndex << endl;
      return true;
    } else if (element > key) {
      e = m - 1;
    } else {
      s = m + 1;
    }
  }
  return false;
}

int main() {
  //! SQUARE ROOT of a number with binary search
  // cout << endl;
  // int number = 24;

  // int ans = squareRoot(number);
  // cout << "\nAnswer is: " << ans << endl;

  // double finalAns = ans;
  // int precision = 3;
  // double step = 0.1;

  // for (int i = 1; i <= precision; i++) {
  //   for (double n = finalAns; n * n <= number; n = n + step) {
  //     finalAns = n;
  //   }
  //   step /= 10;

  //   // double n = finalAns;
  //   // while (n * n <= number) {
  //   //   finalAns = n;
  //   //   n += step;
  //   // }
  //   // step /= 10;
  // }

  // cout << "Square root is: " << finalAns;

  //! BINARY search in 2D ARRAY
  vector<vector<int>> arr = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
  };

  cout << "Is present: " << binarySearch2D(arr, 16);
}