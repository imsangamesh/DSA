//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

//! steps to follow
//* 1. Find 'n' such that it is just >= Map.num
//* 2. if(n >= 100) find how many hundreds
//*    if(n < 100)  no need to do 2nd step

vector<pair<int, string>> mp = {
    {1000000000, "Billion"},
    {1000000, "Million"},
    {1000, "Thousand"},
    {100, "Hundred"},
    {90, "Ninety"},
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
    cout << "================\n";
    if (num == 0) return "Zero";

    //* getting the just_greater_pair & 'b_value'
    pair<int, string> myPair;
    for (auto it : mp) {
        if (num >= it.first) {
            myPair = it;
            break;
        }
    }

    string a = "";
    if (num >= 100) a = numberToWords(num / myPair.first) + " ";

    string b = myPair.second;

    string c = "";
    if (num % myPair.first != 0) {
        c = " " + numberToWords(num % myPair.first);
    }

    return a + b + c;
}
//! TC:  ceil ( log_base_10 ( N ))
//* TC  ===  no_of_words  ===  no_of_digits
//* soo,  no_of_digits = ceil ( log_base_10(N) )
//* soo..
//! SC:  ceil ( log_base_10 ( N ))
//* depth_of_stack = no_of_digits

int main() {
    int num = 1234567890;
    string ans = numberToWords(num);

    cout << "\nAnswer is: " << ans << "\n\n";
}