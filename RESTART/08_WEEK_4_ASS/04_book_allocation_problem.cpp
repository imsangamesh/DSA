//?https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

bool canWeAssignBooks(int arr[], int n, int limit, int studs, int total) {
  int book = 0;
  for (int stud = 1; stud <= studs; stud++) {
    int sum = 0;
    while (book < n) {
      // if pages > max_limit
      if (arr[book] > limit) return false;

      if (sum + arr[book] > limit) break;

      sum += arr[book];
      total -= arr[book];
      book++;
    }
  }
  if (total == 0) return true;
  return false;
}

//! TUTOR SOLUTION
bool canWeAssignBooksBetter(int arr[], int books, int limit, int studs) {
  int pagesSum = 0;
  int studCount = 1;

  for (int i = 0; i < books; i++) {
    if (arr[i] > limit) return false;

    if (arr[i] + pagesSum > limit) {
      studCount++;        // start assigning to next stud
      pagesSum = arr[i];  // assign the book to next stud
      if (studCount > studs) return false;
    } else {
      pagesSum += arr[i];
    }
  }

  return true;
}

long long findPages(int n, int arr[], int m) {
  if (m > n) return -1;

  int total = 0;
  for (int i = 0; i < n; i++) {
    total += arr[i];
  }

  int s = 0, e = total;
  int ans = -1;

  while (s <= e) {
    int mid = s + (e - s) / 2;

    if (canWeAssignBooksBetter(arr, n, mid, m)) {
      ans = mid;
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return ans;
}

int main() {
  cout << endl;
  int arr[] = {12, 34, 67, 90};
  int n = 4;
  int m = 2;

  long long ans = findPages(n, arr, m);

  cout << ans;
  cout << endl << endl;
}