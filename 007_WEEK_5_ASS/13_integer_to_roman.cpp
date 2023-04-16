#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    vector<string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans = "";
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            ans += symbols[i];
            num -= values[i];
        }
    }

    return ans;
}

int main() {
    int num = 1994;

    string roman = intToRoman(num);

    cout << "Answer is: " << roman;
}