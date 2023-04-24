#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int numSquares(int n) {
    if (n <= 0) return 0;

    int i = 1;
    int ans = INT_MAX;

    while (i <= sqrt(n)) {
        int perfectSquare = i * i;
        int numberOfPerfectSquares = 1 + numSquares(n - perfectSquare);
        if (numberOfPerfectSquares < ans) {
            ans = numberOfPerfectSquares;
        }
        i++;
    }
    return ans;
}

int main() {
    int num = 1;
    //
    int ans = numSquares(num);
    cout << "Answer is: " << ans;
}