//* 983. Minimum Cost For Tickets
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

int mincostTicketsHelper(vector<int>& days, vector<int>& costs, int i) {
    // base
    if (i >= days.size()) return 0;

    //* 1 day Pass ---------------------------
    int cost1 = costs[0] + mincostTicketsHelper(days, costs, i + 1);

    //* 7 days Pass --------------------------
    int passEndDay = days[i] + 7 - 1;
    int j = i;

    // avoiding buying pass, till it's valid
    while (j < days.size() && days[j] <= passEndDay) {
        j++;
    }

    int cost7 = costs[1] + mincostTicketsHelper(days, costs, j);

    //* 30 days Pass -------------------------
    passEndDay = days[i] + 30 - 1;
    j = i;

    // avoiding buying pass, till it's valid
    while (j < days.size() && days[j] <= passEndDay) {
        j++;
    }

    int cost30 = costs[2] + mincostTicketsHelper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}
//! TC:  3 ^ N
//* same as fibonacci, but here we've 3 branches.
//! SC:  N  ( max_depth )

int mincostTickets(vector<int>& days, vector<int>& costs) {
    return mincostTicketsHelper(days, costs, 0);
}

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    int ans = mincostTickets(days, costs);
    cout << "\nAnswer is: " << ans << "\n\n";
}