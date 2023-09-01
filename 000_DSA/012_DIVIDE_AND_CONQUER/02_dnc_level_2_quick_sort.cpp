//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

//! /////// /////// /////// /////// /////// /////// ///////  QUICK SORT
//? 1. Partition logic
//*     1. choose pivot index
//*     2. count no of nums < pivotELm
//*     3. swap ( arr[pivotIndex] , arr[s + count] )
//*     4. make sure, left_elms < pivotElm < right_elms

//? 2. Recursion logic

int partition(int* arr, int s, int e) {
    //? step1: choose pivot Element
    int pivotIndex = s;
    int pivotElement = arr[s];

    //? step2: find correct_pos for pivot elm & place it there
    // counting no of nums smaller than pivotElm
    int count = 0;
    for (int i = s + 1; i <= e; i++) {  //!  N
        if (arr[i] <= pivotElement) count++;
    }

    // the time, I'm out of loop, I'll be having correct_pivot_index.
    int correctIndex = s + count;
    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;  // updating 'pivot'

    //? step3: put smallers on left & biggers on right
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {  //!  N/2  >>  N
        //* below 2 while_loops are to find wrong_elm
        //* they stop, whenever they find, wrong_elm
        while (arr[i] <= pivotElement) i++;
        while (arr[j] < pivotElement) j--;

        // there may be 2 cases:
        // 1. there may be elements to swap
        // 2. no need to swap
        if (i < pivotIndex && j > pivotIndex) swap(arr[i], arr[j]);
    }

    return pivotIndex;
}

void quickSort(int* arr, int s, int e) {
    //* base case
    if (s >= e) return;

    //* partition logic
    int p = partition(arr, s, e);

    //* recursive left_logic
    quickSort(arr, s, p - 1);

    //* recursive right_logic
    quickSort(arr, p + 1, e);
}
//! TC:  N * log_N  (avg case)  |  N * N  (worst_case)
//! SC:  1

//! /////// /////// /////// /////// /////// Permutation of Strings
void printPermutation(string& str, int i) {
    // base case
    if (i >= str.length()) {
        cout << str << " ";
        return;
    }

    for (int j = i; j < str.length(); j++) {
        //? swapping
        swap(str[i], str[j]);

        //? recursion
        printPermutation(str, i + 1);

        //? backtracking
        // to recreate the original string
        swap(str[i], str[j]);
    }
}

//* /////// /////// /////// /////// /////// /////// /////// /////// ///////
//? /////// /////// /////// /////// /////// /////// /////// /////// ///////
//! /////// /////// /////// /////// /////// /////// /////// /////// ///////

int main() {
    //! /////// /////// /////// /////// /////// ///////  QUICK SORT
    int arr[] = {4, 1, 3, 4, 20, 10, 100, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0, e = n - 1;

    quickSort(arr, s, e);

    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    //! /////// /////// /////// /////// /////// ///////  BACK-TRACKING
    //! /////// /////// /////// /////// Permutation of Strings
    // every character wants to be at all the avail places
    string str = "abc";
    printPermutation(str, 0);
    cout << "\n\n";
}