//*
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> arr) {
    for (string val : arr) {
        cout << val << " ";
    }
}

//? ------------------------------------------------------------------
string removeAdjacentDuplicates(string& str) {
    //* traverse through string & do these 2 steps:
    //* 1● if last_char_of_ans == curr_char_of_str >>> pop_it
    //* 2● else push_it.
    string ans = "";
    for (int i = 0; i < str.length(); i++) {
        if (ans.length() == 0) {
            ans.push_back(str[i]);
            continue;
        }

        if (ans[ans.length() - 1] == str[i]) {
            ans.pop_back();
        } else {
            ans.push_back(str[i]);
        }
    }
    return ans;
}
//! TC:  N (str_len)
//* for loop
//! SC:  constant

//? ------------------------------------------------------------------
string removeAllOccOfString(string& str, string part) {
    while (str.find(part) != string::npos) {
        int foundIndex = str.find(part);
        str.erase(foundIndex, part.length());
    }
    return str;
}

//? ------------------------------------------------------------------
bool isPalindrome(string& str, int i, int j) {
    while (i < j) {
        if (str[i] != str[j]) return false;

        i++;
        j--;
    }
    return true;
}
bool validPalindromeII(string s) {
    int i = 0, j = s.length() - 1;

    while (i <= j) {
        if (s[i] == s[j]) {
            //* both extremes are same, so move on.
            i++;
            j--;
        } else {
            //* not equal, now try removing 'i', or remove 'j'
            //* one at a time, & check if:
            //* "if by removing any char, we can get a palindrome"
            //* if in any of 2 cases, we get true, then return true.

            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
    }
    return true;
}
//! TC:  N + N + N  >>  N
//* running N + N iterations for 2 cases, when s[i] != s[j].
//* however, if in all the cases, if s[i] == s[j] (if given str is palindrome)
//* then, we don't have to check these extra 2 cases.
//! SC:  constant

//? ------------------------------------------------------------------
int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;

    //? step1: get minutes in int.
    for (int i = 0; i < timePoints.size(); i++) {
        string curr = timePoints[i];

        int hours = stoi(curr.substr(0, 2));
        int mins = stoi(curr.substr(3, 2));
        int totalMins = hours * 60 + mins;

        minutes.push_back(totalMins);
    }

    //? sort the array.
    //* by sorting you prevent your N*N TC while searching the mini
    sort(minutes.begin(), minutes.end());

    //? find minimum among sorted mins.
    int mini = INT_MAX;
    for (int i = 0; i < minutes.size() - 1; i++) {
        int diff = minutes[i + 1] - minutes[i];
        if (diff < mini) mini = diff;
    }

    //! comparing the last missing comparison
    //* i.e. comparing FIRST & LAST elms
    int lastDiff = minutes[0] + 1440 - minutes[minutes.size() - 1];
    // adding 1440, coz 24 * 60 (minutes_in_day)
    if (lastDiff < mini) mini = lastDiff;

    return mini;
}

//? ------------------------------------------------------------------
bool isPali(string name) {
    for (int i = 0; i <= name.length() / 2; i++) {
        if (name[i] != name[name.length() - 1 - i]) return false;
    }
    return true;
}
vector<string> findPalindromicSubStrs_1(string str) {
    vector<string> ans;
    int n = str.length();

    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            string sub = str.substr(i, len);
            if (isPali(sub)) ans.push_back(sub);
        }
    }

    return ans;
}
//! TC:  N * N * N
//* 2 nested_for loops
//* 1 nested loop from Pali_function.
//! SC:  constant

//? --------------------
int expandAroundIndex(string str, int i, int j) {
    int count = 0;
    // till the characters are matching,
    // till i doesn't go before 0
    // till j doesn't go after n-1
    while ((i >= 0) && (i <= str.length() - 1) && (str[i] == str[j])) {
        count++;
        i--;
        j++;
    }
    return count;
}

int findPalindromicSubStrs_2(string str) {
    int n = str.length();
    int count = 0;

    for (int center = 0; center < n; center++) {
        //
        //? ODD CASE
        int oddPalindromes = expandAroundIndex(str, center, center);
        count += oddPalindromes;

        //? EVEN CASE
        int evenPalindromes = expandAroundIndex(str, center, center + 1);
        count += evenPalindromes;
    }

    return count;
}
//! TC:  N ^ 2
//* one for loop
//* 2 adjacent while loops, which are jumping from 2 steps at a time.
//* sooo we consider N for while loop
//! SC:  constant

int main() {
    //! 1047. Remove All Adjacent Duplicates In String
    // string str = "abbaca";
    // cout << "Answer is: " << removeAdjacentDuplicates(str);

    //! 1910. Remove All Occurrences of a Substring
    // string str = "daabcbaabcbc";
    // string part = "abc";
    // cout << "Answer is: " << removeAllOccOfString(str, part);

    //! 680. Valid Palindrome II
    // string str = "abca";
    // cout << "Answer is: " << validPalindromeII(str);

    //! 539. Minimum Time Difference
    // vector<string> times = {"23:59", "00:00"};
    // cout << "Answer is: " << findMinDifference(times);

    //! 647. Palindromic Substrings | 1:40
    //! //////////////////////////////////////
    //! //////////// IMPORTANT ///////////////
    //! //////////////////////////////////////
    string str = "noon";
    //? NIEVE METHOD | BRUTE FORCE | N^3
    // vector<string> ans = findPalindromicSubStrs_1(str);

    //? BETTER METHOD | N^2
    int ans = findPalindromicSubStrs_2(str);
    cout << "Answer is: " << ans;
}