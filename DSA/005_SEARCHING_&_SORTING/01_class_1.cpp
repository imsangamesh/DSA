//*
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int s = 0, e = size - 1;

    while (s <= e) {
        int m = (s + e) / 2;

        if (arr[m] == key) {
            return m;
        } else if (key < arr[m]) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

int firstOccurence(int arr[], int size, int key) {
    int s = 0, e = size - 1;
    int index = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] == key) {
            index = m;
            e = m - 1;
        } else if (arr[m] > key) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return index;
}

int lastOccurence(int arr[], int size, int key) {
    int s = 0, e = size - 1;
    int index = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] == key) {
            index = m;
            s = m + 1;
        } else if (key < arr[m]) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return index;
}

//! -------------------- my own method
int findPeakELement1(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;
    int ans = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
            return m;
        }
        if (arr[m] > arr[m - 1]) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return -1;
}

//! -------------------- his method
int findPeakELement2(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;
    int ans = -1;

    while (s < e) {
        int m = s + (e - s) / 2;

        //? my own method
        if (arr[m] > arr[m - 1]) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    return s;
}

int main() {
    //! ------------------------------ BINARY SEARCH
    // int arr[] = {1, 2, 3, 10, 11, 22, 33, 55, 66, 110};
    // int n = 10;
    // int key = 66;

    // int res = binarySearch(arr, n, key);
    // if (res == -1) {
    //     cout << "Not found" << endl;
    // } else {
    //     cout << "Found at index: " << res << endl;
    // }

    //! ------------------------------ FIRST OCCURENCE / LOWER BOUND
    // int arr[] = {1, 2, 3, 10, 10, 10, 10, 55, 66, 110};
    // int n = 10;
    // int key = 10;

    // int res = firstOccurence(arr, n, key);
    // cout << "Found at index: " << res << endl;

    //! ------------------------------ LAST OCCURENCE / UPPER BOUND
    // int arr[] = {1, 2, 3, 10, 10, 10, 10, 55, 66, 110};
    // int n = 10;
    // int key = 10;

    // int res = lastOccurence(arr, n, key);
    // cout << "Found at index: " << res << endl;

    //! ------------------------------ TOTAL OCCURENCES
    // int arr[] = {1, 2, 3, 10, 10, 10, 10, 55, 66, 110};
    // int n = 10;
    // int key = 10;
    // int fo = firstOccurence(arr, n, key);
    // int lo = lastOccurence(arr, n, key);

    // cout << "Total occ: " << lo - fo + 1 << endl;

    //! ------------------------------ FIND MISSING NO
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11};
    // int n = 10;

    // //? with sum
    // int sum = 0;
    // for (int i = 0; i < n; i++) {
    //     sum += arr[i];
    // }

    // int actuallyReqdSum = 0;
    // for (int i = 1; i <= n + 1; i++) {
    //     actuallyReqdSum += i;
    // }

    // cout << "Missing is: " << actuallyReqdSum - sum << endl;

    // //? have to try - H/w - ERROR in some cases
    // int s = 0, e = n - 1;
    // int m = s + (e - s) / 2;

    // while (s < e) {
    //     m = s + (e - s) / 2;

    //     if (m + 1 == arr[m]) {
    //         s = m;
    //     } else {
    //         e = m - 1;
    //     }
    // }
    // cout << "Missing is: " << m + 1 << endl;

    //! ------------------------------ PEAK NO IN MOUNTAIN ARRAY
    vector<int> arr = {1, 2, 3, 4, 5, 10, 40, 100, 50, 3};

    int ans = findPeakELement1(arr);
    cout << "Peak index: " << ans;
}