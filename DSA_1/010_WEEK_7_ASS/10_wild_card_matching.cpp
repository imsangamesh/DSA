#include <iostream>
#include <vector>
using namespace std;

bool isMatchHelper(string& str, int si, string& p, int pi) {
    // base
    if (si == str.size() && pi == p.size()) {
        return true;
    }

    if (si == str.size() && pi < p.size()) {
        while (pi < p.size()) {
            if (p[pi] != '*') return false;
            pi++;
        }
        return true;
    }

    // single char matching
    if (str[si] == p[pi] || '?' == p[pi]) {
        return isMatchHelper(str, si + 1, p, pi + 1);
    }

    if (p[pi] == '*') {
        //* treat '*' as empty
        bool caseA = isMatchHelper(str, si, p, pi + 1);

        //* let '*' consume one char
        bool caseB = isMatchHelper(str, si + 1, p, pi);

        return caseA || caseB;
    }

    // char doesn't match
    return false;
}

bool isMatch(string str, string p) {
    int si = 0;  //* pointer index for str
    int pi = 0;  //* pointer index for p

    return isMatchHelper(str, si, p, pi);
}
/*
* TC:  2^n (exponential)
! for each check, we're having 2 calls as fibonacci  ->  2^n
* SC:  n
*/

int main() {
    string str = "abcdefg";
    string p = "abc*fg";
    //
    bool ans = isMatch(str, p);
    cout << "Answer is: " << ans;
}