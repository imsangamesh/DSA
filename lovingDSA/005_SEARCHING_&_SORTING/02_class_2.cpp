//*
//* ⍟ ◉ ● ⇒
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double findSqrt(int target) {
    int s = 0, e = target;
    double ans = -1.0;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (m * m == target) return m;

        if (m * m > target) {
            e = m - 1;
        } else {
            ans = m;
            s = m + 1;
        }
    }

    int precision = 10;
    double step = 0.1;

    for (int i = 0; i < precision; i++) {
        for (double num = ans + step; num * num <= target; num += step) {
            ans = num;
        }
        step /= 10;
    }

    return ans;
}

bool findIndexOf2DArray() {
    vector<vector<int>> arr = {
        {1, 2, 3, 4},     {5, 6, 7, 8},     {9, 10, 11, 12},
        {13, 14, 15, 16}, {17, 18, 19, 20},
    };
    int target = 30;
    int rows = arr.size(), cols = arr[0].size();

    int s = 0, e = rows * cols - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        //* TO REMEMBER ===================
        //* ====================
        int r = mid / cols;  //*
        int c = mid % cols;  //*
        //* ====================

        if (arr[r][c] == target) {
            cout << "Index are: " << r << " | " << c << "\n";
            return true;
        }

        if (arr[r][c] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return false;
}

int main() {
    //! -------------------------------------- SQUARE ROOT
    // int num = 10;
    //
    // double ans = findSqrt(num);
    // cout << "Answer is: " << setprecision(10) << ans;

    //! -------------------------------------- 2D ARRAY INDEX
    bool ans = findIndexOf2DArray();
    cout << "Found: " << ans;
}