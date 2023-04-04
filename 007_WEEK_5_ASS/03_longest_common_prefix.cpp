using namespace std;
#include <iostream>
#include <string>
#include <vector>

string longestCommonPrefix(vector<string> arr) {
    // string currChar = "";
    // string ans = "";

    // int i = 0;
    // while (true) {
    //     currChar = arr[0][i];

    //     for (int j = 0; j < arr.size(); j++) {
    //         if (arr[j][i] != currChar) {
    //             return ans;
    //         } else {
    //             ans.push_back(arr[j][i]);
    //             i++;
    //         }
    //     }
    // }

    string ans;

    int i = 0;
    while (true) {
        char currChar = 0;

        for (auto &&str : arr) {
            if (i >= str.size()) {
                currChar = 0;
                break;
            }

            if (currChar == 0) {
                currChar = str[i];
            } else if (str[i] != currChar) {
                currChar = 0;
                break;
            }
        }

        if (currChar == 0) break;

        ans.push_back(currChar);
        i++;
    }
    return ans;
}

int main() {
    vector<string> arr = {"flower", "flight", "flow"};

    string ans = longestCommonPrefix(arr);

    if (ans == "") {
        cout << "No common prefixes found";
    } else {
        cout << "Answer is: " << ans;
    }
}