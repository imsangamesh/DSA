//* 279. Perfect Squares
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

int numSquares(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ans = INT_MAX;
    int i = 1;
    //* drawing out perfect squares
    while (i < sqrt(n)) {
        int perfectSquare = i * i;
        int numberOfPerfectSquare = 1 + numSquares(n - perfectSquare);
        if (numberOfPerfectSquare < ans) ans = numberOfPerfectSquare;
        i++;
    }

    return ans;
}
//! TC:  sqrt_N ^ N  >>  N ^ N
//* it is calling for sqrt_N branches.
//! SC:  N  (max_stacks)

int main() {
    int n = 12;

    int ans = numSquares(n);
    cout << "\nAnswer is: " << ans << "\n\n";
}