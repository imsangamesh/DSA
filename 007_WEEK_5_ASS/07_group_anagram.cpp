#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
// using namespace std;
using std::array;
using std::cout;
using std::map;
using std::string;
using std::vector;

//* here we're facing O(n * (k*logk)) as time complexity bcz of sorting
vector<vector<string>> groupAnagrams1(vector<string> strs) {
    map<string, vector<string>> mp;

    for (auto &&str : strs) {
        string s = str;

        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans.push_back(it->second);
    }

    return ans;
}

//* we can eliminate sort function by using hashing as below
//! ----------- not sure about the error caused by the hash function
// std::array<int, 256> hash(string s) {
//     std::array<int, 256> hash = {0};
//     for (int i = 0; i < s.size(); i++) {
//         hash[s[i]]++;
//     }
//     return hash;
// }

// vector<vector<string>> groupAnagrams2(vector<string> strs) {
//     map<std::array<int, 256>, vector<string>> mp;

//     for (auto &&str : strs) {
//         mp[hash(str)].push_back(str);
//     }

//     vector<vector<string>> ans;
//     for (auto it = mp.begin(); it != mp.end(); it++) {
//         ans.push_back(it->second);
//     }

//     return ans;
// }

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams1(strs);
    // vector<vector<string>> ans = groupAnagrams2(strs);

    for (auto &&val : ans) {
        for (auto &&str : val) {
            cout << str << " ";
        }
        cout << "\n";
    }
}