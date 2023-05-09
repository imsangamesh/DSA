#include <iostream>
#include <vector>
using namespace std;

int findPivotInRotated(vector<int> arr) {
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (s == e) return s;

        if (arr[m] > arr[m + 1] && m <= e) {
            return m;
        } else if (arr[m - 1] > arr[m] && m - 1 >= s) {
            return m - 1;
        }

        if (arr[s] > arr[m]) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

int binarySearch(vector<int> arr, int s, int e, int key) {
    cout << "------" << s << e << endl;
    while (s <= e) {
        cout << "------" << endl;
        int m = s + (e - s) / 2;

        if (arr[m] == key) {
            return m;
        } else if (arr[m] > key) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

int squareRoot(int target) {
    int s = 0, e = target;  //? you can take target/2 except for 2,3,5
    int ans = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (m * m == target) {
            return m;
        } else if (m * m > target) {
            e = m - 1;
        } else {
            ans = m;
            s = m + 1;
        }
    }
    return ans;
}

int sortNearlySorted(vector<int> arr, int target) {
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] == target) {
            return m;
        } else if (arr[m - 1] == target) {
            return m - 1;
        } else if (arr[m + 1] == target) {
            return m + 1;
        }

        if (arr[m] > target) {
            e = m - 2;
        } else {
            s = m + 2;
        }
    }
    return -1;
}

int binaryDivision(int dividend, int divisor) {
    int s = 0, e = dividend;
    int ans = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (divisor * m == dividend) {
            return m;
        } else if (divisor * m > dividend) {
            e = m - 1;
        } else {
            ans = m;
            s = m + 1;
        }
    }
    return ans;
}

int main() {
    //! ------------------------------ PIVOT in ROTATED arr
    // vector<int> arr = {2, 4, 6, 8, 9, 10};

    // int ans = findPivotInRotated(arr);
    // cout << "Index is: " << ans << endl;
    // cout << "Answer is: " << arr[ans] << endl;

    //! ------------------------------ SEARCH in ROTATED - X
    // vector<int> arr = {9, 10, 2, 4, 6, 8};
    // int target = 6;
    // int ans = -1;

    // int pivot = findPivotInRotated(arr);

    // if (target <= arr[pivot] && target >= arr[0]) {
    //     binarySearch(arr, target, 0, pivot);
    // } else {
    //     binarySearch(arr, target, pivot, arr.size() - 1);
    //     cout << "-----3-" << endl;
    // }

    // cout << "Pivot of ele is: " << pivot << endl;
    // cout << "Index of ele is: " << ans << endl;

    //! ------------------------------ SQUARE ROOT
    // int target = 35;
    // int precision = 3;

    // int rough = squareRoot(target);
    // cout << "Rough root: " << rough << endl;

    // double step = 0.1;
    // double ans = rough;

    // for (int i = 0; i < precision; i++) {
    //     double j = ans;

    //     while (j * j <= target) {
    //         ans = j;
    //         j = j + step;
    //     }

    //     step /= 10;
    // }
    // cout << "Final root: " << ans << endl;

    //! ------------------------------ NEARLY SORTED ARRAY
    // vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    // int target = 70;

    // int ans = sortNearlySorted(arr, target);
    // cout << ans << endl;

    //! ------------------------------ DIVIDE NOS
    // int dividend = 10, divisor = 3;
    // int precision = 3;

    // double ans = binaryDivision(dividend, divisor);
    // cout << "Answer: " << ans << endl;

    // double step = 0.1;
    // for (int i = 0; i < precision; i++) {
    //     double j = ans;
    //     while (j * divisor <= dividend) {
    //         ans = j;
    //         j += step;
    //     }
    //     step /= 10;
    // }
    // cout << "Answer with precision: " << ans << endl;

    //! ------------------------------ ODD OCCURING NO
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 60, 60, 3, 4, 4};

    // //? XOR method with O(n) = n - BAD
    // int ans = 0;
    // for (int i = 0; i < arr.size(); i++) {
    //     ans ^= arr[i];
    // }
    // cout << ans << endl;

    // //? binary search method
    int s = 0, e = arr.size() - 1;
    int ans = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] != arr[m + 1] && arr[m] != arr[m - 1]) {
            ans = m;
        }

        if (m % 2 == 0) {
            if (arr[m] == arr[m + 1]) {
                s = m + 2;
            } else {
                e = m - 2;
            }
        } else {
            if (arr[m] == arr[m - 1]) {
                s = m + 2;
            } else {
                e = m - 2;
            }
        }
    }

    cout << "Answer is " << ans << endl;
}