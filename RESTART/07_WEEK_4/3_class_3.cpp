//*
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

int nearlySortedBinarySearch(vector<int> arr, int key) {
  int s = 0, e = arr.size() - 1;

  while (s <= e) {
    int m = (s + e) / 2;

    if (arr[m] == key) {
      return m;
    } else if (m >= s && arr[m - 1] == key) {
      return m - 1;
    } else if (m <= e && arr[m + 1] == key) {
      return m + 1;
    }

    else if (arr[m] > key) {
      e = m - 2;
    } else {
      s = m + 2;
    }
  }

  return -1;
}

int divisionByBinarySearch(int dividend, int divisor) {
  int divs = abs(divisor);
  int divd = abs(dividend);

  int s = 0, e = divd;
  int ans = 0;

  while (s <= e) {
    int m = (s + e) / 2;

    if (divs * m == divd) {
      ans = m;
      break;
    } else if (divs * m < divd) {
      ans = m;
      s = m + 1;
    } else if (divs * m > divd) {
      e = m - 1;
    }
  }

  if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0)) {
    return -ans;
  } else {
    return ans;
  }
}

int oddOccuringElement(vector<int> arr) {
  int s = 0, e = arr.size() - 1;

  while (s <= e) {
    if (s == e) return s;
    int mid = s + (e - s) / 2;

    if (mid % 2 == 0) {
      if (arr[mid] = arr[mid + 1]) {
        s = mid + 2;
      } else {
        e = mid;
      }
    } else {
      if (arr[mid] == arr[mid - 1]) {
        s = mid + 1;
      } else if (arr[mid] == arr[mid + 1]) {
        e = mid - 1;
      } else {
        return mid;
      }
    }
  }
  return -1;
}

int main() {
  cout << endl;

  //! BINARY SEARCH in NEARLY SORTED
  // vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
  // int key = 70;

  // int ans = nearlySortedBinarySearch(arr, key);
  // cout << "\nAnswer is: " << ans;

  // cout << endl << endl;

  //! DIVISION by BINARY SEARCH
  // int dividend = 22, divisor = 7;

  // int ans = divisionByBinarySearch(dividend, divisor);
  // cout << "\nQuotient is: " << ans << endl;

  // int precision = 10;
  // double quotient = ans;
  // double step = 0.1;

  // for (int i = 0; i < precision; i++) {
  //   for (double j = quotient; j * divisor < dividend; j += step) {
  //     quotient = j;
  //   }
  //   step /= 10;
  // }

  // cout << "Final ans: " << quotient;

  //! find the ODD OCCURING ELEMENT in an array
  vector<int> arr = {1, 2, 2, 3, 3, 4, 4, 5, 5, 4, 4, 600, 600, 4, 4};
  //? Method 1
  // int oddElement = 0;
  // for (int i = 0; i < arr.size(); i++) {
  //   oddElement = oddElement ^ arr[i];
  // }
  // cout << "Odd Element: " << oddElement;

  //? Method 2 - Binary
  cout << "Odd Occuring Element is: " << arr[oddOccuringElement(arr)];
}
