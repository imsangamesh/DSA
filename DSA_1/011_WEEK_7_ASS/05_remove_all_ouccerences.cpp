#include <iostream>
#include <vector>
using namespace std;

void removeOccOfAllParts(string& str, string& part) {
    int pos = str.find(part);
    if (pos != string::npos) {
        /*
         * part string has been located | remove it.
         * we are removing the 'part' by concatenating first_part & last_part
         * leaving middle_part which is 'part'.
         */
        string left_part = str.substr(0, pos);
        string right_part = str.substr(pos + part.length(), str.length());
        str = left_part + right_part;
        //! str.erase(pos, part.length());
        //! we can use this above line rather than 3lines.

        removeOccOfAllParts(str, part);
    } else {
        //! ------------- BASE_CASE
        //! all the occurences have been removed
        //? coz ( 'pos' == string::npos )
        //* so do nothing!
    }
}
/*
* TC: n*m
! 1. find key >  n*m  | n:size_of_str | m:size_of_part
! - bcz we will compare every char of 'part' in 'str'
! 2. to_form_left_part  >  n
! 3. to_form_right_part  >  n
! 4. total recursive calls  >  n/m
! - this is when we receive 'part' everytime in 'str'

* SC: n/m
! - coz we are recursing n/m times.
*/

int main() {
    string str = "daabcbaabcbc", part = "abc";
    //
    removeOccOfAllParts(str, part);
    cout << "Answer is: " << str;
}