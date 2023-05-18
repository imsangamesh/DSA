//* 443. String Compression
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//! //////////////////////////////////////////
//! ///////// RUN LENGTH ENCODING ////////////
//! //////////////////////////////////////////
void printVector(vector<char> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int compress(vector<char>& chars) {
    if (chars.size() == 1) return 1;

    int index = 0;
    int i = 1, prev = 0;
    int count = 1;

    printVector(chars);
    while (i <= chars.size()) {
        cout << chars[prev] << " " << chars[i] << endl;

        if (i < chars.size() && chars[i] == chars[prev]) {
            //* prev == curr | just increment & move on
            count++;

            cout << "incremented to | " << count << "\n";
            //
        } else {
            //* we've found a new char, soo dump both 'char' & 'count'.
            cout << "dumping | " << count << "\n";

            chars[index++] = chars[prev];  // dump char

            if (count > 1) {  // dumping count.
                vector<char> temp;

                while (count) {  //* if count is of more_than_1 digits.
                    temp.push_back((count % 10) + '0');
                    count /= 10;
                }
                //* bcz, it was pushing in reverse order, I had to first
                //* store in temp and then push to our answer.
                for (int i = temp.size() - 1; i >= 0; i--) {
                    chars[index++] = temp[i];
                }
                //? --------------this or this----------------
                // string cnt = to_string(count);
                // for (auto ch : cnt) chars[index++] = ch;
            }
            count = 1;  // after dump, reset count to 1.
        }
        prev = i;
        i++;

        printVector(chars);
        cout << "\n";
    }

    return index;
}
//! TC:  N
//*
//! SC:  1

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'd', 'e', 'e'};
    chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    chars = {'a', 'a'};
    chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    //
    int ans = compress(chars);
    cout << "Answer is: " << ans;
    cout << "\n";
    printVector(chars);
}