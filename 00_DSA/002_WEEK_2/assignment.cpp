#include <iostream>
using namespace std;

float areaOfCircle(float n);
bool isEven(int n);
bool isPrime(int n);
int factorial(int n);
int setKthBit(int a, int b);
float* celToFarh(int cel);

int main() {
    int n = 5;

    // cout << "Enter the value of n: ";
    // cin >> n;

    //! ------------------------------ HOLLOW HALF PYR
    // //? using while
    // int row = 0;
    // while (row < n) {
    //     int col = 0;
    //     while (col <= row) {
    //         if (col == 0 || col == row || row == n - 1) {
    //             cout << col + 1 << " ";
    //             col++;
    //         } else {
    //             cout << "  ";
    //             col++;
    //         }
    //     }
    //     cout << endl;
    //     row++;
    // }

    // //? using for
    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col <= row; col++) {
    //         if (col == 0 || row == n - 1 || row == col) {
    //             cout << col + 1 << " ";
    //         } else {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }
    //* 1
    //* 1 2
    //* 1   3
    //* 1     4
    //* 1 2 3 4 5

    //! ------------------------------ HOLLOW HALF PYR - INV - NOS
    // //? using while
    // int row = 0;
    // while (row < n) {
    //     int col = 0;
    //     while (col < n - row) {
    //         if (col == 0 || row == 0 || row + col == 4) {
    //             cout << col + row + 1 << " ";
    //             col++;
    //         } else {
    //             cout << "  ";
    //             col++;
    //         }
    //     }
    //     cout << endl;
    //     row++;
    // }
    // //? using for
    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col < n - row; col++) {
    //         if (row == 0 || col == 0 || row + col == 4) {
    //             cout << col + row + 1 << " ";
    //         } else {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }
    //* 1 2 3 4 5
    //* 2     5
    //* 3   5
    //* 4 5
    //* 5

    //! ------------------------------ NUM - PALINDROME - EQUILATERAL - PYR
    // //? using while
    // int row = 0;
    // while (row < n) {
    //     int col = 0;
    //     while (col < n - row - 1) {
    //         cout << "  ";
    //         col++;
    //     }

    //     col = 0;
    //     while (col <= row) {
    //         cout << col + 1 << " ";
    //         col++;
    //     }

    //     col = 0;
    //     while (col < row) {
    //         cout << row - col << " ";
    //         col++;
    //     }

    //     cout << endl;
    //     row++;
    // }
    // //? using for
    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col < n - row - 1; col++) {
    //         cout << "  ";
    //     }

    //     for (int col = 0; col <= row; col++) {
    //         cout << col + 1 << " ";
    //     }

    //     for (int col = 0; col < row; col++) {
    //         cout << row - col << " ";
    //     }

    //     cout << endl;
    // }

    //*         1
    //*       1 2 1
    //*     1 2 3 2 1
    //*   1 2 3 4 3 2 1
    //* 1 2 3 4 5 4 3 2 1

    //! ------------------------------ SOLID HALF DIAMOND
    // //? using while
    // int row = 0;
    // while (row < 2 * n - 1) {
    //     if (row < n) {
    //         int col = 0;
    //         while (col <= row) {
    //             cout << "* ";
    //             col++;
    //         }
    //     } else {
    //         int col = 0;
    //         while (col < n - 1 - (row - 5)) {
    //             cout << "* ";
    //             col++;
    //         }
    //     }
    //     cout << endl;
    //     row++;
    // }
    // //? using for
    // for (int row = 0; row < 2 * n - 1; row++) {
    //     if (row < n) {
    //         for (int col = 0; col <= row; col++) {
    //             cout << "* ";
    //         }
    //     } else {
    //         for (int col = 0; col < n - row + 4; col++) {
    //             //* col < n * 2 - 1 - row
    //             cout << "* ";
    //         }
    //     }
    //     cout << endl;
    // }

    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *

    //! ------------------------------ FANCY PATTERN 1
    // //? using while
    // int row = 0;
    // while (row < n) {
    //     int col = 0;
    //     while (col < 2 * (n - 1) - row) {
    //         cout << "*";
    //         col++;
    //     }

    //     col = 0;
    //     while (col <= row) {
    //         cout << col + 1;
    //         if (col != row) cout << "*";
    //         col++;
    //     }

    //     col = 0;
    //     while (col < 2 * n - row) {
    //         cout << "*";
    //         col++;
    //     }

    //     cout << endl;
    //     row++;
    // }

    // //? using for
    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col < 2 * (n - 1) - row; col++) {
    //         cout << "*";
    //     }

    //     for (int col = 0; col <= row; col++) {
    //         cout << col + 1;
    //         if (col != row) cout << "*";
    //     }

    //     for (int col = 0; col < 2 * (n - 1) - row; col++) {
    //         cout << "*";
    //     }

    //     cout << endl;
    // }
    // ********1********
    // *******1*2*******
    // ******1*2*3******
    // *****1*2*3*4*****
    // ****1*2*3*4*5****

    //! ------------------------------ FANCY PATTERN 2
    // //? using while
    // n = 4;
    // int row = 0, start = 1;
    // while (row < n) {
    //     int col = 0;
    //     while (col <= row) {
    //         cout << start;
    //         if (row != col) cout << "*";

    //         start++;
    //         col++;
    //     }

    //     cout << endl;
    //     row++;
    // }
    // row = 0;
    // while (row < n) {
    //     int col = 0;
    //     start = start - (n - row);
    //     while (col < n - row) {
    //         cout << start + col;
    //         if (col + row != n - 1) cout << "*";

    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // //? using for
    // n = 4;
    // int start = 1;
    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col <= row; col++) {
    //         cout << start;
    //         if (col != row) cout << "*";

    //         start++;
    //     }
    //     cout << endl;
    // }

    // for (int row = 0; row < n; row++) {
    //     start = start - (n - row);
    //     for (int col = 0; col < n - row; col++) {
    //         cout << start + col;
    //         if (col + row != n - 1) cout << "*";
    //         // if (col < n - 1 - row) cout << "*";
    //     }
    //     cout << endl;
    // }

    //* 1
    //* 2*3
    //* 4*5*6
    //* 7*8*9*10
    //* 7*8*9*10
    //* 4*5*6
    //* 2*3
    //* 1

    //! ------------------------------ FANCY PATTERN 3
    //? ON HOLD
    // *
    // * 1 *
    // * 1 2 1 *
    // * 1 2 3 2 1 *
    // * 1 2 1 *
    // * 1 *
    // *

    //! ------------------------------ FLOYD TRIANGLE
    // //? using while
    // int row = 0, start = 1;
    // while (row < n) {
    //     int col = 0;
    //     while (col <= row) {
    //         cout << start++ << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }
    //* 1
    //* 2 3
    //* 4 5 6
    //* 7 8 9 10
    //* 11 12 13 14 15

    //! ------------------------------ PASCALS TRIANGLE
    // //? using while
    // int row = 1;
    // while (row <= n) {
    //     int col = 1, bc = 1;
    //     while (col <= row) {
    //         cout << bc << " ";
    //         bc = bc * (row - col) / col;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }
    // //? using for
    // for (int row = 1; row <= n; row++) {
    //     int bc = 1;
    //     for (int col = 1; col <= row; col++) {
    //         cout << bc << " ";
    //         bc = bc * (row - col) / col;
    //     }
    //     cout << endl;
    // }
    //* 1
    //* 1 1
    //* 1 2 1
    //* 1 3 3 1
    //* 1 4 6 4 1

    //! ------------------------------ BUTTERFLY PATTERN
    //? ON HOLD

    //! ------------------------------ AREA OF CIRCLE
    // cout << "Area of circle of radius " << n << " is " << areaOfCircle(n)
    //      << endl;

    //! ------------------------------ ODD OR EVEN
    // if (isEven(n)) {
    //     cout << n << " is even" << endl;
    // } else {
    //     cout << n << " is odd" << endl;
    // }

    //! ------------------------------ FACTORIAL
    // cout << "factorial of " << n << " is " << factorial(n) << endl;

    //! ------------------------------ PRIME NO
    // if (isPrime(n)) {
    //     cout << n << " is prime" << endl;
    // } else {
    //     cout << n << " is not prime" << endl;
    // }

    //! ------------------------------ ALL PRIME NOS TILL N
    // n = 100;
    // for (int i = 0; i <= n; i++) {
    //     if (isPrime(i)) {
    //         cout << i << " ";
    //     }
    // }

    //! ------------------------------ REVERSE INTEGER
    // n = 123456789;
    // while (n > 0) {
    //     cout << n % 10;
    //     n = n / 10;
    // }

    //! ------------------------------ SET THE K th BIT
    // n = 11;
    // cout << "result after setting kth bit is " << setKthBit(n, 2) << endl;

    //! ------------------------------ CEL TO KELVIN TO FAH
    // cout << n << " degree = " << celToFarh(n)[0] << " kelvin" << endl;
    // cout << n << " degree = " << celToFarh(n)[1] << " farenheit" << endl;
}

float areaOfCircle(float r) { return r * r * 3.142; }

bool isEven(int n) { return n % 2 == 0; }

bool isPrime(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int factorial(int n) {
    int prod = 1;
    for (int i = n; i > 0; i--) {
        prod *= i;
    }
    return prod;
}

int setKthBit(int num, int k) { return num | 1 << k; }

float* celToFarh(int cel) {
    float arr[2];

    arr[0] = cel * 1.8 + 32;
    arr[1] = cel + 273.15;

    return arr;
}