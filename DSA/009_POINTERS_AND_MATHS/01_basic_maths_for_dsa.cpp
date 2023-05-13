//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//? 3. SIEVE OF ERATOSTHENES
//? 4. SEGMENTED SIEVE

//! ////////// //////////  ////////// //////////  PRIME NUMBERS COUNT

//? ------------------------------------------ NIEVE APPROACH
bool isPrime1(int n) {
    if (n <= 1) return false;
    for (int i = 0; i <= n / 2; i++) {  //!  N * N
        if (n % i == 0) return false;
    }
    return true;
}

//? ------------------------------------------ SQRT APPROACH
bool isPrime2(int n) {
    if (n <= 1) return false;

    //* running loop only till sqrt(n)
    for (int i = 0; i <= sqrt(n); i++) {  //!  N * sqrt(N)
        if (n % i == 0) return false;
    }
    return true;
}

//? ----------------------------- NORMAL | METHOD 1
int countPrimes1(int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {  //!  N
        if (isPrime1(i)) count++;  //!  N * N
    }
    return count;
}

//? ------------------ SIEVE OF ERATOSTHENES | METHOD 2
int sieveEratosthenesMethod(int n) {
    if (n <= 1) return 0;

    vector<bool> primes(n, true);  //* setting  all to TRUE
    primes[0] = primes[1] = false;
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (primes[i]) {  // if num is prime only
            count++;

            int j = 2 * i;  // starting from 2nd multiple
            while (j < n) {
                primes[j] = false;  //* setting non-prime
                j += i;
            }
        }
    }
    return count;
}
//! TC:  N * log_log_N
//* by Taylors series of maths, if we add n/2 + n/3 + n/5 + n/7 + n/11 + ...
//* you'll get log_log_N
//! SC:  N

//! ////////// //////////  ////////// GFG | GCD of two numbers
int gcd(int A, int B) {
    if (A == 0) return B;
    if (B == 0) return A;

    while (A > 0 && B > 0) {
        if (A > B) {
            A = A - B;
        } else {
            B = B - A;
        }
    }

    //* if loop has exited, it means, anyone of them has become 0
    return A == 0 ? B : A;
}

//! ////////// //////////  ////////// LCD of two numbers
int lcm(int A, int B) {
    //* lcm(a, b) * gcd(a, b) = a * b;
    return A * B / gcd(A, B);
}

//! ////////// //////////  ////////// FAST EXPONENTIATION

//? ------------------ SLOW METHOD
int slowExponentiation(int a, int b) {
    int ans = 1;
    for (int i = 0; i < b; i++) {  //! O(b)
        ans *= a;
    }
    return ans;
}

//? ------------------ SLOW METHOD
int fastExponentiation(int a, int b) {
    int ans = 1;

    while (b > 0) {
        if (b & 1) ans = ans * a;  // odd
        a = a * a;
        b >>= 1;  // b = b / 2
    }

    return ans;
}

int main() {
    //! ------------------------------------ 204. Count Primes
    // int n = 500;

    // int ans = countPrimes1(n);
    // ans = sieveEratosthenesMethod(n);
    // cout << "Answer is: " << ans;

    //! ------------------------------------ find GCD
    // int a = 24, b = 72;

    // int ans = gcd(a, b);
    // cout << "Answer is: " << ans;

    //! ------------------------------------ find LCM
    // int a = 24, b = 72;

    // int ans = lcm(a, b);
    // cout << "Answer is: " << ans;

    //! ------------------------------------ MODULO ARITHMETIC
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
    //! ------------------------------------ FAST EXPONENTIATION
    //? SLOW METHOD
    // int a = 10, b = 5;

    // int ans = slowExponentiation(a, b);
    // cout << "Answer is: " << ans;

    //? FAST METHOD
    // int a = 10, b = 5;

    // int ans = fastExponentiation(a, b);
    // cout << "Answer is: " << ans;
}

//! ////////// //////////  ////////// //////////
//! ////////// have to get back to it //////////
//! ////////// //////////  ////////// //////////
