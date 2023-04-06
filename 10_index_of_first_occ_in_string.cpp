#include <iostream>
// using namespace std;
using std::cout;
using std::string;

int indexOfFirstOccInString(string heystack, string needle) {
    int n = heystack.size();
    int m = needle.size();

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < m; j++) {
            if (needle[j] != heystack[i + j]) break;

            if (j = m - 1) return i;
            //* j is fully matched with string and it has reached the
            //* end of second strto compare further.
        }
    }
    return -1;
}

int main() {
    string heystack = "sadbutsad";
    string needle = "sad";

    int ans = indexOfFirstOccInString(heystack, needle);
}
