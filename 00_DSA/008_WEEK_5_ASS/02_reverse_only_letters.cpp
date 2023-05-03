using namespace std;

#include <iostream>
#include <string>

string reverseOnlyLetters(string str) {
    int s = 0, e = str.length() - 1;

    //? (str[s] >= 65 && str[s] <= 90) || (str[s] >= 97 && str[s] <= 122)
    //? for checking the alphabet

    while (s <= e) {
        if (isalpha(str[s]) && isalpha(str[e])) {
            swap(str[s], str[e]);
            s++;
            e--;
        } else if (!isalpha(str[s])) {
            s++;
        } else {
            e--;
        }
    }

    return str;
}

int main() {
    // string str = "Test1ng-Leet=code-2!";
    string str = "ab-cd";

    string newStr = reverseOnlyLetters(str);
    cout << newStr << endl;
}