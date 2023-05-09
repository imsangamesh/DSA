//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//? if number > INT_MAX, clamp it to INT_MAX
//? if number < INT_MIN, clamp it to INT_MIN
//? if there is no num, return 0.
int myAtoi(string s) {
    int number = 0, i = 0;
    int sign = 1;  // +ve

    //? ignore spaces
    while (s[i] == ' ') i++;

    cout << "checking at : " << i;
    //? determining -ve & +ve sign
    if (i < s.size() && s[i] == '-' || s[i] == '+') {
        sign = s[i] == '-' ? -1 : 1;
        i++;
    }

    //? convert all available digits
    while (i < s.size() && isdigit(s[i])) {
        //* coz, further, we're gonna multiply it by 10
        //* soo, we're checking before_hand that
        if (number > INT_MAX / 10) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }

        //* there my be the case, where number = INT_MAX
        //* now, num = 2,147,483,64
        //* if you multiply by 10  >>   2,147,483,640
        //* if you add something > 7  >> it overflows
        if (number == INT_MAX / 10 && s[i] > '7') {
            return sign == -1 ? INT_MIN : INT_MAX;
        }

        number = number * 10 + (s[i] - '0');
        i++;
    }

    return number * sign;
}
//! TC:  N
//! SC:  1

int main() {
    string str = "    -1234hello";
    str = "+1";
    str = "+-12";
    // str = "   -42";
    //
    int ans = myAtoi(str);
    cout << "Answer is: " << ans;
}