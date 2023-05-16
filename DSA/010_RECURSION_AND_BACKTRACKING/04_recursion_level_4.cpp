//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//? //////// //////// //////// //////// //////// //////// //////// ////////
//? ------------------------------------------------------- MIN NO OF COINS
int minNoOfCoins(vector<int>& arr, int target) {
    if (target == 0) return 0;
    //* to create 0 as target, we need 0 coins

    //? solve 1 case
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        //
        //* here you're avoiding the -ve answers
        if (target - arr[i] >= 0) {
            int ans = minNoOfCoins(arr, target - arr[i]);
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

// int minNoOfCoins(vector<int>& arr, int target) {
//     if (target == 0) return 0;
//     //* to create 0 as target, wkt we need only 0 coins

//     if (target < 0) return INT_MAX;
//     //? why returning INT_MAX
//     //* when target < 0, we don't want to modify the current 'mini'
//     //* so we're returning INT_MAX
//     //* and in the previous stack, we'll do min(ans + 1, 'mini')
//     //* there we will get 'mini', coz 'ans' we got will be INT_MAX

//     //? solve 1 case
//     int mini = INT_MAX;
//     for (int i = 0; i < arr.size(); i++) {
//         int ans = minNoOfCoins(arr, target - arr[i]);
//         if (ans != INT_MAX) mini = min(mini, ans + 1);
//     }
//     return mini;
// }
/*
? why adding 1 to ans in COIN's PROBLEM -----------------------------
* if I received, INT_MAX as 'ans' that is invalid
* so I'm not doing anything.
* We'll modify 'ans' only when we don't receive invalid answer.
* Now suppose we receive valid answer, then we've to accept it.
* so we have to modify the answer.
*
? target = 5, coins = [1, 2]
? suppose we are getting a 'ans' = 2 as the minimum no of coins reqd
? to create 4 rupees then to make it 5 rupees, ABSO-FUCKING-LUTELY
? we need another 1 coin to sum it up to 5 rupees.
? sooo we're adding 1 to the answer.
*
* or else I could remove the BASE_CASE for invalid 'ans' by checking
* whether it yields the INVALID_ANS i.e,
! if(target - arr[i] >= 0)
*
* //? let's solve 1 case
* int mini = INT_MAX;
* for (int i = 0; i < arr.size(); i++) {
*     if (target - arr[i] >= 0) {
*          int ans = minNoOfCoins(arr, target - arr[i]);
*          mini = min(ans + 1, mini);
*     }
* }
*/

//? //////// //////// //////// //////// //////// //////// //////// ////////
//? ------------------------------------------------ MAXIMUM NO of SEGMENTS
int maxNoOfSegments(int len, int x, int y, int z) {
    //* to create segment of len 0, we need only 0 length
    if (len == 0) return 0;

    int maxi = INT_MIN;
    if (len - x >= 0) {
        int ans = maxNoOfSegments(len - x, x, y, z) + 1;
        maxi = max(maxi, ans);
    }

    if (len - y >= 0) {
        int ans = maxNoOfSegments(len - y, x, y, z) + 1;
        maxi = max(maxi, ans);
    }

    if (len - z >= 0) {
        int ans = maxNoOfSegments(len - z, x, y, z) + 1;
        maxi = max(maxi, ans);
    }

    return maxi;
}

//!
//? //////// //////// //////// //////// //////// //////// //////// ////////
//? ------------------------------------------ MAX SUM of NOT_ADJACENT ELMS
void maxSumOfNonAdjacentElm(vector<int>& arr, int i, int sum, int& maxi) {
    if (i >= arr.size()) {
        maxi = max(sum, maxi);
        return;
    }
    /*
     ? why updating maxi in BASE_CASE
     * we are taking 'sum' of all tree paths
     * when we reach the leaf-node i.e, the dead-end
     * we are simply modifying the maxi.
     */
}

int main() {
    //! find MIN NO of COINS reqd to make TARGET_SUM
    // vector<int> arr{1, 2, 3};
    // int target = 7;

    // int ans = minNoOfCoins(arr, target);
    // cout << "Min coins needed: " << ans << endl;

    //! CUT INTO SEGMENTS
    //! MAXIMUM NO of SEGMENTS to create LONG ROD
    int n = 7;
    int x = 5, y = 2, z = 2;

    int ans = maxNoOfSegments(n, x, y, z);
    cout << "Max no of Segments: " << ans << endl;
}