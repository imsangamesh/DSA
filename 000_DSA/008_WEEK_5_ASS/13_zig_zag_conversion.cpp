//* 6. Zigzag Conversion
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;

    //* creating vector_of_strings of length 'numRows'
    //* where each string represents a row.
    vector<string> zigzag(numRows);

    int i = 0, row = 0;  // iterates over original str.
    bool direction = 1;  // top to bottom

    //* we're checking i, inside loop, not in outer_while loop, coz
    //* we may, go inside the loop, and then if there are no elms to push,
    //* we can go out of bound there
    while (true) {
        if (direction) {
            //? top to bottom
            while (row < numRows && i < s.size()) {
                zigzag[row++].push_back(s[i++]);
                // pushing in curr_row
                // incrementing i
                // incrementing row
            }
            //* after reaching bottom, row = 3, so set it to 1st index
            row = numRows - 2;  // 3 - 2 = 1 (second_row)
        } else {
            //? bottom to top
            while (row >= 0 && i < s.size()) {
                zigzag[row--].push_back(s[i++]);
                // pushing in curr_row
                // incrementing i
                // decrementing row
            }
            //* after reaching top, row = 0, so set it to 1st index
            row = 1;  // second_row
        }
        if (i >= s.size()) break;
        direction = !direction;
    }

    string ans = "";
    for (auto str : zigzag) {
        ans += str;
    }

    return ans;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    //
    string ans = convert(s, numRows);
    cout << "Answer is: " << ans;
}