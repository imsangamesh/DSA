#include <iostream>
#include <vector>
using namespace std;

void reverseString(string& str, int s, int e) {
    if (s >= e) return;
    swap(str[s], str[e]);
    reverseString(str, s + 1, e - 1);
}
/*
* TC: n/2 + 1  >>  n
! we're calling recursively till both s & e meet
! soo, they'll meet exactly at the center.
* SC: n/2 + 1  >>  n
! reason is same as TC
*/

int main() {
    string str = "Hello";
    int s = 0, e = str.length() - 1;

    reverseString(str, s, e);
    cout << "Answer is: " << str;
}