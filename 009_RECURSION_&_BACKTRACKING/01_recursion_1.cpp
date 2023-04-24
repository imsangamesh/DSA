#include <iostream>
using namespace std;

//! -------------------------- PRINTING COUNT
void printCount(int n) {
    if (n == 0) return;  //* BASE CASE
    cout << n << " ";    //* PROCESSING
    printCount(n - 1);   //* RECURSING_RELATION
}

//! -------------------------- POWER OF 2
int powerOf2(int n) {
    if (n == 1) return 2;  //* BASE CASE
    return 2 * powerOf2(n - 1);
    //* PROCESSING & RECURSING_RELATION
}

//! -------------------------- FACTORIAL
int factorial(int n) {
    if (n == 1) return 1;  //* BASE CASE
    return n * factorial(n - 1);
    //* PROCESSING & RECURSING_RELATION
}

//! -------------------------- FIBONACCI
int fibonacci(int n) {
    if (n == 0 || n == 1) return n;  //* BASE CASE
    return fibonacci(n - 1) + fibonacci(n - 2);
    //* PROCESSING & RECURSING_RELATION
}

int main() {
    cout << "\n";
    printCount(10);

    int res = powerOf2(10);
    cout << "\n\nPower of 2^10 is: " << res;

    res = factorial(5);
    cout << "\n\nFactorial of 5 is: " << res;

    res = fibonacci(10);
    cout << "\n\nFibonacci of 10 is: " << res;
    cout << "\n\n";
}