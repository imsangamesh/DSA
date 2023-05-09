//* 14. Longest Common Prefix
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strings) {
    if (strings.size() == 1) return strings[0];  // special case

    int ci = 0;  // currentIndex
    string ans = "";

    while (true) {
        // char we're checking with all strings
        char currChar = strings[0][ci];

        for (auto str : strings) {
            cout << "======\n";
            // if any of char, doesn't match, we return 'ans'
            if (str[ci] != currChar) return ans;
        }

        //* we've got out of for loop, means, all the chars matched
        //* so just push it to string.
        cout << "pushing: " << currChar << endl;
        ans.push_back(currChar);
        ci++;  // now check for next char.
    }

    return ans;
}
//! TC:  N * M
//* N : no_of_strings  |  M : no_of_matching_letters
//* we're iterating nested_for_in_while loop. soo in the worst case,
//* if all the characters in all strings match, then we get N*M.
//! SC:  1

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    strs = {"flower", "flower", "flower"};
    // strs = {"dog", "racecar", "car"};
    // strs = {"", ""};  //! DIDN'T GET THIS
    //
    string ans = longestCommonPrefix(strs);
    cout << "Answer is: " << ans;
}
