#include <bits/stdc++.h>

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool isPossible(vector<long long int> arr, int need, long long int cut) {
    int total = 0;
    int count = 1;

    for (int i = 0; i < arr.size(); i++) {
        cout << count++ << endl;
        if (cut < arr[i]) {
            total += arr[i] - cut;
        }
    }
    return total >= need;
}

int main() {
    vector<long long int> arr = {20, 15, 10, 17};
    int need = 7;

    long long int start = 0;
    long long int end = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, need, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << "Answer is: " << ans << endl;
}
