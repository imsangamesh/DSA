#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void addStringsOfNums(string& num1, int p1, string& num2, int p2, string& ans,
                      int carry = 0) {
    //* -------------- BC
    if (p1 < 0 && p2 < 0) {
        if (carry != 0) ans.push_back(carry + '0');
        return;
    }

    //* -------------- PRC (Processing)
    int n1 = (p1 < 0 ? '0' : num1[p1]) - '0';
    int n2 = (p2 < 0 ? '0' : num2[p2]) - '0';
    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum / 10;
    ans.push_back(digit + '0');

    //* -------------- RR (Recursion Relation)
    addStringsOfNums(num1, p1 - 1, num2, p2 - 1, ans, carry);
}
/*
 * TC: n+1  >>  n
 * SC: n+1  >>  n
 */

int main() {
    string num1 = "11", num2 = "123";
    string ans = "";
    //
    addStringsOfNums(num1, num1.size() - 1, num2, num2.size() - 1, ans, 0);
    reverse(ans.begin(), ans.end());
    cout << "Answer is: " << ans;
}

//! //////////////////////////////////////////////
/*
* huge difference just by using PASS_BY_REFERENCE,
? before:  60ms  |  260mb  | beats 6%
? after :  6ms   |  7mb    | beats 56%
*/
