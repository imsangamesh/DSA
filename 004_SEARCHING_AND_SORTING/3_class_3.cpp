#include <iostream>
#include <vector>
using namespace std;

int binarySearchNearlySorted(vector<int> arr, int target) {
    int s = 0, e = arr.size();

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (target == arr[m]) {
            return m;
        } else if (target == arr[m - 1] && m - 1 >= s) {
            return m - 1;
        } else if (target == arr[m + 1] && m + 1 < e) {
            return m + 1;
        } else if (target > arr[m]) {
            s = m + 2;
        } else {
            e = m - 2;
        }
    }
    return -1;
}

int binaryDivision(int dividend, int divisor) {
    if (dividend == 0 || divisor == 0) return -1;
    int s = 0, e = abs(dividend);
    int ans = 0;

    while (s <= e) {
        int m = s + (e - s) / 2;
        int res = abs(m * divisor);

        if (res == abs(dividend)) {
            return m;
        } else if (res < abs(dividend)) {
            ans = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return ans;
}

int findOddOccuringNo(vector<int> arr) {
    int s = 0, e = arr.size();  //? check e value once

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (s == e) {
            return s;
        }

        if (m % 2 == 0) {  //? EVEN CASE
            if (arr[m] == arr[m + 1]) {
                s = m + 2;
            } else if (arr[m] == arr[m - 1]) {
                e = m - 2;
            } else {
                return m;
            }
        } else {  //? ODD CASE
            if (arr[m] == arr[m + 1]) {
                e = m - 1;
            } else if (arr[m] == arr[m - 1]) {
                s = m + 1;
            }
        }
    }
}

int findPivot(vector<int> arr) {
    int s = 0, e = arr.size() - 1;
    int ans = e;

    while (s < e) {
        int m = s + (e - s) / 2;

        if (arr[m] < arr[m + 1]) {
            s = m + 1;
        } else {
            ans = m;
            e = m;
        }
    }
    return ans;
}

int main() {
    //! ------------------------------ NEARLY SORTED ARRAY
    // vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    // int target = 40;

    // int ans = binarySearchNearlySorted(arr, target);
    // cout << ans << endl;

    //! ------------------------------ DIVIDE NOS
    // int dividend = -22, divisor = 7;
    // int precision = 3;

    // double ans = binaryDivision(dividend, divisor);

    // double step = 0.1;
    // for (int i = 0; i < precision; i++) {
    //     for (double j = ans; j * abs(divisor) <= abs(dividend); j = j + step)
    //     {
    //         ans = j;
    //     }
    //     step /= 10;
    // }

    // if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0)) {
    //     cout << ans << endl;
    // } else {
    //     cout << -ans << endl;
    // }

    //! ------------------------------ ODD OCCURING NO
    // vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 3, 60, 60, 4, 4};

    // //? XOR method with O(n) = n - BAD
    // int ans = 0;
    // for (int i = 0; i < arr.size(); i++) {
    //     ans ^= arr[i];
    // }
    // cout << ans << endl;

    // //? binary search method
    // int ans = findOddOccuringNo(arr);
    // cout << "Index is: " << ans << endl;
    // cout << "Answer is: " << arr[ans] << endl;

    vector<int> arr = {1, 2, 3, 5, 7, 9, 100};
    // vector<int> arr = {10, 9, 7, 6, 5};

    // int ans = findPivot(arr);
    // cout << "Index is: " << ans << endl;
    // cout << "Answer is: " << arr[ans] << endl;
}