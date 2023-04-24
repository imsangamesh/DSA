#include <iostream>
#include <vector>
using namespace std;

void lastOccurenceLTR(string& str, char& key, int i, int& loi) {
    if (i == str.length()) return;

    lastOccurenceLTR(str, key, i + 1, loi);

    if (str[i] == key) loi = i;
}
/*
* TC: O(n)
! TC: suppose we have string 'abc', then recursive tree forms
! till 'i' = str_len. so totally there'll be ( n+1 ) recursions.
! soo, TC: O(n)
* SC: O(n)
! reason is same as TC
*/

void lastOccurenceRTL(string& str, char& key, int i, int& loi) {
    if (i < 0) return;

    //* when checking from R to L we're not continuing to check further chars
    //* coz, we got the last occurence index, so we return.
    if (str[i] == key) {
        loi = i;
        return;
    }

    lastOccurenceRTL(str, key, i - 1, loi);
}
/*
* TC: O(n)
! TC: suppose we have string 'abc', then recursive tree forms
! till 'i' < 0. so totally there'll be ( n+1 ) recursions.
! soo, TC: O(n)
* SC: O(n)
! reason is same as TC
*/

int main() {
    //* methods to follow
    //? M1: search from left to right
    //? M2: search from right to left
    //? M3: STL function --> strrchar()

    //! -------------------------- LEFT to RIGHT
    // string str = "abcddedf";
    // char key = 'd';
    // int i = 0;
    // int loi = -1;  //* loi: lastOccurenceIndex

    // lastOccurenceLTR(str, key, i, loi);
    // cout << "Last occurence is at: " << loi;

    //! -------------------------- RIGHT to LEFT
    // string str = "abcddedf";
    // char key = 'f';
    // int i = str.length() - 1;
    // int loi = -1;  //* loi: lastOccurenceIndex

    // lastOccurenceRTL(str, key, i, loi);
    // cout << "Last occurence is at: " << loi;
}