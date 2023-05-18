//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

//! /////// /////// /////// /////// ///////  GENERATE PARANTHESIS
void solve(vector<string>& ans, int n, int open, int close, string output) {
    // base case
    if (open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }

    //? INCLUDE open bracket
    if (open > 0) {
        output.push_back('(');
        solve(ans, n, open - 1, close, output);
        // backtracking
        output.pop_back();
    }

    //? INCLUDE close bracket
    if (close > open) {
        output.push_back(')');
        solve(ans, n, open, close - 1, output);
        // backtracking
        output.pop_back();
    }
}

vector<string> generateParanthesis(int n) {
    vector<string> ans;
    int open = n, close = n;
    string output = "";

    solve(ans, n, open, close, output);
    return ans;
}

//* /////// /////// /////// /////// /////// /////// /////// /////// ///////
//? /////// /////// /////// /////// /////// /////// /////// /////// ///////
//! /////// /////// /////// /////// /////// /////// /////// /////// ///////

void printVector(vector<string> arr) {
    for (auto val : arr) {
        cout << val << endl;
    }
}

int main() {
    cout << endl;
    int n = 4;
    //
    vector<string> ans = generateParanthesis(n);
    printVector(ans);
    //
    cout << endl << endl;
}