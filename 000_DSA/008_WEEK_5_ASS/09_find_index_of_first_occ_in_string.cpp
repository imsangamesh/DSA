//* 28. Find the Index of the First Occurrence in a String
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.size(); i++) {
        //
        int j = 0;
        while (j < needle.size()) {
            // looping till needle & haystack are exactly equal
            if (needle[j] != haystack[i + j]) break;
            j++;
        }

        if (j == needle.size()) return i;
    }
    return -1;
}
//! TC:  N * M (len_of_haystack, len_of_needle)
//*
//! SC:  1

int main() {
    string haystack = "sadbutsad", needle = "sad";
    haystack = "leetcode", needle = "leeto";
    //
    int ans = strStr(haystack, needle);
    cout << "Answer is: " << ans;
}