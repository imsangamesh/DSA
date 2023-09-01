//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

//! /////// /////// /////// /////// /////// ///////  MERGE SORT
//? 1. find mid
//? 2. break into 2 halves
//? 3. sort 2 halves  ( when only 1 elm is left )
//? 4. merge

void merge(int* arr, int s, int e) {
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // creating arrays
    int* left = new int[len1];
    int* right = new int[len2];

    // copying values to 'left'
    int k = s;  //* coz, 's' doesn't always start from 0
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }

    // copying values to 'rigth'
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }

    //? MERGE logic
    int li = 0, ri = 0;
    int i = s;

    // copying whichever is smaller
    while (li < len1 && ri < len2) {
        if (left[li] < right[ri]) {
            arr[i++] = left[li++];
        } else {
            arr[i++] = right[ri++];
        }
    }

    // copy leftover elms from left_array
    while (li < len1) {
        arr[i++] = left[li++];
    }

    // copy leftover elms from right_array
    while (ri < len2) {
        arr[i++] = right[ri++];
    }

    // TODO: delete 'left' & 'right' arrays
}

void mergeSort(int* arr, int s, int e) {
    // base case
    if (s >= e) return;
    // if  s == e  ->  single elm
    // if  s > e   ->  invalid array

    int mid = s + (e - s) / 2;

    //* sort left part
    mergeSort(arr, s, mid);

    //* sort right part
    mergeSort(arr, mid + 1, e);

    // actually, there is no sorting!
    // only dividing till we've only 1 elm, which is considered as sorted

    //* now MERGE 2 sorted arrays
    merge(arr, s, e);
}

//! TC:  0
//* to reach base_case :  k1
//* left_call for merge_sort :  TC( n/2 )
//* right_call for merge_sort :  TC( n/2 )
//* merge_fun :  n * k  :: approx_val due to following reasons
//      1. copy left_vals
//      2. copy rigth_vals
//      3. compare and place elms
//      4. place left_remaining elms
//      5. place right_remaining elms
//*  TC(n)     :  k1 +  TC( n/2 ) + TC( n/2 )  + n*k
//*            :  k1 +  2 TC( n/2 ) +  n*k
//*            :  2 TC( n/2 ) +  n*k  ( neglet_k1 )
//*  TC(n/2)   :  2 TC( n/4 ) +  n/2 * k  ( substitute n by n/2 )
//*  TC(n/4)   :  2 TC( n/8 ) +  n/4 * k  ( substitute n by n/2 )
//*                 .             .
//*                 .             .
//*                 .             .
//*                 .             .
//*   TC(1)    :  K  ( we can sort array with 1 elm in k time )
//?   others will be eliminated by each others from LHS & RHS
//* -----------------------------------------
//*   TC(n)    :  (a-1) * n * k
//?   in a-1, -1 is coz, n*k is not there for last line, i.e. TC(1)
//?   'a' is log_n  :: ( base_2 ) :: by binary_search
//*
//*   TC(n)  =  ( log_n - 1 ) * n * k  +  k
//*   TC(n)  =  k * n * log_n  - n * k     ( neglet k )
//*   TC(n)  =  k * n * log_n    ( neglet  n*k )
//*
//*   TC(n)  =  n * log_n    ( neglet k )
//*
//! SC:  1

int main() {
    int arr[] = {4, 5, 13, 2, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0, e = n - 1;

    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}