//*
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

void selectionSort(vector<int>& arr) {
  for (int i = 0; i <= arr.size() - 2; i++) {
    int minIndex = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[minIndex] > arr[j]) minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  }
}

void bubbleSort(vector<int>& arr) {
  int times = 0;
  for (int i = 0; i <= arr.size() - 2; i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
      times++;
    }
  }
  cout << times << endl;
}

void bubbleSortOptimize(vector<int>& arr) {
  int times = 0;
  for (int i = 0; i <= arr.size() - 2; i++) {
    bool swapped = false;
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
      times++;
    }
    if (swapped == false) break;
  }
  cout << times << endl;
}

int main() {
  cout << endl;
  vector<int> arr = {1, 10, 50, 19, 13, 12, 100, 10, 11, 4};
  // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 9, 10};

  //! SELECTION SORT - O(n^2)
  //? NOT STABLE - for [2, 2, 1]
  /*
   * This is used on smaller arrays to sort
   * This finds the "smallest" in the whole array and puts it in the start
   */
  // selectionSort(arr);

  //! BUBBLE/SHRINKING SORT - O(n^2)
  //? STABLE
  /*
   * This is mainly used to bring the "ith" largest element to it's position
   */
  // bubbleSort(arr);

  //! BUBBLE/SHRINKING SORT OPTIMIZED
  //! - TC:  O(n^2) for non-sorted, and O(n) for sorted
  // bubbleSortOptimize(arr);

  //! INSERTION
  //? Fetch - Compare - Shift - Copy
  //? This is mainly used in PARTIALLY SORTED ARRAYs
  /*
   * We pick a number (by outer loop) and then compare the previous elements
   * with the picked_element till previous element becomes smaller than the
   * picked. We'll also be shifting the numbers if they are larger than the
   * picked_num. And when we stop (when the num is smaller than picked), then we
   * simply copy the picked num to the position where we stopped.
   */
  //! - TC:  O(n) for sorted - O(n^2) for non-sorted

  for (int i = 1; i < arr.size(); i++) {
    int value = arr[i];
    int j = i - 1;

    while (arr[j] > value) {
      // we are comparing with 'value' and not with 'arr[i]', cuz, the value
      // 'arr[i]' may be overrided while shifting... it is overrided in most of
      // the shifting cases.
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = value;
  }

  printVector(arr);
  cout << endl << endl;
}
