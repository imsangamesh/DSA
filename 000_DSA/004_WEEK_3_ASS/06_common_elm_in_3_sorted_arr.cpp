//* GFG. COMMON ELEMENTS
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void printVector(set<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

void commonElementIn3SortedArray() {
    vector<int> arr = {1, 5, 10, 20, 40, 80};
    vector<int> brr = {6, 7, 20, 80, 100};
    vector<int> crr = {3, 4, 15, 20, 30, 70, 80, 120};

    arr = {30, 30, 30, 100, 1000};
    brr = {30, 30, 30, 100, 1000};
    crr = {30, 30, 30, 100, 1000};

    int a = 0, b = 0, c = 0;
    set<int> ans;

    while (a < arr.size() || b < brr.size() || c < crr.size()) {
        if (arr[a] == brr[b] && brr[b] == crr[c]) {
            ans.insert(arr[a]);
            a++;
            b++;
            c++;
        } else if (arr[a] < brr[b]) {
            a++;
        } else if (brr[b] < crr[c]) {
            b++;
        } else {
            c++;
        }
    }
    printVector(ans);
}

int main() {
    //
    commonElementIn3SortedArray();
}