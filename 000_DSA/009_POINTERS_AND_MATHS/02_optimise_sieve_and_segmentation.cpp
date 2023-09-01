//*
//* ◉ ● ⇒
//* --------------------------------------
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//? -------------------------- SIEVE OF ERATOSTHENES | NORMAL
vector<bool> sieve(int n) {
    // create sieve array of N prime telling isPrime
    vector<bool> sieveArr(n + 1, true);
    sieveArr[0] = sieveArr[1] = false;

    for (int i = 2; i <= n; i++) {
        int multiple = i * 2;  // starting from 2
        while (multiple <= n) {
            sieveArr[multiple] = false;
            multiple += i;
        }
    }

    return sieveArr;
}
//! TC:  N * log_log_N
//* by Taylors series of maths, if we add n/2 + n/3 + n/5 + n/7 + n/11 + ...
//* you'll get log_log_N
//! SC:  N

//? -------------------------- SIEVE OF ERATOSTHENES | 2 OPTIMISATIONS
vector<bool> sieve1(int n) {
    // create sieve array of N prime telling isPrime
    vector<bool> sieveArr(n + 1, true);
    sieveArr[0] = sieveArr[1] = false;

    //! OPTIMISATION 2 | OUTER LOOP ------------------------
    //* we're starting from 2, but we're taking the loop till n,
    //* which is not necessary. coz INNER loop is running is starting from i*i
    //* so, we shd run OUTER loop only till sqrt_n, coz suppose...
    //? if 'x' > sqrt(n)  |  multiple = i*i  |  and multiple runs
    //? while (i*i <= n), which will never happen in cases of x.
    for (int i = 2; i <= n; i++) {
        //! OPTIMISATION 1 | INNER LOOP ------------------------
        //* first unmarked number would be (i * i), not (i * 2), as others have
        //* been marked by 2 to (i - 1) already.
        int multiple = i * i;

        while (multiple <= n) {
            sieveArr[multiple] = false;
            multiple += i;
        }
    }

    return sieveArr;
}
//! TC:  N * log_log_N
//* no change here, as we consider the upper bound.
//! SC:  N

//? ------------------------------------------ SEGMENTED SIEVE
vector<bool> segSieve(int L, int R) {
    // get me prime arr, which I'll use to mark seg sieve
    vector<bool> sieveArr = sieve(sqrt(R));
    vector<int> basePrimes;

    for (int i = 0; i < sieveArr.size(); i++) {
        if (sieveArr[i]) basePrimes.push_back(i);
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 1 || L == 0) {
        segSieve[L] = false;
    }

    for (auto prime : basePrimes) {
        int first_mul = (L / prime) * prime;
        if (first_mul < L) first_mul += prime;

        int j = max(first_mul, prime * prime);
        while (j <= R) {
            segSieve[j - L] = false;
            j += prime;
        }
    }

    return segSieve;
}

int main() {
    //! ------------------------ NORMAL SIEVE | OPTIMISED SIEVE
    // vector<bool> sieveArr = sieve1(25);

    // for (int i = 0; i < 25; i++) {
    //     if (sieveArr[i]) cout << i << " ";
    // }

    //! ------------------------ SEGMENTED SIEVE
    // int L = 110, R = 130;
    // vector<bool> ss = segSieve(L, R);
    // for (int i = 0; i < ss.size(); i++) {
    //     if (ss[i]) cout << i + L << " ";
    // }
}