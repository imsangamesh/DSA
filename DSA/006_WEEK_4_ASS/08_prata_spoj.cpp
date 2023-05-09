//*
//* ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

int timeToCook(int rank, int nP) {
    //
    return rank * nP * (nP + 1) / 2;
}

bool isPossible(vector<int>& ranks, int nP, int guessedTime) {
    int prataCount = 0;  // cooked pratas

    for (int i = 0; i < ranks.size(); i++) {
        int R = ranks[i];  // curr rank
        int j = 1;         // efficiency (cook1: 1, cook2: 2, ...)
        int timeTaken = 0;

        while (true) {
            if (timeTaken + j * R <= guessedTime) {
                //* if cook is cooking, in the guessedTime
                prataCount++;
                timeTaken += j * R;  // Rank * individual_prata_count

                j++;
                // increasing individual_prata_count to maintain the increasing
                // time for successive pratas.
            } else {
                // if time has exceeded the guessedTime,
                //* break & move to next to cook
                break;
            }
        }

        //* if any of the cooks completed the task, return
        //* else check for next cook
        if (prataCount >= nP) return true;
    }
    return false;
}

int minTimeToCook(vector<int>& ranks, int nP) {
    int lastRank = ranks[ranks.size() - 1];

    int start = 0;
    //* if all pratas are done by last_rank_chef
    int end = timeToCook(lastRank, nP);

    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(ranks, nP, mid)) {
            ans = mid;
            end = mid - 1;  // checking if we can do in yet less time.
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int nC = 4;  // no of cooks.

    vector<int> ranks = {1, 2, 3, 4};
    int nP = 10;  // no of pratas.

    ranks = {1};
    nP = 8;

    ranks = {1, 1, 1, 1, 1, 1, 1, 1};
    nP = 8;
    //
    int ans = minTimeToCook(ranks, nP);
    cout << "Answer is: " << ans;
}