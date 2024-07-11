#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

int main() {
  int arr[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
  };

  for (int col = 0; col < 4; col++) {
    if ((col & 1) == 0) {  // top to bottom
      for (int row = 0; row < 3; row++) {
        cout << arr[row][col] << " ";
      }
    } else {  // bottom to top
      for (int row = 2; row >= 0; row--) {
        cout << arr[row][col] << " ";
      }
    }
  }
}