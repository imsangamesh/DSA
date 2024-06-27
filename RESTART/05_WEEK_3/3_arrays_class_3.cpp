#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(int arr[][4], int rows, int cols, int key) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (arr[i][j] == key) return true;
    }
  }
  return false;
}

int findMinimum(int arr[][4], int rows, int cols) {
  int mini = INT_MAX;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (arr[i][j] < mini) mini = arr[i][j];
    }
  }
  return mini;
}

int findMaximum(int arr[][4], int rows, int cols) {
  int maxi = INT_MIN;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (arr[i][j] > maxi) maxi = arr[i][j];
    }
  }
  return maxi;
}

void transposeMatrix(int arr[][3], int rows, int cols, int transArr[][3]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      transArr[i][j] = arr[j][i];
    }
  }
}

void printVector(vector<int> arr) {
  for (auto val : arr) {
    cout << val << " ";
  }
}

int main() {
  //! 2-D ARRAY
  // int arr[3][3] = {
  //     {1, 2, 3},
  //     {4, 5, 6},
  //     {7, 8, 9},
  // };

  // // Row wise printing
  // cout << endl << "Row wise: ";
  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // // Column wise printing
  // cout << endl << "Column wise: ";
  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     cout << arr[j][i] << " ";
  //   }
  //   cout << endl;
  // }

  //! ROW SUM PRINT
  // int arr[5][4] = {
  //     {1, 2, 3, 4}, {2, 3, 4, 1}, {5, 6, 1, 3}, {2, 4, 6, 8}, {1, 4, 9, 0},
  // };

  // for (int i = 0; i < 5; i++) {
  //   int rowSum = 0;
  //   for (int j = 0; j < 4; j++) {
  //     rowSum += arr[i][j];
  //   }
  //   cout << rowSum << " ";
  // }

  //! COLUMN SUM PRINT
  // int arr[5][4] = {
  //     {1, 2, 3, 4},  //
  //     {2, 3, 4, 1},  //
  //     {5, 6, 1, 3},  //
  //     {2, 4, 6, 8},  //
  //     {1, 4, 9, 0},  //
  // };

  // for (int col = 0; col < 4; col++) {
  //   int colSum = 0;
  //   for (int row = 0; row < 5; row++) {
  //     colSum += arr[row][col];
  //   }
  //   cout << colSum << " ";
  // }

  //! LINEAR SEARCH
  // int arr[5][4] = {
  //     {1, 2, 3, 4},  //
  //     {2, 3, 4, 1},  //
  //     {5, 6, 1, 3},  //
  //     {2, 4, 6, 8},  //
  //     {1, 4, 9, 0},  //
  // };

  // cout << linearSearch(arr, 5, 4, 8);

  //! MAXIMUM AND MINIMUM
  // int arr[5][4] = {
  //     {1, 2, 3, 4},    //
  //     {2, 3, 14, 1},   //
  //     {5, 6, 1, 3},    //
  //     {21, 4, 16, 8},  //
  //     {1, 4, -9, 0},   //
  // };

  // cout << "Maximum is: " << findMaximum(arr, 5, 4) << endl;
  // cout << "Minimum is: " << findMinimum(arr, 5, 4) << endl;

  //! TRANSPOSE A MATRIX
  // int arr[3][3] = {
  //     {1, 2, 3},
  //     {4, 5, 6},
  //     {7, 8, 9},
  // };
  // int transArr[3][3];

  // transposeMatrix(arr, 3, 3, transArr);

  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     cout << transArr[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  //! 1:35 - VECTOR of VECTORS
  vector<vector<int>> arr;

  vector<int> a{1, 2, 3};
  vector<int> b{4, 5, 6};
  vector<int> c{7, 8, 9};

  arr.push_back(a);
  arr.push_back(b);
  arr.push_back(c);

  for (int i = 0; i < arr.size(); i++) {
    printVector(arr[i]);
    cout << endl;
  }
  cout << endl;

  //* METHOD 2
  vector<vector<int>> brr(3, vector<int>(5, 101));

  for (int i = 0; i < brr.size(); i++) {
    printVector(brr[i]);
    cout << endl;
  }
}