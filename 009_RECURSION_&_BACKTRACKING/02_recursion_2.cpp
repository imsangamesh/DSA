#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    // if (n == 0 || n == 1) return 1;
    if (n == 1 || n == 2) return n;
    /*
     * now if ya know, value of climbStairs(2) = 2,
     * then you can put them in the BASE_CASE
     */
    return climbStairs(n - 1) + climbStairs(n - 2);
}

void printArray(vector<int> arr, int n, int index) {
    //? kaha rukna hai, bolo
    if (index == n) return;  //* BC

    //? eka case solve kardo
    cout << arr[index] << " ";  //* PROC

    //? baki ka recursion pe chod do
    printArray(arr, n, index + 1);  //* RR
}

//? using RETURN not PASS_BY_REFERENCE
int findMaxInArray_1(vector<int> arr, int n, int i, int max) {
    if (i == n) return max;
    if (arr[i] > max) max = arr[i];
    return findMaxInArray_1(arr, n, i + 1, max);
}

//? using PASS_BY_REFERENCE not RETURN
void findMaxInArray_2(vector<int> arr, int n, int i, int& max) {
    if (i == n) return;
    if (arr[i] > max) max = arr[i];
    findMaxInArray_2(arr, n, i + 1, max);
}

//? using PASS_BY_REFERENCE not RETURN
void findMinInArray(vector<int> arr, int n, int i, int& min) {
    if (i == n) return;
    if (arr[i] < min) min = arr[i];
    findMinInArray(arr, n, i + 1, min);
}

bool searchKey(string& str, char& ch, int& i) {
    //* key not found --> return false
    if (i == str.length()) return false;

    //* check the first character
    if (str[i] == ch) return true;

    //* leave the rest to recursion
    int newI = i + 1;
    return searchKey(str, ch, newI);
}

int findKeyIndex(string& str, char& ch, int& i) {
    if (i == str.length()) return -1;

    if (str[i] == ch) return i;

    int newI = i + 1;
    return findKeyIndex(str, ch, newI);
}

void storeAllIndexesOfElm(string& str, char& ch, int& i, vector<int>& arr) {
    if (i == str.length()) return;

    if (str[i] == ch) arr.push_back(i);

    int newI = i + 1;
    return storeAllIndexesOfElm(str, ch, newI, arr);
}

void printDigits(int n) {
    if (n == 0) return;
    printDigits(n / 10);
    cout << n % 10 << " ";
}

int main() {
    //! -------------------------- CLIMBING STAIRS
    // int res = climbStairs(5);
    // cout << "No of ways to climb 5 steps: " << res;

    //! -------------------------- PRINTING from ARRAY
    // vector<int> arr = {10, 20, 30, 40, 50};
    // int index = 0, n = arr.size();

    // printArray(arr, n, index);

    //! -------------------------- FIND MAX in ARRAY
    // vector<int> arr = {10, 20, 80, 100, 30, 40, 50};
    // int i = 0, n = arr.size();

    // //? using RETURN not PASS_BY_REFERENCE
    // int res = findMaxInArray_1(arr, n, i, INT_MIN);
    // cout << "Maximum is: " << res;

    // //? using PASS_BY_REFERENCE not RETURN
    // int max = INT_MIN;
    // findMaxInArray_2(arr, n, i, max);
    // cout << "Maximum is: " << max;

    //! -------------------------- FIND MIN in ARRAY
    // vector<int> arr = {10, 20, 80, 100, 30, 40, 50};
    // int i = 0, n = arr.size();
    // int min = INT_MAX;

    // findMinInArray(arr, n, i, min);
    // cout << "Minimum is: " << min;

    //! -------------------------- SEARCH ELEMENT
    // string str = "SaninePinklin";
    // int i = 0, n = str.length();
    // char key = 'l';

    // bool res = searchKey(str, key, i);
    // cout << "Key found?: " << res;

    //! -------------------------- SEARCH INDEX of ELM
    // string str = "SaninePinklin";
    // int i = 0, n = str.length();
    // char key = 'l';

    // int res = findKeyIndex(str, key, i);
    // cout << "Key index?: " << res;

    //! -------------------------- STORE all INDEXES
    // string str = "SaninePinklin";
    // vector<int> arr;
    // int i = 0, n = str.length();
    // char key = 'i';

    // storeAllIndexesOfElm(str, key, i, arr);
    // cout << "Indexes are:\n";
    // for (auto&& val : arr) {
    //     cout << val << " ";
    // }

    //! -------------------------- PRINT DIGITS of NUM
    int num = 1024;

    // int num = 0647;
    /*
    ? when an integer starts with 0, it is interpreted as octal no.
    ? soo, octal value of 0647 is 423.
    */

    printDigits(num);
}