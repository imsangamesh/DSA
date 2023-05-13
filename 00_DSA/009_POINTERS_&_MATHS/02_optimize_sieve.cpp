#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int n) {
    //* creating sieve array of N size telling isPrime
    // ! TC: n_log(log_n)
    vector<bool> arr(n + 1, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i <= n; i++) {
        if (arr[i] == true) {
            int multiple = i * 2;
            while (multiple <= n) {
                cout << "----------\n";
                arr[multiple] = false;
                multiple += i;
            }
        }
    }
    return arr;
}

vector<bool> sieveOptimisationInnerLoop(int n) {
    //* creating sieve array of N size telling isPrime
    vector<bool> arr(n + 1, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i <= n; i++) {
        if (arr[i] == true) {
            int multiple = i * i;
            while (multiple <= n) {
                //? ----------------- OPTIMIZATION 1 - on inner loop
                /*
                 * we're seeing that
                 * for 2 we're starting from 2*2
                 ? so for 3, let's start from 3*3
                 ? llly for 4, let's start from 4*4
                 ? and so on.
                 ! TC: n_log(log_n)
                 */
                cout << "----------\n";
                arr[multiple] = false;
                multiple += i;
            }
        }
    }
    return arr;
}

vector<bool> sieveOptimisationOuterLoop(int n) {
    //* creating sieve array of N size telling isPrime
    vector<bool> arr(n + 1, true);
    arr[0] = arr[1] = false;

    int i = 2;
    while (i * i <= 25) {
        if (arr[i] == true) {
            int multiple = i * i;
            while (multiple <= n) {
                //? ----------------- OPTIMIZATION 1 - on inner loop
                /*
                 * here now after optimising inner loop, we're seeing that,
                 * the inner loop is running for numbers(i) whose square
                 * value(i*i) is greater than 25(n). which is definitely not
                 * needed.
                 ? soo let's tell outer loop to run the loop only till root(n)
                 ? i.e, in this case it would be root(25) = till 5
                 ! TC: n_log(log_n)
                 */
                cout << "----------\n";
                arr[multiple] = false;
                multiple += i;
            }
            i++;
        }
    }
    return arr;
}

vector<bool> segmentSieve(int l, int r) {
    //* get me prime array, I will use it to mark Segment Sieve
    vector<bool> sieve = sieveOptimisationOuterLoop(sqrt(r));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i]) basePrimes.push_back(i);
    }
    /*
    ! I WAS BORED & I WAS NOT GETTING ANYTHING
    ! coz HE COVERED THIS IN like 2 or 3 VIDEOS kinda HARD TO CONNECT
    ! & I WAS EXCITED FOR  -->  "RECURSION & BACKTRACKING"
    */
}

int main() {
    //? this is the old process.
    // vector<bool> result = sieve(25);
    // vector<bool> result = sieveOptimisationInnerLoop(25);
    vector<bool> result = sieveOptimisationOuterLoop(25);

    for (int i = 0; i < result.size(); i++) {
        if (result[i]) cout << i << " ";
    }
}
