//?https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

bool canWeAssignBoardsToPainters(int arr[], int boards, int painters,
                                 long long limit) {
  long long boardsSumForEachPainter = 0;
  int painter = 1;

  for (int board = 0; board < boards; board++) {
    if (arr[board] > limit) return false;

    if (boardsSumForEachPainter + arr[board] > limit) {
      painter++;                             // start assigning to next painter
      boardsSumForEachPainter = arr[board];  // reset boards assigned
      if (painter > painters) return false;
    } else {
      boardsSumForEachPainter += arr[board];
    }
  }
  return true;
}

long long minTime(int arr[], int n, int k) {
  long long s = 0, e = 0;
  for (int i = 0; i < n; i++) {
    e += arr[i];
  }

  long long ans = -1;

  while (s <= e) {
    long long m = s + (e - s) / 2;

    if (canWeAssignBoardsToPainters(arr, n, k, m)) {
      ans = m;
      e = m - 1;
    } else {
      s = m + 1;
    }
  }

  return ans;
}

int main() {
  cout << endl;
  int arr[] = {10, 20, 30, 40};
  int n = 4;  // no of boards
  int k = 2;  // no of painters

  cout << "\nAnswer is: " << minTime(arr, n, k);
  cout << endl << endl;
}