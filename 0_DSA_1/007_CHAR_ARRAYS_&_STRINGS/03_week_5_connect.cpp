using namespace std;
#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>

bool cmp(char first, char second) { return first > second; }

int main() {
    //! --------------------------- CUSTOM COMPARATOR
    string s = "sanine";
    sort(s.begin(), s.end(), cmp);

    cout << s << endl;

    vector<int> arr = {5, 3, 1, 7, 9};
    sort(arr.begin(), arr.end(), cmp);
    // sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}