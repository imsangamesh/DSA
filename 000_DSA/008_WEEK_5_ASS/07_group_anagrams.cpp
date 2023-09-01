//* 49. Group Anagrams
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams_1(vector<string>& strs) {
    map<string, vector<string>> hash;

    for (auto str : strs) {  //! N
        string originalStr = str;
        sort(str.begin(), str.end());  //! N * (k * log_K)
        hash[str].push_back(originalStr);
    }

    vector<vector<string>> ans;
    for (auto eachPair : hash) {
        ans.push_back(eachPair.second);
    }

    return ans;
}
//? N : length_of_strs
//? k : length_of_largest_string
//! TC:  N * (k * log_k)
//! SC:  N * k

//? ---------------------------------------------------
//! ////////////////////////////////////////////////
//! It worked in LEETCODE  |  skipped sorting.  ////
//! ////////////////////////////////////////////////
// std::array<int, 26> createHash(string s) {
//     std::array<int, 26> arr = {0};
//     for (int i = 0; i < s.size(); i++) {
//         arr[s[i] - 'a']++;
//     }
//     return arr;
// }

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     map<std::array<int, 26>, vector<string>> map;

//     for (auto str : strs) {
//         map[createHash(str)].push_back(str);
//     }

//     vector<vector<string>> ans;
//     for (auto eachPair : map) {
//         ans.push_back(eachPair.second);
//     }

//     return ans;
// }
//! TC:  N * K
//* we're mapping our anagram 'hashMap' to 'vector_of_matching_strs'
//* 1. we're checking hashMap of all strs.
//* 2. and mapping them into similar group, if that_string's_hashMap is similar
//! SC:  N * k

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //
    vector<vector<string>> ans = groupAnagrams_1(strs);
    for (auto each : ans) {
        for (auto str : each) {
            cout << str << " ";
        }
        cout << endl;
    }
}
