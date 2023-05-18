//* 767. Reorganize String
//* ◉ ● ⇒
//* /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//! /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//! /\/\/\/\/ use PRIORITY QUEUE \/\/\/\/\/\/\
//! /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

//? GREEDY TECHNIQUE
string reorganizeString(string s) {
    // letters are only lower_case.
    int hash[26] = {0};

    for (int i = 0; i < s.size(); i++) {  //! N
        // in ASCII 'a' starts from 97, but to store it in hash of 26_len, so
        hash[s[i] - 'a']++;
    }

    //? find the char with most freq
    char maxFreqChar;
    int maxFreq = INT_MIN;
    for (int i = 0; i < 26; i++) {
        if (hash[i] > maxFreq) {
            maxFreq = hash[i];
            maxFreqChar = i + 'a';
        }
    }

    int index = 0;  // initialising placing index
    //? start placing maxFreqChar
    while (maxFreq && index < s.size()) {  //! N/2 >> N
        s[index] = maxFreqChar;            // placing max_freq_chars
        maxFreq--;                  // decrementing 'freq' of placed 'char'
        index += 2;                 // incrementing placing index
        hash[maxFreqChar - 'a']--;  // decrementing in hash_table
    }

    //* check if you've placed all max_freq_chars
    // if all were placed, it 'maxFreq' would be 0
    if (maxFreq != 0) return "";

    //* let's place the rest chars
    for (int i = 0; i < 26; i++) {
        while (hash[i] > 0) {  //! N*26 >> N
            // if index exceeds the bound, bring it to 1
            // as maxFreqChar is placed at 0.
            index = index >= s.size() ? 1 : index;

            s[index] = i + 'a';  // placing 'char'
            hash[i]--;           // decrementing freq
            index += 2;          // updating index
        }
    }

    return s;
}
//! TC:  N
//* N + N/2 + N*26  >>  N
//! SC:  1

int main() {
    //
    string ans = reorganizeString("aaabcba");
    cout << "Answer is: " << 404;
}