#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool isPossible(vector<int> arr, int k, int mid) {
    //? can we place k cows with at least mid distance between cow

    int count = 1;
    int pos = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            count++;
        }
        if (count == k) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 4, 8, 9};
    int k = 3;

    int start = 0;
    int end = arr[arr.size() - 1] - arr[0];
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, k, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << "Answer is: " << ans << endl;
}