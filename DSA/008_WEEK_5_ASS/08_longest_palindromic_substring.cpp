//* 5. Longest Palindromic Substring
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) return false;
    }
    return true;
}
//! ////////////////////////////////////////////////
//! shd solve with DP | Leet: Time limit exceeded //
//! ////////////////////////////////////////////////
string longestPalindrome(string s) {
    int n = s.length();
    vector<string> substrs;
    string maxLenPalindrome;

    //? find substrings of string
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            string sub = s.substr(i, len);
            //? extract Palindromic ones
            if (isPalindrome(sub)) {
                substrs.push_back(sub);
                //? find max_len_palindrome
                maxLenPalindrome = sub;
            }
        }
    }

    return maxLenPalindrome;
}
//! TC:  N * N * N
//! SC:  1

int main() {
    string str = "noon";
    //
    string ans = longestPalindrome(str);
    cout << "Answer is: " << ans;
}