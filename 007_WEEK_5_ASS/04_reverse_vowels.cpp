using namespace std;
#include <iostream>
#include <string>

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseOnlyVowels(string str) {
    int s = 0, e = str.length() - 1;

    while (s <= e) {
        if (isVowel(str[s]) && isVowel(str[e])) {
            swap(str[s], str[e]);
            s++;
            e--;
        } else if (!isVowel(str[s])) {
            s++;
        } else {
            e--;
        }
    }

    return str;
}

int main() {
    // string str = "hello";
    string str = "leetcode";

    string newStr = reverseOnlyVowels(str);
    cout << newStr << endl;
}
