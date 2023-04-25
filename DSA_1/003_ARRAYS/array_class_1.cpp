#include <limits.h>

#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return true;
    }
    return false;
}

int findMin(int arr[], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }

    return min;
}

int findMax(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    return max;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 5000, 60, 70, 80, 90, 100};
    int n = 11;

    //! ------------------------------ LINEAR SEARCH
    // if (linearSearch(arr, 10, 100)) {
    //     cout << "element is present" << endl;
    // } else {
    //     cout << "element is not present" << endl;
    // }

    //! --------------------------------------- FIND ZEROES & ONES
    // int zarray[10] = {0, 1, 2, 1, 0, 1, 0, 0, 1};
    // int zc = 0, oc = 0;

    // for (int i = 0; i < n; i++) {
    //     if (zarray[i] == 0) {
    //         zc++;
    //     } else if (zarray[i] == 1) {
    //         oc++;
    //     }
    // }
    // cout << "No of zeroes: " << zc << endl;
    // cout << "No of ones: " << oc << endl;

    //! --------------------------------------- FIND MINIMUM & MAXIMUM
    // cout << "Minimum is: " << findMin(arr, n) << endl;
    // cout << "Maximum is: " << findMax(arr, n) << endl;

    //! --------------------------------------- PRINTING EXTREMES
    // for (int i = 0; i < n / 2; i++) {
    //     cout << arr[i] << " | " << arr[n - 1 - i] << endl;
    // }
    // if (n % 2 != 0) cout << arr[n / 2];

    //! --------------------------------------- REVERSING BY SWAPPING EXTREMES
    // for (int i = 0; i < n / 2; i++) {
    //     int temp = arr[i];
    //     arr[i] = arr[n - 1 - i];
    //     arr[n - 1 - i] = temp;
    // }
    // printArray(arr, n);
}