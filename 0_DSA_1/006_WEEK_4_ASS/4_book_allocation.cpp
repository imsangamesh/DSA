#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool isPossible(int arr[], int n, int m, int sol) {
    int pageSum = 0;
    int currAlloc = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > sol) return false;

        if (arr[i] + pageSum > sol) {
            currAlloc += 1;
            pageSum = arr[i];

            if (currAlloc > m) {
                return false;
            }
        }

        else {
            pageSum += arr[i];
        }

        cout << " ========= " << endl;
    }
    return true;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(int);
    int m = 2;

    int start = 0;
    int end = accumulate(arr, arr + n, 0);
    int ans = -1;

    if (m > n) ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << "Answer is: " << ans << endl;
}