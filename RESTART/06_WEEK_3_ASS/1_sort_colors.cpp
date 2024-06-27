//? https://leetcode.com/problems/sort-colors/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

int main() {
  vector<int> arr{2, 0, 2, 1, 1, 0};

  //! Method 1: USING PREDEFINED STL SORT FUNCTION
  // sort(arr.begin(), arr.end());
  // printVector(arr);

  //! Method 2: COUNTING METHOD - (NOT INPLACE)
  //? First count the number of 0s, 1s, and 2s and then
  //? using the count, spread them into an array
  // int zeroes = 0, ones = 0, twos = 0;

  // for (int i = 0; i < arr.size(); i++) {
  //   if (arr[i] == 0) {
  //     zeroes++;
  //   } else if (arr[i] == 1) {
  //     ones++;
  //   } else {
  //     twos++;
  //   }
  // }

  // int i = 0;
  // while (zeroes--) {
  //   arr[i] = 0;
  //   i++;
  // }
  // while (ones--) {
  //   arr[i] = 1;
  //   i++;
  // }
  // while (twos--) {
  //   arr[i] = 2;
  //   i++;
  // }

  // printVector(arr);

  //! Method 3: INPLACE
  int l = 0, m = 0, h = arr.size() - 1;

  while (m <= h) {
    if (arr[m] == 0) {
      swap(arr[m], arr[l]);
      l++;
      m++;
      //* Why m++ here?
      //? cuz, we are sure that behind 0s will BE ALWAYS behind 'm'
      //? if 'l' is on 1 & 'm' is on 0, this should not be the case!
      //? so, we do: m++
    } else if (arr[m] == 1) {
      m++;
    } else if (arr[m] == 2) {
      swap(arr[m], arr[h]);
      h--;
    }
  }

  printVector(arr);
}