#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int binarySearch(vector<int> arr, int s, int target) {
    int e = arr.size() - 1;

    while (s <= e) {
        int m = s + (e - s) / 2;

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

int main() {
    vector<int> arr = {3, 1, 4, 1, 5};
    int k = 1;

    // //? by finding all the pairs using 2 loops - 1
    // for (int i = 0; i < arr.size(); i++) {
    //     for (int j = i + 1; j < arr.size(); j++) {
    //         if (abs(arr[i] - arr[j]) == k) {
    //             cout << arr[i] << " " << arr[j] << endl;
    //         }
    //     }
    // }

    // //? first sort the array using INBUILT function - 2
    // sort(arr.begin(), arr.end());
    // int i = 0, j = 1;
    // set<pair<int, int>> ans;

    // while (j < arr.size()) {
    //     int diff = arr[j] - arr[i];
    //     cout << "------------" << endl;

    //     if (diff == k) {
    //         ans.insert({arr[i], arr[j]});
    //         i++;
    //         j++;
    //     } else if (diff < k) {
    //         i++;
    //     } else {
    //         j++;
    //     }

    //     if (i == j) j++;
    // }
    // cout << "Ans is: " << ans.size() << endl;

    // //? first sort the array | then searching whether (a[i] + k) element is
    // //? present or not by binary search - 3
    // sort(arr.begin(), arr.end());
    // set<pair<int, int>> ans;

    // for (int i = 0; i < arr.size(); i++) {
    //     int curr = arr[i], searchElm = arr[i] + k;

    //     if (binarySearch(arr, i + 1, searchElm) != -1) {
    //         ans.insert({curr, searchElm});
    //         cout << "inserting " << curr << " " << searchElm << endl;
    //     }
    // }
    // cout << "Ans is: " << ans.size() << endl;
}
