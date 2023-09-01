//* 345. Reverse Vowels of a String
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isVowel(char ch) {
    //
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

string reverseOnlyLetters(string& str) {
    int i = 0, j = str.length() - 1;

    while (i < j) {
        if (isVowel(str[i]) && isVowel(str[j])) {
            swap(str[i], str[j]);
            i++;
            j--;
        } else if (isVowel(str[i])) {
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