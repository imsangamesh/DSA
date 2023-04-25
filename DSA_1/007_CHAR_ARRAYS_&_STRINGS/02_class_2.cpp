using namespace std;
#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>

string removeDuplicates(string str) {
    string ans = "";

    for (int i = 0; i < str.length(); i++) {
        if (ans.length() == 0 || str[i] != ans[ans.length() - 1]) {
            ans.push_back(str[i]);
        } else {
            ans.pop_back();
        }
    }

    return ans;
}

string removeAdjacentDuplicates(string str, string word) {
    while (str.find(word) != string::npos) {
        int index = str.find(word);

        str.erase(index, word.length());
    }

    return str;
}

bool isPalindrome(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

vector<int> findMinutes(vector<string> times) {
    vector<int> result;
    for (int i = 0; i < times.size(); i++) {
        int hr = 0;
        int min = stoi(times[i].substr(3, 2));

        /*
         * this if check is done for special cases like
         * ["00:00, 23:59"]
         * - if you check this - there is no need to check the difference b/w
         *   last and first element at the end in main function.
         */
        if (times[i].substr(3, 2) == "00") {
            hr = 24;
        } else {
            hr = stoi(times[i].substr(0, 2));
        }

        int mins = hr * 60 + min;
        result.push_back(mins);
    }
    return result;
}

vector<string> findSubstrings(string str) {
    int n = str.length();
    vector<string> mySubstrs;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - 1 - i; j++) {
            string temp = str.substr(i, j);
            if (isPalindrome(temp)) {
                mySubstrs.push_back(temp);
            }
        }
    }
    return mySubstrs;
}

int expandAroundIndex(string str, int i, int j) {
    int count = 0;
    while (i >= 0 && j <= str.length() - 1 && str[i] == str[j]) {
        count++;
        i--;
        j++;
    }
    return count;
}

int main() {
    //! --------------------------- REMOVE DUPLICATES
    // string str = "abbaca";
    // cout << "Answer is: " << removeDuplicates(str) << endl;

    //! --------------------------- REMOVE ADJACENT DUPLICATES
    // //? tc:1
    // string str = "daabcbaabcbc";
    // string word = "abc";
    // //? tc:2
    // str = "axxxxyyyyb";
    // word = "xy";

    // cout << "Answer is: " << removeAdjacentDuplicates(str, word) << endl;

    //! --------------------------- VALID PALINDROME
    // string str = "leverl";
    // int n = str.length();

    // for (int i = 0; i < n / 2; i++) {
    //     if (str[i] != str[n - 1 - i]) {
    //         string temp = str;
    //         if (isPalindrome(temp.erase(i, 1))) {
    //             str.erase(i, 1);
    //         } else {
    //             str.erase(n - 1 - i, 1);
    //         }

    //         break;
    //     }
    // }
    // cout << str << endl;

    //! --------------------------- MIN MINUTE DIFF
    // //? tc:1
    // vector<string> times = {"12:10", "10:15", "13:15", "17:20",
    //                         "18:00", "19:47", "23:59"};
    // //? tc:2
    // times = {"00:00", "23:59"};

    // vector<int> minutes = findMinutes(times);
    // sort(minutes.begin(), minutes.end());

    // int minDiff = INT_MAX;
    // for (int i = 0; i < minutes.size() - 1; i++) {
    //     int diff = minutes[i + 1] - minutes[i];
    //     if (diff < minDiff) {
    //         minDiff = diff;
    //     }
    // }

    // //* we got to check (lastElm - firstElm) to avoid
    // //* special cases like ["00:00", "23:59"];
    // //* int diff = minutes[0] + 1440 - minutes[minutes.size() - 1];
    // //* if (diff < minDiff) {
    // //*     minDiff = diff;
    // //* }

    // cout << "Min difference is: " << minDiff << endl;

    //! --------------------------- SUBSTRING PALINDROMES IN STR
    // string str = "aaa";
    // vector<string> mySubstrs = findSubstrings(str);

    // cout << mySubstrs;

    //! --------------------------- PALINDROME SUBSTRINGS
    //***************************************************
    // string str = "noon";
    // int totalCount = 0;
    // int n = str.length();

    // for (int center = 0; center < n; center++) {
    //     //? odd
    //     int oddAns = expandAroundIndex(str, center, center);
    //     totalCount += oddAns;

    //     //? even
    //     int evenAns = expandAroundIndex(str, center, center + 1);
    //     totalCount += evenAns;
    // }
    // cout << "Answer is: " << totalCount;
}