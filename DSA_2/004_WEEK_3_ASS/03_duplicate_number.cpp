/*
 * LEET CODE - DONE
 * not possible to solve it IN_PLACE coz, it needs binary search
 * concept.
 * - negative marking
 * -
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//? ------------------------ METHOD 1 - nieve
int sortAndTrace(vector<int> arr) {
    /*
    ? it is not solving IN_PLACE
    !TC:  n
    * it is traversing the array one time
    !SC:  constant
    */
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] == arr[i + 1]) return arr[i];
    }
    return -1;
}

int negativeMarking(vector<int> arr) {
    /*
    ? it is still not solving IN_PLACE
    !TC:  n
    * it is traversing the array one time
    !SC:  constant
    */
    for (int i = 0; i < arr.size(); i++) {
        int index = abs(arr[i]) - 1;

        if (arr[index] < 0) {
            return abs(arr[index]);
        } else {
            arr[index] *= -1;
        }
    }
    return -1;
}

int sendingNumToTheirPosition(vector<int> arr) {
    /*
    ? it is still not solving IN_PLACE
    !TC:  n
    * it is traversing the array one time
    !SC:  constant
    */
    while (arr[arr[0]] != arr[0]) {
        swap(arr[0], arr[arr[0]]);
    }
    return arr[0];
}

int main() {
    vector<int> arr{1, 2, 3, 1, 4};
    //
    // int ans = sortAndTrace(arr);
    int ans = negativeMarking(arr);
    cout << "Answer is: " << ans;
}