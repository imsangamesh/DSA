#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool isPossible(int arr[], int n, int m, long long sol) {
    int timeSum = 0;
    int currAlloc = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > sol) return false;

        if (timeSum + arr[i] > sol) {
            currAlloc += 1;
            timeSum = arr[i];

            if (currAlloc > m) return false;
        }

        else {
            timeSum += arr[i];
        }
    }

    return true;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;

    long long start = 0;
    long long end = accumulate(arr, arr + n, 0);
    int ans = -1;

    while (start <= end) {
        long long mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = start + 1;
        }
    }

    cout << "Answer is: " << ans << endl;
}