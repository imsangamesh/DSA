//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* --------------------------------------

void addStrings(string& s1, int i1, string& s2, int i2, int carry,
                string& ans) {
    //
    if (i1 < 0 && i2 < 0) {
        while (carry) {
            ans.insert(ans.begin(), (carry % 10) + '0');
            carry /= 10;
        }
        return;
    }

    int n1 = i1 >= 0 ? s1[i1] - '0' : 0;
    int n2 = i2 >= 0 ? s2[i2] - '0' : 0;

    int temp = n1 + n2 + carry;
    carry = temp / 10;
    ans.insert(ans.begin(), temp % 10 + '0');

    addStrings(s1, i1 - 1, s2, i2 - 1, carry, ans);
}
//! TC:  N  ( max_len_of_2_nums )
//! SC:  N  ( max_len_of_2_nums )

int main() {
    string s1 = "9999999999", s2 = "99999";
    int i1 = s1.length() - 1, i2 = s2.length() - 1;
    int carry = 0;
    string ans = "";

    addStrings(s1, i1, s2, i2, carry, ans);
    cout << "Answer is: " << ans;
}