#include <iostream>
#include <vector>
using namespace std;

int robAdjacentHouse(vector<int>& arr, int i) {
    if (i >= arr.size()) return 0;

    //? INCLUDE
    int rob1 = arr[i] + robAdjacentHouse(arr, i + 2);
    //? EXCLUDE
    int rob2 = robAdjacentHouse(arr, i + 1);

    return max(rob1, rob2);
}
/*
* TC:  2^n
! we are calling 2 calls for each call, same as fibonacci
* SC:  n
! our maximum depth we are filling is in order_of_n
*/

int main() {
    vector<int> arr{5, 2, 1, 4};
    //
    int ans = robAdjacentHouse(arr, 0);
    cout << "Answer is: " << ans;
}