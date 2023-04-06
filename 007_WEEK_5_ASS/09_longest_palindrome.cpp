#include <iostream>
// using namespace std;
using std::cout;
using std::string;

bool isPalindrome(string& s, int start, int end) {
    while (start <= end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

string longestPalindrome(string s) {
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                string t = s.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }

    return ans;
}

int main() {
    string s = "babad";
    string res = longestPalindrome(s);

    cout << "Answer is: " << s;
}

/*
 * 2 loops in longest palindrome fn
 * 3 one loop in isPalindrome fn

 ! O ( n*n*n )
 */