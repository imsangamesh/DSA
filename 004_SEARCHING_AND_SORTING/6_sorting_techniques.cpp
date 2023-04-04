#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int main() {
    vector<int> arr = {10, 1, 4, 8, 5, 7};
    int n = arr.size();

    //! ------------------------------ SELECTION SORT
    // //?  1+2+3+4+5+... = n * (n + 1) / 2; = n*n
    // for (int i = 0; i < n - 1; i++) {
    //     int min = i;

    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[j] < arr[min]) {
    //             min = j;
    //         }
    //     }

    //     swap(arr[i], arr[min]);
    // }
    // printVector(arr);

    //! ------------------------------ BUBBLE SORT
    // for (int round = 1; round < n; round++) {
    //     bool swapped = false;

    //     for (int j = 0; j < n - round; j++) {
    //         if (arr[j] > arr[j + 1]) {
    //             cout << "----------------" << endl;
    //             swapped = true;
    //             swap(arr[j], arr[j + 1]);
    //         }
    //     }

    //     if (swapped == false) break;
    // }
    // printVector(arr);

    //! ------------------------------ INSERTION SORT
    // for (int round = 0; round < n; round++) {
    //     //? 1. fetch
    //     int val = arr[round];

    //     //? 2. compare
    //     int j = round - 1;
    //     for (; j >= 0; j--) {
    //         if (arr[j] > val) {
    //             //? 3. shifting
    //             arr[j + 1] = arr[j];
    //         } else {
    //             break;
    //         }
    //     }

    //     //? 4. copy val
    //     arr[j + 1] = val;
    // }
    // printVector(arr);
}