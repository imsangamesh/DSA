//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* --------------------------------------

void reverseString(string& str, int s, int e) {
    if (s > e) return;
    swap(str[s], str[e]);
    reverseString(str, s + 1, e - 1);
}
//! TC:  N/2  >>  N
//! SC:  N/2  >>  N

int main() {
    string str = "hello there";
    reverseString(str, 0, str.length() - 1);
    cout << "Answer is: " << str;
}