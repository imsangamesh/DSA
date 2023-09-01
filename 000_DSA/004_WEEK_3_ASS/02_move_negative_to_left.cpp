//* LEETCODE
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

void moveAllNegativeToLeft(vector<int>& arr) {
    //? DUTCH NATIONAL FLAG algo
    //? 2 pointer approach
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        if (arr[s] < 0) {
            s++;
        } else {
            swap(arr[s], arr[e]);
            e--;
        }
    }
}

int main() {
    vector<int> arr = {-1, 3, 3, 6, 9, -1, -10, 10, -2, 0, -2, 2, -1};
    //
    moveAllNegativeToLeft(arr);
    printVector(arr);
}