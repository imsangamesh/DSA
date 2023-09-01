//* 44. Wildcard Matching
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

bool isMatchHelper(string& s, int si, string& p, int pi) {
    // base case
    if (si == s.size() && pi == p.size()) return true;

    // base case
    if (si == s.size() && pi < p.size()) {
        while (pi < p.size()) {
            if (p[pi] != '*') return false;
            pi++;
        }
        return true;
    }

    //* single char matching
    if (s[si] == p[pi] || '?' == p[pi]) {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }

    if (p[pi] == '*') {
        //* treating '*' as null
        bool caseA = isMatchHelper(s, si, p, pi + 1);

        //*treating '*' as one char
        bool caseB = isMatchHelper(s, si + 1, p, pi);

        return caseA || caseB;
    }

    //* char doesn't match
    return false;
}
//! TC:  2 ^ N  same_as_fib
//! SC:  N

bool isMatch(string s, string p) {
    int si = 0;  // pointer index for s string
    int pi = 0;  // pointer index for p string

    return isMatchHelper(s, si, p, pi);
}

int main() {
    string s = "abcd*fg";
    string p = "ab*fg";

    int ans = isMatch(s, p);
    cout << "\nAnswer is: " << ans << "\n\n";
}