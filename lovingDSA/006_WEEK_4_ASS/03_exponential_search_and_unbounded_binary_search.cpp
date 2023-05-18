//*
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// also called as:
//! EXPONENTIAL SEARCH
//! GALLOPING SEARCH
//! STRAZIK SEARCH

int binarySearch(vector<int> arr, int s, int e, int target) {
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target) return mid;

        if (arr[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

//! -------------------------------- EXPONENTIAL SEARCH
int exponentialSearch(vector<int> arr, int target) {
    //* we're checking for 0 term, coz we need i to start from 1, coz
    //* when we multiply i by 2 to jump to next step, if i==0, then everytime
    //* 2*i = 0, and it doesn't move further.
    if (arr[0] == target) return 0;
    int i = 1;
    int n = arr.size();

    while (arr[i] < target) {
        i = i << 1;
    }
    cout << "i: " << i << "\n";

    //* we're taking min, coz there may be case, where i exceeds the last_index.
    return binarySearch(arr, i >> 1, min(i, n - 1), target);
}
//! TC:  log( 2^(log(m) - 1) )
//? total size of sub_array
//* m is num till where i goes & stops. it depends on the target.
//* if you want to find 13 in array, then i goes till index 16.
//* soo it takes just 4 steps to reach 16. how? >> 2 * 2 * 2 * 2 >> 4 times.
//* soo log(16) = 4.  >>>  log_m
//*
//* suppose, range is from  8 to 16
//* 8  >>  2^3  |  16  >> 2^4
//* but  3 >> log(m-1)  |  4 >> log(m)
//* total size = 2^log(m) - 2^log(m-1)
//* => 2^log(m) - 2^log(m) * 2^(-1)
//* => 2^log(m) ( 1 - 2^(-1) )
//* => 2^log(m) ( 1 - 1/2 )
//* => 2^log(m) * 1/2
//* => 2^log(m) / 2
//* => 2^( log(m) - 1 )
//*
//? Binary search
//* TC is log(n), but here n is 2^( log(m) - 1 )
//* sooo ans.
//! SC:  constant
//! APPLICATIONS
//* 1. search in ♾️ array or unbounded array (with no n)
//* 2. better than binary_search

int unboundedSearch(vector<int> arr, int target) {
    int i = 0, j = 1;

    while (arr[j] < target) {
        i = j;
        j *= 2;  // j = j << 1;
    }

    return binarySearch(arr, i, j, target);
}

int main() {
    //! -------------------------------- EXPONENTIAL SEARCH
    // vector<int> arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    // int target = 70;
    //
    // int ans = exponentialSearch(arr, target);
    // cout << "Answer is: " << ans;

    //! -------------------------------- UNBOUNDED ARR SEARCH
    //? METHOD 1 - BRUTE_FORCE (with no n)
    //* run the loop till we find the just_larger_num and stop there

    // vector<int> arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    // int target = 13;
    // int ans = -1;

    // int i = 0;
    // while (true) {
    //     if (arr[i] > target) break;
    //     if (arr[i] == target) ans = i;
    //     i++;
    // }
    // cout << "Answer is: " << ans;

    //? METHOD 2 - Two POINTER APPROACH (with no n)
    //* keep 2 pointers at 0 & 1. and traverse array only till (arr[j] < target)
    //* while traversing do  i=j & j*=2.
    //* after stopping apply binary_search to find ans.

    // vector<int> arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    // int target = 13;

    // int ans = unboundedSearch(arr, target);
    // cout << "Answer is: " << ans;
}