//* 1155. Number of Dice Rolls With Target Sum
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

int numRollsToTarget(int n, int k, int target) {
    // base conditions
    if (target < 0) return 0;             //* couldn't reach target
    if (n == 0 && target != 0) return 0;  //* no dices, but target unreached
    if (n != 0 && target == 0) return 0;  //* dices left, but target reached
    if (n == 0 && target == 0) return 1;  //? no dices, target reached

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}
//! TC:  K ^ N
//! SC:  N   ( max_depth )

int main() {
    // int ans =
    // cout << "\nAnswer is: " << ans << "\n\n";
}