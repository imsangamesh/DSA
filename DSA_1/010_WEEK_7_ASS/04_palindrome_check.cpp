#include <iostream>
#include <vector>
using namespace std;

void checkPalindrome(string& str, int s, int e, bool& ans) {
    if (s >= e) return;

    if (str[s] != str[e]) {
        ans = false;
        return;
    }

    checkPalindrome(str, s + 1, e - 1, ans);
}
/*
* TC:  n/2 + 1  >>  n
! recursing till n/2
* SC:  n/2 + 1  >>  n
*/

int main() {
    string str = "racecar";
    bool ans = true;
    //
    checkPalindrome(str, 0, str.length() - 1, ans);
    cout << "Answer is: " << ans;
}