#include <iostream>
#include <vector>
using namespace std;

void printAllSubArrayUtil(vector<int>& arr, int s, int e) {
    if (e == arr.size()) return;

    for (int i = s; i <= e; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    printAllSubArrayUtil(arr, s, e + 1);
}

void printAllSubArrays(vector<int>& arr) {
    for (int start = 0; start < arr.size(); start++) {
        printAllSubArrayUtil(arr, start, start);
    }
}

/*
* TC: n*n
! no of recursions: n
! no of for-loop iterations: n
* SC: n+2  >>  n
! here we've 2 functions.
! 1st 'print' fn is pushed in stack
! then n times 'util' fn is called.
! and for every 'util' call, there would be n stacks.
! and after each 'util' fn, that stack is destroyed except 'print' fn in stack
*/

int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    //
    printAllSubArrays(arr);
}