//* 205. Isomorphic Strings
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    int hash1[256] = {0};  // s -> t mapper
    int hash2[256] = {0};  // t -> s mapper

    for (int i = 0; i < s.length(); i++) {
        //* hash1[s[i]] shd be 0 or t[i]
        if (hash1[s[i]] != 0 && hash1[s[i]] != t[i]) return false;
        //* hash2[t[i]] shd be 0 or s[i]
        if (hash2[t[i]] != 0 && hash2[t[i]] != s[i]) return false;

        hash1[s[i]] = t[i];
        hash2[t[i]] = s[i];
    }
    return true;
}
//! TC:  N (length_of_str)
//* 1 for loop
//! SC:  (256 + 256) * 4  >>  1

int main() {
    string s = "egg", t = "add";
    // s = "foo", t = "bar";
    // s = "paper", t = "title";
    // s = "badc", t = "baba";
    //
    bool ans = isIsomorphic(s, t);
    cout << "Answer is: " << ans;
}