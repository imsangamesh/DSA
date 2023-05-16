//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//? -------------------------- CLIMBING STAIRS
int climbStairs(int n) {  //! 2 ^ N
    //* coz, value of climbStairs(2) = 2,
    //* then you can put them in the BASE_CASE
    if (n == 1 || n == 2) return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

//? -------------------------- PRINTING from ARRAY
void printArray(vector<int>& arr, int n, int i) {
    if (i >= n) return;
    cout << arr[i] << " ";
    printArray(arr, n, i + 1);
}

//? -------------------------- FIND MAX in ARRAY
void findMaxInArray(vector<int>& arr, int n, int i, int& maxi) {
    if (i == n) return;
    if (arr[i] > maxi) maxi = arr[i];
    findMaxInArray(arr, n, i + 1, maxi);
}

//? -------------------------- SEARCH ELEMENT
bool searchKey(string& str, char& key, int i) {
    // it has reached end, yet key not found.
    if (i == str.length()) return false;
    if (str[i] == key) return true;
    return searchKey(str, key, i + 1);
}

//? -------------------------- SEARCH INDEX of ELM
int findKeyIndex(string& str, char& key, int i) {
    if (i == str.length()) return -1;
    if (str[i] == key) return i;
    cout << " Hello";
    return findKeyIndex(str, key, i + 1);
}

//? -------------------------- STORE all INDEXES
void storeAllIndexesOfKey(string& str, char& key, int i, vector<int>& arr) {
    if (i == str.length()) return;
    if (str[i] == key) arr.push_back(i);
    storeAllIndexesOfKey(str, key, i + 1, arr);
}

//? -------------------------- PRINT DIGITS of NUM
void printDigits(int n) {
    if (n == 0) return;
    printDigits(n / 10);
    cout << n % 10 << " ";
}

int main() {
    //! -------------------------- CLIMBING STAIRS
    // int res = climbStairs(20);
    // cout << "No of ways to climb 5 steps: " << res;

    //! -------------------------- PRINTING from ARRAY
    // vector<int> arr = {10, 20, 30, 40, 50};
    // int index = 0, n = arr.size();

    // printArray(arr, n, index);

    //! -------------------------- FIND MAX in ARRAY
    // //? using PASS_BY_REFERENCE not RETURN
    // vector<int> arr = {10, 20, 80, 100, 30, 40, 50};
    // int i = 0, n = arr.size();

    // int maxi = INT_MIN;
    // findMaxInArray(arr, n, i, maxi);
    // cout << "Maximum is: " << maxi;

    //! -------------------------- SEARCH ELEMENT
    // string str = "SaninePinklin";
    // int i = 0, n = str.length();
    // char key = 'z';

    // bool res = searchKey(str, key, i);
    // cout << "Key found?: " << res;

    //! -------------------------- SEARCH INDEX of ELM
    // string str = "SaninePinklin";
    // int i = 0;
    // char key = 'l';

    // int res = findKeyIndex(str, key, i);
    // cout << "Key index?: " << res;

    //! -------------------------- STORE all INDEXES
    // string str = "SaninePinklin";
    // vector<int> arr;
    // int i = 0;
    // char key = 'i';

    // storeAllIndexesOfKey(str, key, i, arr);
    // cout << "Indexes are:\n";
    // for (auto&& val : arr) cout << val << " ";

    //! -------------------------- PRINT DIGITS of NUM
    // int num = 12345;
    // //? int num = 0647;
    // //* when an integer starts with 0, it is interpreted as octal no.
    // //* soo, octal representation of 0647 is 423.
    // printDigits(num);
}