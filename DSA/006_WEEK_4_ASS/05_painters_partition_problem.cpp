//*
//* ◉ ● ⇒
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool isAllocationPossible(int arr[], int n, int k, int guessedTime) {
    long long plankSum = 0;
    int painterCount = 1;  // start with 1st painter.

    for (int i = 0; i < n; i++) {
        //* if plank_set has more planks than guessed_time, they won't
        //* complete in time.
        if (arr[i] > guessedTime) return false;

        if (plankSum + arr[i] > guessedTime) {
            painterCount++;     // move to next painter.
            plankSum = arr[i];  // reset the plankSum for next painter.

            //* after moving to next painter, check if we've exceeded
            //* the given num of painters.
            if (painterCount > k) return false;
        }

        // everything is fine.
        else {
            plankSum += arr[i];
        }
    }
    // all pages are assigned successfully.
    return true;
}

long long minimumPaintingTime(int arr[], int n, int k) {
    long long start = 0;
    long long end = 0;
    //* we're assuming that, "what if we give all planks to one painter?"
    //* where he'll take 'end' time.
    for (int i = 0; i < n; i++) {
        end += arr[i];
    }

    long long ans = -1;

    while (start <= end) {
        long long mid = start + (end - start) / 2;

        if (isAllocationPossible(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1;  // check for other possible soln on left
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4, k = 2;
    //
    long long ans = minimumPaintingTime(arr, n, k);
    cout << "Answer is: " << ans;
}