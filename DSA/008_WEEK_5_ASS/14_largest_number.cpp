//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool myComp(string a, string b) {
    //
    return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
    vector<string> snums;

    for (auto n : nums) snums.push_back(to_string(n));

    sort(snums.begin(), snums.end(), myComp);

    //* if the largest num is 0, then all are 0, soo
    if (snums[0] == "0") return "0";

    string ans = "";
    for (auto str : snums) ans += str;

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    nums = {3, 30, 34, 5, 9};
    nums = {0, 0};
    nums = {0};
    //
    string ans = largestNumber(nums);
    cout << "Answer is: " << ans;
}