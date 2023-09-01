//* GFG. FIRST REPEATING ELM
//* ⍟ ◉ ● ⇒
#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int storeTheFreqOfElms(vector<int>& arr) {
    //* storing the frequencies of each no. and checking which no. has the
    //* frequency greater than 1, checking from the left index.
    unordered_map<int, int> hash;

    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]]++;
    }

    for (auto val : arr) {
        if (hash[val] > 1) return val;
    }

    return -1;
}

int storeTheFreqOfElmsWithArrayHash(vector<int>& arr) {
    //* storing the frequencies of each no. and checking which no. has the
    //* frequency greater than 1, checking from the left index.
    //! own hash using array.
    int max = *max_element(arr.begin(), arr.end());
    vector<int> hash(max, 0);

    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]]++;
    }

    for (auto val : arr) {
        if (hash[val] > 1) return val;
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
    //
    int ans = storeTheFreqOfElmsWithArrayHash(arr);
    cout << "Answer is: " << ans;
}