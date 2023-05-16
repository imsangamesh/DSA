//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

void printSubArrayUtil(vector<int>& nums, int s, int e) {
    if (e == nums.size()) return;

    for (int i = s; i <= e; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    printSubArrayUtil(nums, s, e + 1);
}

void printSubArray(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        printSubArrayUtil(nums, i, i);
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
    vector<int> nums = {1, 2, 3, 4, 5};

    printSubArray(nums);
}