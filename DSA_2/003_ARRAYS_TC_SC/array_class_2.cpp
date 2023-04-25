#include <limits.h>

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int main() {
    //! .................................. SORT 0s & 1s
    vector<int> arr{0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1};
    int s = 0, e = arr.size() - 1;

    /*
    !TC:  max(no_of_0, no_of_1)
    * in above case, we're seeing that loop is running
    * 11 times for 12 no_of_1s
    !SC:  0
    */

    //? ------- METHOD 1
    //! ------- DUTCH NATIONAL FLAG METHOD
    while (s <= e) {
        if (arr[s] == 0) {
            s++;
        } else if (arr[e] == 1) {
            e--;
        } else {
            swap(arr[s], arr[e]);
        }
    }

    //? ------- METHOD 2
    // while (s < e) {
    //     if (arr[s] == 1 && arr[e] == 0) {
    //         swap(arr[s], arr[e]);
    //         s++;
    //         e--;
    //     } else if (arr[s] == 0) {
    //         s++;
    //     } else if (arr[e] == 1) {
    //         e--;
    //     }
    // }

    printVector(arr);
}
