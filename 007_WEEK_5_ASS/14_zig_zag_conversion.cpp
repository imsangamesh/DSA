#include <iostream>
#include <string>
#include <vector>
using namespace std;

string zigZigConversion(string str, int numRows) {
    if (numRows == 1) return str;

    vector<string> zigzag(numRows);

    int i = 0, row = 0;
    bool direction = 1;  //? 1 -> Top to Bottom

    while (true) {
        if (direction) {
            while (row < numRows && i < str.size()) {
                zigzag[row++].push_back(str[i++]);
            }
            row -= 2;  //* setting row back to "last-1" row
        } else {
            while (row >= 0 && i < str.size()) {
                zigzag[row--].push_back(str[i++]);
            }
            row = 1;  //* setting row back to 1 (not 0)
        }

        if (i >= str.size()) break;
        direction = !direction;
    }

    string ans = "";
    for (int i = 0; i < zigzag.size(); i++) {
        ans += zigzag[i];
        cout << zigzag[i] << endl;
    }

    return ans;
}

int main() {
    string str = "PAYPALISHIRING";
    str = "ABCDEFG";

    string res = zigZigConversion(str, 3);
    cout << "Answer is: " << res;
}