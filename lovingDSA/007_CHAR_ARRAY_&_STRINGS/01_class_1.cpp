#include <string.h>
using namespace std;
#include <bits/stdc++.h>

#include <iostream>
#include <string>

int len(char name[]) {
    int length = 0, i = 0;

    while (name[i] != '\0') {
        length++;
        i++;
    }
    return length;
}

void reverseString(char name[]) {
    int n = len(name);
    int i = 0, j = n - 1;

    while (i < j) {
        swap(name[i], name[j]);
        i++;
        j--;
    }

    //* for (int i = 0; i < n / 2; i++) {
    //*     swap(name[i], name[n - 1 - i]);
    //* }
}

bool isPalindrome(char* name) {
    int n = len(name);
    for (int i = 0; i < n / 2; i++) {
        if (name[i] != name[n - 1 - i]) return false;
    }
    return true;
}

void toUpperCase(char* name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] = name[i] - ('a' - 'A');  // a - A = 32
        }
    }
}

void toLowerCase(char* name) {
    for (int i = 0; i < len(name); i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            name[i] = name[i] + ('a' - 'A');  // a - A = 32
        }
    }
}

bool myCompare(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    int maxLen = max(str1.length(), str2.length());
    for (int i = 0; i < maxLen; i++) {
        if (str1[i] != str2[i]) return false;
    }

    return true;
}

int main() {
    //! --------------------------- LENGTH
    // char name[] = "Sanine Pinklin";
    // cout << len(name) << endl;
    // cout << strlen(name) << endl;

    //! --------------------------- REVERSE
    // char name[] = "Sanine Pinklin";
    // cout << "Name: " << name << endl;
    // reverseString(name);
    // cout << "Reversed: " << name << endl;

    //! --------------------------- REPLACE SPACE with @
    // cout << "Enter name: ";
    // char name[30];
    // cin.getline(name, 30);

    // for (int i = 0; i < len(name); i++) {
    //     if (name[i] == ' ') name[i] = '@';
    // }

    // cout << "\nModified: " << name << "\n\n";

    //! --------------------------- PALINDROME
    // char name[] = "My name is Sanine Pinklin";
    // char check[] = "racecar";

    // cout << "Palindrome :" << isPalindrome(check);

    //! --------------------------- change CASE
    // char name[] = "Hello There!";
    // toUpperCase(name);
    // cout << "Uppercase :" << name << "\n\n";
    // toLowerCase(name);
    // cout << "Lowercase :" << name << "\n\n";

    //! ----------------------------------------------------- STRINGS
    //! ----------------------------------------------------- STRINGS
    // char demo1[10];
    // string demo2;
    //
    // demo1[0] = 'S';
    // demo1[1] = '\0';
    // demo1[2] = 'a';
    // demo1[3] = '\0';
    // demo1[4] = 'n';

    // demo2[0] = 'S';
    // demo2[1] = '\0';
    // demo2[2] = 'a';
    // demo2[3] = '\0';
    // demo2[4] = 'n';
    //
    // for (int i = 0; i < 5; i++) cout << demo1[i];
    // cout << "\n";
    // for (int i = 0; i < 5; i++) cout << demo2[i];

    // string str = "SaninePinklin";
    //
    // cout << "------------\n" << endl;
    //
    // cout << str << endl;
    // cout << str.length() << endl;
    // cout << str.empty() << endl;
    // str.push_back('@');
    // cout << str << endl;
    // str.pop_back();
    // cout << str << endl << endl;
    //
    // cout << str.substr(0, 6) << endl;
    // cout << str.substr(6, 7) << endl;
    // cout << str << endl;
    //
    // cout << "\n------- compare -----\n";
    //
    // string str1 = "Love";
    // string str2 = "Lover";

    // if (myCompare(str1, str2)) {
    //     cout << "they are same" << endl;
    // } else {
    //     cout << "they are not same" << endl;
    // }

    // int res = str1.compare(str2);
    // if (res == 0) {
    //     cout << "they are same" << endl;
    // } else {
    //     if (res == 1) {
    //         cout << "str1 is greater" << endl;
    //     } else {
    //         cout << "str2 is greater" << endl;
    //     }
    // }

    // cout << "\n------------" << endl;

    //! --------------------------- FIND
    // string sentence = "Hello there, Sanine Pinklin";

    // int res = sentence.find("there");
    // if (res == string::npos) {
    //     cout << "Not found" << endl;
    // } else {
    //     cout << "Found at index: " << res << endl;
    // }

    //! --------------------------- REPLACE
    // string sentence = "Hello there, Sanine Pinklin";

    // sentence.replace(0, 5, "Hey");
    // cout << sentence << endl;

    //! --------------------------- ERASE
    // string str = "SaninePinklin";

    // str.erase(0, 10);
    // cout << str << endl;
}