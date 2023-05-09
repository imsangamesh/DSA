//*
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

//! ----------------------- BRUTE FORCE - nieve
int kDiffPairInArray(vector<int> arr, int k) {
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i; j < arr.size(); j++) {
            if (abs(arr[i] - arr[j]) == k) count++;
        }
    }
    return count;
}
//! TC:  N^2
//* 2 loops
//! SC:  constant

//! ----------------------- 2 POINTER APPROACH
int twoPointerApproach(vector<int> arr, int k) {
    int i = 0, j = 1;

    //* to avoid duplicate pairs
    // you can also use, set<pair<int, int>> ans;
    // and then insert values as >> ans.insert({arr[i], arr[j]});
    unordered_map<int, int> hash;

    //* first sorting the array
    sort(arr.begin(), arr.end());

    while (j < arr.size()) {
        int diff = arr[j] - arr[i];

        if (diff == k) {
            hash[arr[i]] = arr[j];
            i++;
            j++;
        } else if (diff < k) {
            //* diff is too small, so by incrementing j, we're making
            //* i-j window larger.
            j++;
        } else {
            //* diff is too small, so by incrementing i, we're making
            //* i-j window smaller.
            i++;
        }

        //* the particular case is demanding that >>  i != j
        if (i == j) j++;
    }

    for (auto val : hash) {
        cout << val.first << " | " << val.second << "\n";
    }

    return hash.size();
}
//! TC:  N * log_N
//* sorting:  N * log_N
//* while loop is iterating till j reaches end  >>  N
//* ⇒ finally :  N * log_N
//! SC:  constant

int binarySearch(vector<int>& arr, int s, int e, int key) {
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) return mid;

        if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    //! ----------------------- BRUTE FORCE - nieve
    // vector<int> arr = {3, 1, 4, 1, 5};
    // int k = 2;
    //
    // int ans = kDiffPairInArray(arr, k);
    // cout << "Answer is: " << ans;

    //! ----------------------- 2 POINTER APPROACH
    // vector<int> arr = {3, 1, 4, 1, 5};
    // int k = 2;

    // arr = {3, 1, 4, 1, 5};
    // k = 0;

    // arr = {1, 1, 1, 1, 1};
    // k = 0;

    // int ans = twoPointerApproach(arr, k);
    // cout << "Answer is: " << ans;

    //! ----------------------- BINARY SEARCH
    // vector<int> arr = {3, 1, 4, 1, 5};
    // int k = 2;

    // //* here, we're reframing the equation from
    // //* arr[j] - arr[i] = k    >>    arr[j] = k + arr[i]
    // //* we're actually looping through all the elms where i is fixed &
    // //* then we're searching whether j, i.e. i+k where  j-i = k.
    // //* and so, we're using BINARY_SEARCH for searching

    // set<pair<int, int>> hash;

    // //* first sorting the array
    // sort(arr.begin(), arr.end());

    // for (int i = 0; i < arr.size() - 1; i++) {
    //
    //     int wantedJ = k + arr[i];

    //     int index = binarySearch(arr, i + 1, arr.size() - 1, wantedJ);
    //     if (index != -1) {
    //         hash.insert(hash.end(), {arr[i], index});
    //     }
    // }

    // for (auto val : hash) {
    //     cout << val.first << " | " << val.second << "\n";
    // }
    // cout << "Answer is: " << hash.size();
    //! TC:  N * log_N
    //* outer loop  >>  N
    //* inner loop of binary_search  >>  log_N
    //! SC:  constant
}