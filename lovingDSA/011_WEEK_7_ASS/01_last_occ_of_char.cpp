//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* --------------------------------------
//? 1. search from left to right
//? 2. search from right to left
//? 3. STL fn : strrchr()
//* --------------------------------------

//? 1. search from left to right
int leftToRight(vector<char>& arr, int i, char& target, int& ans) {
    if (i == arr.size()) return ans;
    if (arr[i] == target) ans = i;
    return leftToRight(arr, i + 1, target, ans);
}
//! TC:  N + 1  >>  N
//! SC:  N + 1  >>  N

//? 2. search from right to left
int rightToLeft(vector<char>& arr, int i, char& target) {
    if (i < 0) return -1;
    if (arr[i] == target) return i;
    return rightToLeft(arr, i - 1, target);
}
//! TC:  N + 1  >>  N
//! SC:  N + 1  >>  N

int main() {
    vector<char> arr = {'a', 'b', 'c', 'd', 'd', 'e', 'd', 'g'};
    char target = 'd';
    int ans = -1;

    // int res = leftToRight(arr, 0, target, ans);
    // cout << "Answer is: " << res;
    int res = rightToLeft(arr, arr.size() - 1, target);
    cout << "Answer is: " << res;
}