//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

int findUniqueInPairs(vector<int> arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int main() {
    vector<int> arr = {0, 10, 20, 30, 40, 50, 5000, 60, 70, 80, 90, 100};
    vector<int> brr = {1, 3, 5, 2, 4, 7, 9};
    vector<int> crr = {2, 4, 6, 8, 5, 7, 9};
    vector<int> ans;

    //! ------------------------------ FIND UNIQUE IN THE PAIRS
    // vector<int> uniArray = {2, 3, 4, 4, 3, 2, 5, 6, 6, 7, 9, 8, 9, 8, 7};
    // cout << "Unique element in array of pairs: " <<
    // findUniqueInPairs(uniArray)
    //      << endl;

    //! ------------------------------ MERGING ELEMENTS
    // for (int i = 0; i < asize; i++) {
    //     ans.push_back(crr[i]);
    // }
    // for (int i = 0; i < bSize; i++) {
    //     ans.push_back(crr[i]);
    // }
    // printVector(ans);

    //! ------------------------------------- INTERSECTION
    // for (int i = 0; i < brr.size(); i++) {
    //     for (int j = 0; j < crr.size(); j++) {
    //         if (brr[i] == crr[j]) {
    //             ans.push_back(brr[i]);
    //         }
    //     }
    // }
    // printVector(ans);

    //! ------------------------------------- PAIR SUM
    // for (int i = 0; i < arr.size(); i++) {
    //     for (int j = i; j < arr.size(); j++) {
    //         if (arr[i] + arr[j] == 100) {
    //             cout << arr[i] << " + " << arr[j] << endl;
    //         }
    //     }
    // }

    //! ------------------------------------- TRIPLET
    // for (int i = 0; i < arr.size(); i++) {
    //     for (int j = i; j < arr.size(); j++) {
    //         for (int k = j; k < arr.size(); k++) {
    //             if (arr[i] + arr[j] + arr[k] == 100) {
    //                 cout << arr[i] << " + " << arr[j] << " + " << arr[k]
    //                      << endl;
    //             }
    //         }
    //     }
    // }

    //! ------------------------------------- SORT 0s & 1s
    // vector<int> zrr{0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1};
    // int s = 0, i = 0, e = zrr.size() - 1;

    // //* here we are traversing the array with i and checking whether
    // //* it is 1 or 0.
    // //* case 1: swap it with the no at start pos | start++ | i++
    // //* case 2: swap it with the no at end pos   | end--   | look below
    // //* we don't do i++ at other case as we're not sure that the
    // //* swapped no is not 1.
    // //? we don't get any change in no of loops

    // while (i < e) {
    //     if (zrr[i] == 0) {  //* if i = 0
    //         swap(zrr[i], zrr[s]);
    //         s++;
    //         i++;
    //     } else {  //* if i = 1
    //         swap(zrr[i], zrr[e]);
    //         e--;
    //     }
    // }
    // printVector(zrr);

    //! ------------------------------------- SORT 0s & 1s
}