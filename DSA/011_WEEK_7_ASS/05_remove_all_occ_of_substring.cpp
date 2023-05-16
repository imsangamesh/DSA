//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//*-------------------------- without RECURSION
string removeOccurrences(string s, string part) {
    while (s.find(part) != string::npos) {
        int foundIndex = s.find(part);
        s.erase(foundIndex, part.length());
    }
    return s;
}
//* --------------------------------------

string removeAllOccOfSubstring(string& str, string& part) {
    int isFound = str.find(part);
    if (isFound == string::npos) return str;

    str.erase(isFound, part.length());

    return removeAllOccOfSubstring(str, part);
}
//! TC:  N * N
//* find_fun :  N * M  ( str_len * part_len )  -->  each case
//* and recursive_fun is called till 'part' is found in 'str'
//* no_of_recursive_calls  -->  N / M
//? finally :  N * M * N / M  >>  N * N
//! SC:  N / M   ( no_of_calls )

int main() {
    string str = "daabcbaabcbc";
    string part = "abc";

    str = "axxxxyyyyb";
    part = "xy";

    string ans = removeAllOccOfSubstring(str, part);
    cout << "Answer is: " << ans;
}