#include <iostream>
#include <vector>

using namespace std;

int stringCompressor(vector<char>& chars) {
    int index = 0;
    int prev = chars[0], count = 1;

    for (int i = 1; i < chars.size(); i++) {
        if (chars[i] == prev) {
            count++;
        } else {
            //* we're storing the value of char only when
            //* previous is not equal to current -> chars[i]
            chars[index++] = prev;

            //* storing the count only if it is greater than 1
            //* we should also consider the case when count is 2-digit no
            if (count > 1) {
                string countStr = to_string(count);
                for (auto&& ch : countStr) chars[index++] = ch;
            }

            prev = chars[i];
            count = 1;
        }
    }

    chars[index++] = prev;
    if (count > 1) {
        string countStr = to_string(count);
        for (auto&& ch : countStr) chars[index++] = ch;
    }

    return index;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    // vector<char> chars = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
    //                       'a', 'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int ans = stringCompressor(chars);

    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << chars[i] << " ";
    }
}
