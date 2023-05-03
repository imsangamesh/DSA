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

void sortColors(vector<int>& arr) {
    //? In place approach | 3 pointer approach
    int b = 0, a = 0, c = arr.size() - 1;

    while (b <= c) {
        if (arr[b] == 0) {
            swap(arr[b], arr[a]);
            b++;
            a++;
        } else if (arr[b] == 2) {
            swap(arr[b], arr[c]);
            c--;
        } else {
            b++;
        }
    }
}

int main() {
    vector<int> arr = {2, 2, 0, 1, 1, 0, 2, 1, 0};
    //
    sortColors(arr);
    printVector(arr);
}