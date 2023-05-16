//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

int robHelper(vector<int>& nums, int i) {
    if (i >= nums.size()) return 0;

    //? INCLUDE
    int robAmt1 = nums[i] + robHelper(nums, i + 2);
    //? EXCLUDE
    int robAmt2 = robHelper(nums, i + 1);
    cout << "------------\n";

    return max(robAmt1, robAmt2);
}
//! TC:  2 ^ N
//* same as Fibonacci
//! SC:  N

int rob(vector<int>& nums) {
    //
    return robHelper(nums, 0);
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    int ans = rob(nums);
    cout << "Answer is: " << ans;
}