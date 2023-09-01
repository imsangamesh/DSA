//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//? ------------------------------------ is ARRAY SORTED
bool isArraySorted(int arr[], int& n, int i) {
    if (i == n - 1) return true;
    if (arr[i] > arr[i + 1]) return false;
    return isArraySorted(arr, n, i + 1);
}

//? ------------------------------------ BINARY SEARCH
int binarySearch(vector<int>& arr, int s, int e, int& key) {
    if (s > e) return -1;  //* coz it should be (s <= e)

    int mid = s + (e - s) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearch(arr, s, mid - 1, key);
    return binarySearch(arr, mid + 1, e, key);
}

//? ------------------------------------- SUB SEQUENCE of STRING
void sequenceOfString(string& str, string& finalOutput, int i,
                      vector<string>& store) {
    //
    // when reached the end, we've got a SUB_SEQUENCE so, push it.
    if (i == str.length()) {
        store.push_back(finalOutput);  //* storing
        return;
    }

    //? INCLUDING
    string newOutput = finalOutput + str[i];
    sequenceOfString(str, newOutput, i + 1, store);

    //? EXCLUDING
    sequenceOfString(str, finalOutput, i + 1, store);
}

int main() {
    //! -------------------------- is ARRAY SORTED
    // int arr[] = {10, 20, 30, 40, 50};
    // int n = 5, i = 0;

    // bool res = isArraySorted(arr, n, i);
    // cout << "Is sorted?: " << res;

    //! -------------------------- BINARY SEARCH
    // vector<int> arr = {10, 20, 30, 40, 50, 60};
    // int s = 0, e = arr.size() - 1;
    // int key = 10;

    // int res = binarySearch(arr, s, e, key);
    // cout << "Found at index: " << res;

    //! -------------------------- SUB SEQUENCE of STRING
    //! ////////// ////////// ////////// ////////// //////////
    //! //////////  important | INCLUDE | EXCLUDE   //////////
    //! ////////// ////////// ////////// ////////// //////////
    // string str = "abcde";
    // string finalOutput = "";
    // vector<string> store;
    // int i = 0, n = str.length();

    // sequenceOfString(str, finalOutput, i, store);
    // cout << endl;
    // for (auto val : store) {
    //     cout << val << ", ";
    // }
}