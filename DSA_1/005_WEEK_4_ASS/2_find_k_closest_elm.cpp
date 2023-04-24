#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int lowerBound(vector<int> arr, int x) {
    int s = 0, e = arr.size() - 1;
    int ans = end;  //! you'll get error if ans = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] >= x) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return ans;
}

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int main() {
    //* vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    //* vector<int> arr = {35, 39, 42, 45, 48, 50, 53, 55, 56};
    //* int x = 34, k = 4;

    vector<int> arr = {3, 5, 8, 10};
    int x = 15, k = 2;

    // //? double pointer + window compression
    // int l = 0, h = arr.size() - 1;
    // while (h - l >= k) {
    //     int l_diff = abs(arr[l] - x);
    //     int h_diff = abs(arr[h] - x);

    //     if (l_diff > h_diff) {
    //         l++;
    //     } else {
    //         h--;
    //     }
    // }
    // vector<int> ans(arr.begin() + l, arr.begin() + hx + 1);

    // for (int i = 0; i <= ans.size() - 1; i++) {
    //     cout << ans[i] << " ";
    // }

    // //? binary search (min bound) + window expansion
    /**
     ** lower bound: if(target is present) => return address
     **              else => return next itr

     ** upper bound: if(target is present) => return next itr
     **              else => return next itr

     *? here we're taking h = lowerbound as wkt lowerbound returns the next itr
     *? if not present
     */

    int h = lowerBound(arr, x);
    int l = h - 1;

    while (k--) {
        if (l <= 0) {
            h++;
        } else if (h >= arr.size() - 1) {
            l--;
        } else if (x - arr[l] > arr[h] - x) {
            h++;
        } else {
            l--;
        }
    }

    vector<int> ans(arr.begin() + l + 1, arr.begin() + h);
    printVector(ans);
}