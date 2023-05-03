//*
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

int findSqrt(int num) {
    num = 25;
    int s = 0, e = num;
    double ans = 0;

    while (s <= e) {
        int m = s + (e - s) / 2;
        int sqr = m * m;

        if (sqr == num) {
            return m;
        }
        if (sqr > num) {
            e = m - 1;
        } else {
            ans = m;
            s = m + 1;
        }
    }
}

int main() {
    //
    cout << "Answer is: " << 404;
}