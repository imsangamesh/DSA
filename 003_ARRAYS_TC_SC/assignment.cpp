#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int main() {
    //! ------------------------------ SORT ARRAY OF 0,1,2
    // int arr[] = {2, 0, 2, 1, 1, 0, 0, 0, 1, 1, 2};
    // int n = 11;
    // //? first method -
    // //* counting the no of 0s 1s 2s and then inserting 0s first followed by
    // //* 1s and 2s.
    // int ones = 0, zeroes = 0, twos = 0;
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] == 0) {
    //         zeroes++;
    //     } else if (arr[i] == 1) {
    //         ones++;
    //     } else {
    //         twos++;
    //     }
    // }

    // int i = 0;
    // while (zeroes--) {
    //     arr[i] = 0;
    //     i++;
    // }

    // while (ones--) {
    //     arr[i] = 1;
    //     i++;
    // }

    // while (twos--) {
    //     arr[i] = 2;
    //     i++;
    // }

    // printArray(arr, n);

    // //? second method - INPLACE
    // int s = 0, m = 0, e = n - 1;

    // while (m <= e) {
    //     if (arr[m] == 1) {
    //         m++;
    //     } else if (arr[m] == 0) {
    //         swap(arr[s], arr[m]);
    //         s++;
    //     } else {
    //         swap(arr[m], arr[e]);
    //         e--;
    //     }
    // }
    // printArray(arr, n);

    //! ------------------------------ MOVE -ve to LEFT
    // int arr[] = {1, 0, 2, -3, 0, 0, 4, -5, -10, 6};
    // int n = 10;
    // int s = 0, e = n - 1, m = 0;

    // while (s <= e) {
    //     if (arr[s] < 0) {
    //         s++;
    //     } else {
    //         swap(arr[s], arr[e]);
    //         e--;
    //     }
    // }
    // printArray(arr, n);

    //! ------------------------------ FIND DUPLICATES
    // vector<int> arr = {1, 3, 4, 2, 4};
    // int n = 5;
    // int ans = -1;

    //? first method
    //* sorting and comparing current no to next number - if they are equal,
    //* then it is duplicate.

    // //? second method - MODIFIED -ve marking
    // for (int i = 0; i < n; i++) {
    //     int index = abs(arr[i]);

    //     if (arr[index] < 0) {
    //         ans = index;
    //         break;
    //     } else {
    //         arr[index] *= -1;
    //     }
    // }
    // cout << "Answer is: " << ans;

    // //? third method - MODIFIED
    // while (arr[arr[0]] != arr[0]) {
    //     swap(arr[arr[0]], arr[0]);
    // }
    // cout << "Answer is: " << arr[0];

    //! ------------------------------ MISSING WITH DUPLICATES
    // vector<int> arr = {5, 3, 3, 3, 1};
    // int n = 5;
    // int ans = -1;

    // //? first method - MODIFIED -ve marking
    // for (int i = 0; i < n; i++) {
    //     int index = abs(arr[i]) - 1;
    //     //* we want indexes from 0 for checking, but we're having
    //     //* indexes(numbers in array) starting from 1 to n
    //     //* so we do -1.

    //     //* don't want to override the new result everytime
    //     if (ans == -1 && arr[index] < 0) {
    //         ans = index;
    //     } else {
    //         arr[index] *= -1;
    //     }
    // }
    // cout << "Index is: " << ans - 1 << endl;
    // cout << "Duplicate no is: " << abs(arr[ans - 1]) << endl;

    // for (int i = 0; i < n; i++) {
    //     if (arr[i] > 0) {
    //         cout << "Missing no is: " << i + 1 << endl;
    //         break;
    //     }
    // }

    // //? second method - MODIFIED
    // int i = 0;
    // while (i < n) {
    //     int index = arr[i] - 1;
    //     if (arr[i] != arr[index]) {
    //         swap(arr[i], arr[index]);
    //     } else {
    //         i++;
    //     }
    // }

    // cout << "Missing no are: ";
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] != i + 1) cout << i + 1 << " ";
    // }

    // cout << endl << "Duplicate no are: ";
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] != i + 1) cout << arr[i] << " ";
    // }

    //! ------------------------------ FIRST REPEATING ELE
    // int arr[] = {1, 5, 3, 4, 5, 6};
    // int n = 6;
    // int ans = -1;

    // //? first method
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[i] == arr[j]) {
    //             cout << arr[i];
    //             break;
    //         }
    //     }
    // }

    //? second method
    //* by hashing the no.s with it's respective iterations as value

    //! ------------------------------ COMMON in 3 ARRAYS
    // int arr[] = {1, 5, 10, 20, 40, 80};
    // int brr[] = {6, 7, 20, 40, 80, 100};
    // int crr[] = {3, 4, 15, 20, 40, 30, 70, 80, 120};
    // int an = 6, bn = 6, cn = 9;
    // int i = 0, j = 0, k = 0;

    // while (i < an && j < bn && k < cn) {
    //     if (arr[i] == brr[j] && brr[j] == crr[k]) {
    //         cout << arr[i] << " ";
    //         //* you should push no in SET which ignores duplicates
    //         //* or if you're said not to use SET data structure,
    //         //* remove all the duplicates before hand from arr, brr, crr and
    //         //* then run this while loop
    //         i++;
    //         j++;
    //         k++;
    //     } else if (arr[i] < brr[j]) {
    //         i++;
    //     } else if (brr[j] < crr[k]) {
    //         j++;
    //     } else {
    //         k++;
    //     }
    //     cout << "-----" << endl;
    // }
    //! ------------------------------ WAVE PRINT A MATRIX
    // vector<vector<int>> arr = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    // };

    // int rows = arr.size();
    // int cols = arr[0].size();

    // for (int col = 0; col < cols; col++) {
    //     if ((col & 1) == 0) {
    //         for (int i = 0; i < rows; i++) {
    //             cout << arr[i][col] << " ";
    //         }
    //     } else {
    //         for (int i = rows - 1; i >= 0; i--) {
    //             cout << arr[i][col] << " ";
    //         }
    //     }
    // }

    //! ------------------------------ SPIRAL PRINT
    // vector<vector<int>> arr = {
    //     {1, 2, 3, 4, 5, 6},       {7, 8, 9, 10, 11, 12},
    //     {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24},
    //     {25, 26, 27, 28, 29, 30},
    // };

    // int rows = arr.size(), cols = arr[0].size();
    // int sr = 0, ec = cols - 1, er = rows - 1, sc = 0;
    // int count = 0;

    // while (count < rows * cols) {
    //     //? printing starting row
    //     for (int c = sr; c <= ec; c++) {
    //         if (count < rows * cols) {
    //             cout << arr[sr][c] << " ";
    //         }
    //         count++;
    //     }

    //     //? printing ending col
    //     for (int r = sr + 1; r <= er; r++) {
    //         if (count < rows * cols) {
    //             cout << arr[r][ec] << " ";
    //         }
    //         count++;
    //     }

    //     //? printing ending row
    //     for (int c = ec - 1; c >= sc; c--) {
    //         if (count < rows * cols) {
    //             cout << arr[er][c] << " ";
    //         }
    //         count++;
    //     }

    //     //? printing starting col
    //     for (int r = er - 1; r >= sr + 1; r--) {
    //         if (count < rows * cols) {
    //             cout << arr[r][sc] << " ";
    //         }
    //         count++;
    //     }

    //     sr++;
    //     sc++;
    //     er--;
    //     ec--;
    // }

    //! ------------------------------ ADDITION OF LARGE NO
    // vector<int> arr = {9, 5, 4, 9};
    // vector<int> brr = {2, 1, 4};
    // vector<int> ans;
    // int i = arr.size() - 1;
    // int j = brr.size() - 1;

    // int carry = 0;
    // while (i >= 0 && j >= 0) {
    //     int res = arr[i] + brr[j] + carry;
    //     carry = res / 10;
    //     res = res % 10;

    //     ans.insert(ans.begin(), res);
    //     i--;
    //     j--;
    // }

    // while (i >= 0) {
    //     int res = arr[i] + 0;
    //     carry = res / 10;
    //     res = res % 10;

    //     ans.insert(ans.begin(), res);
    //     i--;
    //     j--;
    // }

    // while (j >= 0) {
    //     int res = 0 + arr[j];
    //     carry = res / 10;
    //     res = res % 10;

    //     ans.insert(ans.begin(), res);
    //     i--;
    //     j--;
    // }

    // if (carry) ans.insert(ans.begin(), carry);

    // cout << "Answer is: ";
    // printVector(ans);

    //! ------------------------------ FACTORIAL
}
