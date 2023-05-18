//* 121. Best Time to Buy and Sell Stock
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* ------------------------------------------- ITERATIVE APPROACH
int maxProfitIterative(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minPrice) minPrice = prices[i];

        int todaysProfit = prices[i] - minPrice;
        if (todaysProfit > maxProfit) maxProfit = todaysProfit;
    }

    return maxProfit;
}
//* -------------------------------------------

int maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
    if (i == prices.size()) return maxProfit;

    //* checking if today's stock is minimum
    if (prices[i] < minPrice) minPrice = prices[i];

    //* selling our already present stock 'today', & checking whether
    //* we could get greater profit than already got profit.
    int todaysProfit = prices[i] - minPrice;
    if (todaysProfit > maxProfit) maxProfit = todaysProfit;

    return maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}
//! TC:  N
//* it is looping till it reaches the end of array.
//! SC:  N

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    maxProfitFinder(prices, 0, minPrice, maxProfit);

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfitIterative(prices);
    cout << "Answer is: " << ans;
}