//*
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& stalls, int k, int guessedDist) {
    // can we place k cows, with at least guessedDist betw cows

    int cowCount = 1;     // cow count.
    int pos = stalls[0];  // pos of 1st cow placed.

    //* we're starting loop from 2nd elm, coz we've assigned cow_1 to 1st index.
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - pos >= guessedDist) {
            cowCount++;       // curr_cow placed, moving to next.
            pos = stalls[i];  // updating the position after moving to next.
        }

        //* if cows_placed == total_cows, return true.
        if (cowCount == k) return true;
    }
    // if cows are not placed, coz the guessedDist was too large.
    return false;
}

int maxDistanceBetwStalls(int n, int k, vector<int> stalls) {
    sort(stalls.begin(), stalls.end());

    int start = 0;  // when 2 cows are kept at 0 index.
    int end = stalls[stalls.size() - 1] - stalls[0];
    // when 2 cows are kept at 'start' & 'end';
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) >> 1;

        if (isPossible(stalls, k, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 8, 9};
    int n = 5, k = 3;
    //
    int ans = maxDistanceBetwStalls(n, k, arr);
    cout << "Answer is: " << ans;
}