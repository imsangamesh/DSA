#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//? we're concatenating 2 strings and returning the one
//? which sums-up to largest value
//? ex: a = 30 | b = 3
//? a+b = 303  | b+a = 330
//? it should return (b+a) rather than (a+b)
bool myComparator(string a, string b) { return a + b > b + a; }

string largestNumber(vector<int>& nums) {
    vector<string> snums;

    //? converting nums to strings
    for (auto num : nums) {
        snums.push_back(to_string(num));
    }

    sort(snums.begin(), snums.end(), myComparator);

    //* when 0 is the largest no among all the numbers in the array
    //* we're returning 0 directly instead of 000
    if (snums[0] == "0") return 0;

    string ans = "";
    for (auto val : snums) {
        ans += val;
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    // nums = {1, 2, 3, 4, 5};

    string res = largestNumber(nums);
    cout << "Answer is: " << res;
}