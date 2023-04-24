using namespace std;
#include <iostream>
#include <string>

bool isAnagram(string s, string t) {
    int freqTable[256] = {0};

    for (int i = 0; i < s.size(); i++) {
        freqTable[s[i]] += 1;
    }

    for (int i = 0; i < t.size(); i++) {
        freqTable[s[i]] -= 1;
    }

    for (auto&& val : freqTable) {
        if (val != 0) return false;
    }
    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    bool result = isAnagram(s, t);

    if (result) {
        cout << "They are anagrams";
    } else {
        cout << "They are not anagrams";
    }
}