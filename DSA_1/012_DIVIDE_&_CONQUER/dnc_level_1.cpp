#include <iostream>
#include <vector>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    // copy values
    int k = s;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex++] = left[leftIndex++];
        } else {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    //* copy logic for left array
    while (leftIndex < len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    //* copy logic for right array
    while (leftIndex < len2) {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}

void mergeSort(int* arr, int s, int e) {
    // base case
    if (s >= e) return;

    int mid = s + (e - s) / 2;
    // sort Left part
    mergeSort(arr, s, mid);

    // sort Right part
    mergeSort(arr, mid + 1, e);

    //* merge 2 sorted arrays
    merge(arr, s, e);
}

int main() {
    int arr[] = {4, 13, 5, 2, 12, 2, 2, 22};
    int n = end(arr) - begin(arr);
    int s = 0, e = n - 1;
    //
    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}