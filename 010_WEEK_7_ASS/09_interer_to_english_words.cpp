#include <iostream>
#include <vector>
using namespace std;

/*
! steps to follow
* 1. Find 'n' such that it is just >= Map.num
* 2. if(n >= 100) find how many hundreds
*    if(n < 100)  no need to do 2nd
*/

vector<pair<int, string>> mp = {
    {1000000000, "Billion"},
    {1000000, "Million"},
    {1000, "Thousand"},
    {100, "Hundred"},
    {90, "Ninty"},
    {80, "Eighty"},
    {70, "Seventy"},
    {60, "Sixty"},
    {50, "Fifty"},
    {40, "Forty"},
    {30, "Thirty"},
    {20, "Twenty"},
    {19, "Nineteen"},
    {18, "Eighteen"},
    {17, "Seventeen"},
    {16, "Sixteen"},
    {15, "Fifteen"},
    {14, "Fourteen"},
    {13, "Thirteen"},
    {12, "Twelve"},
    {11, "Eleven"},
    {10, "Ten"},
    {9, "Nine"},
    {8, "Eight"},
    {7, "Seven"},
    {6, "Six"},
    {5, "Five"},
    {4, "Four"},
    {3, "Three"},
    {2, "Two"},
    {1, "One"},
};

string numberToWords(int num) {
    if (num == 0) "Zero";

    for (auto it : mp) {
        if (num >= it.first) {
            //? ----------------- a STRING_PART
            string a = "";
            if (num >= 100) {
                a = numberToWords(num / it.first);
            }

            //? ----------------- b STRING_PART
            string b = it.second;

            //? ----------------- c STRING_PART
            string c = "";
            if (num % it.first != 0) {
                c = numberToWords(num % it.first);
            }

            return a + " " + b + " " + c;
        }
    }

    return "";
}
/*
* TC:  log(n)  base_10  (no_of_digits)
! TC === no_of_words
! no_of_words === no_of_digits
! no_of_digits = ceil( log(n) base_10 )
!
! soo, TC === ceil( log(n) base_10 )
! TC === log(n) base_10
* SC:  log(n)  base_10  (no_of_digits)
! same reason as TC
*/

int main() {
    int num = 12345;
    //
    string ans = numberToWords(num);
    cout << "Answer is: " << ans;
}