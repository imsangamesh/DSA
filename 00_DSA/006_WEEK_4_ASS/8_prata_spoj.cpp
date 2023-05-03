#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> ranks, int pratas, int timeLimit) {
    int pC = 0;

    for (int r = 1; r <= ranks.size(); r++) {
        int timeTaken = 0;
        int count = 1;

        while (timeTaken + count * r <= timeLimit) {
            pC++;
            timeTaken = timeTaken + count * r;
            count++;
        }

        if (pC >= pratas) return true;
    }
    return false;
}

int main() {
    vector<int> ranks = {1, 2, 3, 4};
    int pratas = 10;
    int maxRank = *max_element(ranks.begin(), ranks.end());

    int start = 0;
    int end = pratas * (pratas + 1) / 2 * maxRank;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        cout << "Mid: ==============" << mid << endl;
        if (isPossible(ranks, pratas, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << "Answer is: " << ans << endl;
}