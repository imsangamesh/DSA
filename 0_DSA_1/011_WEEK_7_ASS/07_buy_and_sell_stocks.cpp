#include <iostream>
#include <vector>
using namespace std;

void buyAndSellForMaxProfit(vector<int>& arr, int& minPrice, int& maxProfit,
                            int i = 0) {
    if (i == arr.size()) return;

    if (arr[i] < minPrice) minPrice = arr[i];
    int todaysProfit = arr[i] - minPrice;
    if (todaysProfit > maxProfit) maxProfit = todaysProfit;

    buyAndSellForMaxProfit(arr, minPrice, maxProfit, i + 1);
}
/*
* TC:  n+1  >>  n
! rucursing for n iterations.
* SC:  n+1  >>  n
*/

int main() {
    vector<int> arr{7, 1, 5, 3, 6, 4};
    int minPrice = 0, maxProfit = 0;
    //
    buyAndSellForMaxProfit(arr, minPrice, maxProfit);
    cout << "Answer is: " << maxProfit;
    cout << "Answer is: " << minPrice;
}