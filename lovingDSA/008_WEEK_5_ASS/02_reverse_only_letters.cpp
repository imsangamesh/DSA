//* 917. Reverse Only Letters
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isAlpha(char ch) {
    //
    return (ch > 64 && ch < 91) || (ch > 96 && ch < 123);
}

string reverseOnlyLetters(string& str) {
    int i = 0, j = str.length() - 1;

    while (i < j) {
        if (isAlpha(str[i]) && isAlpha(str[j])) {
            swap(str[i], str[j]);
            i++;
            j--;
        } else if (isAlpha(str[i])) {
            j--;
        } else {
            i++;
        }
    }
    return str;
}
//! TC:  N / 2  >>  N
//* looping through string till half way (till i & j meet)
//! SC:  1

int main() {
    string str = "Test1ng-Leet=codeQ!";
    str = "ab-cd";
    //
    string ans = reverseOnlyLetters(str);
    cout << "Answer is: " << ans;
}