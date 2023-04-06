using namespace std;
#include <iostream>

bool isIsomorphis(string s, string t) {
    int hash[256] = {0};
    //? mapping of each char of lang 's' to lang 't'

    int isTCharsMapped[256] = {0};
    //? stores if t[i] char already mapped with s[i]

    for (int i = 0; i < s.size(); i++) {
        if (hash[s[i]] == 0 && isTCharsMapped[t[i]] == 0) {
            hash[s[i]] = t[i];
            isTCharsMapped[t[i]] = 1;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (char(hash[s[i]]) != t[i]) return false;
    }
    return true;
}

int main() {
    string s = "egg", t = "add";

    bool result = isIsomorphis(s, t);

    cout << "Result is: " << result;
}