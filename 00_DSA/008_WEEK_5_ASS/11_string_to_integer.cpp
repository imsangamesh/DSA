#include <iostream>
#include <string>

using namespace std;

int stringToInteger(string str) {
    int ans = 0, i = 0, sign = 1;  //? +ve sign

    //? removing white spaces
    while (str[i] == ' ') i++;

    //? detecting the sign
    if (i < str.size() && str[i] == '-' || str[i] == '+') {
        sign = str[i] == '+' ? 1 : -1;
        i++;
    }

    //? extracting all digits
    while (i < str.size() && isdigit(str[i])) {
        /*
         * checking if the no after doesn't exceed the
         * default range of INT datatype in both cases
         * 1. multiplied by 10
         * 2. when added by single character
         */
        if (ans > INT_MAX || (ans == INT_MAX && str[i] > '7')) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }

        //! converting to int by substracting ( '0' ) from char
        ans = ans * 10 + (str[i] - '0');
        i++;
    }

    return ans * sign;
}

int main() {
    string s = "   -42";

    int num = stringToInteger(s);

    cout << "Number is: " << num;
}
