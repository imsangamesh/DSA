//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* --------------------------------------

bool palindromeCheck(string& str, int i) {
    if (i == str.length() / 2) return true;

    int n = str.length();
    if (str[i] != str[n - 1 - i]) return false;

    return palindromeCheck(str, i + 1);
}
//! TC:  N/2  >>  N
//! SC:  N/2  >>  N

int main() {
    string str = "racecar";

    bool ans = palindromeCheck(str, 0);
    cout << "Answer is: " << ans;
}