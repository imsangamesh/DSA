#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

//* EXPONENTIAL SEARCH
//! DOUBLING SEARCH
//! GALLOPING SEARCH
//! STRAZIK SEARCH

int binarySearch(vector<int> arr, int s, int e, int target) {
    while (s <= e) {
        int m = s + (e - s) / 2;
        cout << endl;
        if (arr[m] == target) {
            return m;
        } else if (arr[m] > target) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

int exponentialSearch(vector<int> arr, int target) {
    if (arr[0] == target) return 0;
    int n = arr.size() - 1;

    int i = 1;  //? : if i == 0 then i * 2 = 0

    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    cout << "applying bs on :" << i / 2 << " to " << i << endl;
    return binarySearch(arr, i / 2, min(i, n), target);
    //? min is imp as wkt i will be doubled when i is still in bound, however
    //? the value of ? of i*2 will be out of bound before it is passed to BS
}

int main() {
    vector<int> arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int target = 70;

    int ans = exponentialSearch(arr, target);
    cout << "Answer is: " << ans << endl;
}