#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        else
            return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int ceilIndex(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else {
            ceil = mid;
            right = mid - 1;
        }
    }

    return ceil;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = binarySearch(arr, 0, n - 1, x);
    result = ceilIndex(arr, n, x);

    int brr[] = {20, 4, 90, 5, 60, 66, 50, 20, 90, 10};
    // selectionSort(brr, 5);
    bubbleSort(brr, 10);
    for (int i = 0; i < 10; i++) {
        cout << brr[i] << " ";
    }

    // if (result == -1)
    //     cout << "Element not found.";
    // else
    //     cout << "Element found at index " << result << endl;
    return 0;
}
