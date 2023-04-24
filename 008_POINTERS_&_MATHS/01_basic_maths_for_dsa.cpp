#include <iostream>
#include <vector>

using namespace std;

bool isPrime1(int num) {
    //? normal NAIVE method.
    //! TC: root_of_N | total TC: N * N
    if (num <= 1) return false;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return true;
    }
    return false;
}

bool isPrime2(int num) {
    //? square-root method - still NAIVE.
    //* for any non_prime number, we'll find at least 1 factor before
    // root_of_num,
    //* so let's check till root_of_num instead of n/2.
    //! TC: root_of_N | total TC: N * root_of_N
    if (num <= 1) return false;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return true;
    }
    return false;
}

//? ------------------------------------------------------------ PRIME
//? for method 1 & 2
int findPrimeCount(int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime1(i)) count++;
    }

    return count;
}

//? for SIEVE OF ERATOSTHENES method
int findPrimeCount2(int n) {
    //! TC: is N * log_log_N
    if (n == 0) return 0;

    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    int count = 0;

    for (int i = 2; i < n; i++) {  //! TC: N
        if (prime[i]) {
            count++;

            int multiple = i * 2;
            while (multiple < n) {  //! TC: log_log_N
                prime[multiple] = false;
                multiple += i;
            }
        }
    }
    return count;
}

//? ------------------------------------------------------------ GCD
int euclidGCD(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (a > 0 && b > 0) {
        a > b ? a = a - b : b = b - a;
    }

    return a == 0 ? b : a;
}

//? ------------------------------------------------------------ LCM
int findLCM(int a, int b) {
    //* wkt:  LCM(a, b) * GCD(a, b) = a*b
    //* soo: LCM(a, b) = a*b / GCD(a, b)

    return a * b / euclidGCD(a, b);
}

//? -------------------------------------- FAST EXPONENTIATION
int fastExponentiation(int a, int b) {
    int ans = 1;

    while (b > 0) {
        if (b & 1) ans = ans * a;  //* b == odd

        a = a * a;
        b >>= 1;  //* b = b / 2;
    }

    return ans;
}

int main() {
    //! --------------------------- PRIME - better ways
    // int n = 100000;

    // int result = findPrimeCount1(n);
    // int result = findPrimeCount2(n);
    // cout << "Prime count is: " << result;

    //! --------------------------- GCD - better ways
    // int a = 72, b = 48;

    // int result = euclidGCD(a, b);
    // cout << "GCD is: " << result;

    //! --------------------------- LCM - better ways
    // int a = 2, b = 3;

    // int result = findLCM(a, b);
    // cout << "LCM is: " << result;

    //! --------------------------- MODULO ARITHMETIC
    /*
     * (a % n)  ->  [0, .... n-1]
     * generally to avoid overflow while storing integer, we do modulo with
     * Large number.
     *
     * 1. (a + b) % M = a % M + b % M
     * 2. a % M - b % M = (a - b) % M
     * 3. ((a % M) % M) % M = a % M
     * 4. a % M * b % M = (a * b) % M)
     */

    //! --------------------------- FAST EXPONENTIATION
    //? this is normally to find the power of a

    // int result = fastExponentiation(2, 3);
    // cout << "Answer is: " << result;
}
