//* 12. Integer to Roman
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string romanSymbols[13] = {
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
};

int values[13] = {
    1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
};

string intToRoman(int num) {
    string ans = "";
    int i = 0;

    while (num > 0) {
        // till you find number_smaller_than num, check forword.
        //* no need to reset i everytime, coz next reduced num < values[i]
        while (num < values[i]) i++;

        // once you've found that num, then push_that to ans
        ans = ans + romanSymbols[i];
        // then update the num.
        num = num - values[i];
    }
    return ans;
}

int main() {
    int num = 94;
    num = 58;
    num = 1994;
    //
    string ans = intToRoman(num);
    cout << "Answer is: " << ans;
}