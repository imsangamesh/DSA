#include <iostream>
#include <vector>
using namespace std;

//! FIND MIN NO of COINS REQD to make TARGET_SUM
int minNoOfCoins(vector<int>& arr, int target) {
    if (target == 0) return 0;
    //* to create 0 as target, wkt we need only 0 coins

    if (target < 0) return INT_MAX;
    /*
     ? why returning INT_MAX
     * when target < 0, we don't want to modify the current 'mini'
     * so we're returning INT_MAX
     * and in the previous stack, we'll do min(ans, 'mini')
     * there we will get 'mini', coz ans = INT_MAX
     */

    //? let's solve 1 case
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        int ans = minNoOfCoins(arr, target - arr[i]);
        if (ans != INT_MAX) mini = min(ans + 1, mini);
    }
    /*
     ? why adding 1 to ans
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

    return mini;
}

//! MAXIMUM NO of SEGMENTS to create LONG ROD
int maxNoOfSegments(int n, int x, int y, int z) {
    if (n == 0) return 0;

    int maxi = INT_MIN;
    //? int maxi = 0;
    //* coz, when we have no possibilities, we are getting answer as INT_MIN
    //* if we take maxi = 0, we'll get answer as 0.

    if (n - x >= 0) {
        int ans = maxNoOfSegments(n - x, x, y, z);
        maxi = max(ans + 1, maxi);
    }
    if (n - y >= 0) {
        int ans = maxNoOfSegments(n - y, x, y, z);
        maxi = max(ans + 1, maxi);
    }
    if (n - z >= 0) {
        int ans = maxNoOfSegments(n - z, x, y, z);
        maxi = max(ans + 1, maxi);
    }

    return maxi;
}

//! MAX SUM of NOT_ADJACENT ELMS
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

    //? INCLUDE CASE
    maxSumOfNonAdjacentElm(arr, i + 2, sum + arr[i], maxi);

    //? EXCLUDE CASE
    maxSumOfNonAdjacentElm(arr, i + 1, sum, maxi);
}

int main() {
    //! FIND MIN NO of COINS REQD to make TARGET_SUM
    // vector<int> arr{1, 2, 3};
    // int target = 7;

    // int ans = minNoOfCoins(arr, target);
    // cout << "Min coins needed: " << ans << endl;

    //! CUT INTO SEGMENTS
    //! MAXIMUM NO of SEGMENTS to create LONG ROD
    // int n = 7;
    // int x = 5, y = 2, z = 2;

    // int ans = maxNoOfSegments(n, x, y, z);
    // cout << "Max no of Segments: " << ans << endl;

    //! MAX SUM of NOT_ADJACENT ELMS
    vector<int> arr{2, 1, 4, 9};
    int i = 0, sum = 0;
    int maxi = INT_MIN;

    maxSumOfNonAdjacentElm(arr, i, sum, maxi);
    cout << "Max sum is: " << maxi << endl;
}