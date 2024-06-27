#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) return true;
  }
  return false;
}

int main() {
  //! LINEAR SEARCH
  // int arr[5] = {1, 3, 5, 7, 8};
  // int size = 5;

  // cout << "Enter the key to find: " << endl;
  // int key;
  // cin >> key;

  // if (linearSearch(arr, size, key)) {
  //   cout << "Present";
  // } else {
  //   cout << "Not Present";
  // }

  //! ZEROES & ONES in the array
  // int arr[] = {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0};
  // int zeroes = 0;
  // int ones = 0;
  // int size = 14;

  // for (int i = 0; i < size; i++) {
  //   if (arr[i] == 1) ones++;
  //   if (arr[i] == 0) zeroes++;
  // }

  // cout << "No of ones: " << ones << endl;
  // cout << "No of zeroes: " << zeroes << endl;

  //! MAXIMUM NO in a ARRAY
  // int arr[] = {2, 4, 1, 6, 16, 20, 8, 9, 0, 10, 1, 12, 15};
  // int size = 7;
  // int max = INT_MIN;

  // for (int i = 0; i < size; i++) {
  //   if (arr[i] > max) max = arr[i];
  // }

  // cout << "Maximum is: " << max;

  //! PRINT EXTREMES in a ARRAY
  // int arr[] = {1, 8, 2, 7, 3, 9, 6, 4, 5};
  // int size = 9;

  // int start = 0;
  // int end = size - 1;

  // while (start <= end) {
  //   if (start == end) {
  //     cout << arr[start] << " ";
  //   } else {
  //     cout << arr[start] << " ";
  //     cout << arr[end] << endl;
  //   }
  //   start++;
  //   end--;
  // }

  //! REVERSE an ARRAY
  int arr[] = {1, 8, 2, 7, 3, 9, 6, 4, 5};
  int size = 9;

  cout << "Original: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < size / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
  }

  cout << "Reversed: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

// 1:28