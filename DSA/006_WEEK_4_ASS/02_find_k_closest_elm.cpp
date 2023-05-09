//* LEET | 658. Find K Closest Elements
//* ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

//! -------------------------------- 2 POINTER APPROACH
vector<int> TwoPointerApproach(vector<int>& arr, int k, int x) {
    //* here, first take  s & e  as extreme pointers.
    //* then create a virtual 'differences' table so that
    //* depending on that, we can narrow our s-e window.
    //! we don't want the no.s with larger differences.
    //! soo whose difference is higher, shorten the window on that side,
    //! so that we exclude the no. which has higher difference.
    //* by doing this, until the diff b/w  e & s < k, we get the ans.
    int s = 0, e = arr.size() - 1;

    while (e - s >= k) {
        if (x - arr[s] > arr[e] - x) {
            s++;
        } else {
            e--;
        }
    }

    //* best method to create array
    //* we're taking  arr.begin()+e+1  >>  +1  is coz, it isn't considered.
    return vector<int>(arr.begin() + s, arr.begin() + e + 1);
}
//! TC:  N-k
//* we're looping till we reach the window of len k
//* we didn't loop inside the window of len > k. only outside of it  >>  N-k
//! SC:  constant

int lowerBound(vector<int>& arr, int target) {
    int s = 0, e = arr.size() - 1;

    int ans = e;
    //* coz, if the last_elm is smaller than target, then we're getting
    //* -1 as ans--which is wrong as the nearest elm may be end-1.
    //* so initialise with e.

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

//! -------------------------------- BINARY SEARCH
vector<int> binarySearchApproach(vector<int>& arr, int k, int x) {
    int e = lowerBound(arr, x);
    int s = e - 1;

    while (k--) {
        if (s < 0) {
            // when there lower_bound is at 'start'
            e++;
        } else if (e >= arr.size()) {
            // when there lower_bound is at 'end'
            s--;
        } else if (x - arr[s] <= arr[e] - x) {
            s--;
        } else {
            e++;
        }
    }
    //* best method to create array
    //* we're taking  arr.begin()+e+1  >>  +1  is coz, it isn't considered.
    //! but here, in this case, we want one less elm on both sides, soo
    return vector<int>(arr.begin() + s + 1, arr.begin() + e);
}
//! TC:  log_n + k
//* log_n : for binary_searching the array
//* k     : loop to get k nums.
//! SC:  constant

int main() {
    //! -------------------------------- 2 POINTER APPROACH
    //! temp problem for INTIUTION devpt
    // vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    // int k = 4, x = 35;
    //
    // vector<int> ans = TwoPointerApproach(arr, k, x);
    // printVector(ans);

    //! -------------------------------- BINARY SEARCH
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4, x = 35;
    //
    vector<int> ans = binarySearchApproach(arr, k, x);
    printVector(ans);
}