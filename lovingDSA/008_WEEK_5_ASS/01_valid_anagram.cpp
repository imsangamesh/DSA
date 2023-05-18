//* 242. Valid Anagram
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//? BRUTE FORCE | NIEVE
bool validAnagram_1(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
//! TC:  N * log_N
//* 2 sorting algos
//! SC:  constant

//? -----------------------------------------------------
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int freqTable[26] = {0};  //* no of alplhabets

    //* incrementing count when I encounter a 'char'
    for (size_t i = 0; i < s.length(); i++) {
        freqTable[s[i] - 'a']++;
        freqTable[t[i] - 'a']--;
    }

    //* now checking whether all counts have decremented or not
    //* if yes, s & t are same
    for (int elm : freqTable) {
        if (elm != 0) return false;
    }

    return true;
}
//! TC:  N + N = N
//* 2 adjacent for loops
//! SC:  256 * 4 bytes  >>  1

int main() {
    string s = "aaagmnr";
    string t = "anagram";
    //
    bool ans = isAnagram(s, t);
    cout << "Answer is: " << ans;
}