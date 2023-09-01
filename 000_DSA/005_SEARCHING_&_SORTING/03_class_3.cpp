//*
//* ⍟ ◉ ● ⇒
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int nearlySortedArray(vector<int> arr, int target) {
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        cout << "\nmid: " << mid;
        cout << "\ns: " << s;
        cout << "\ne: " << e;
        cout << "\n\n";

        if (arr[mid] == target) return mid;
        if (arr[mid - 1] == target) return mid - 1;
        if (arr[mid + 1] == target) return mid + 1;

        //? To REMEMBER ==================
        //* moving 'e' or 's' by 2 places
        if (arr[mid] > target) {
            e = mid - 2;
        } else {
            s = mid + 2;
        }
    }
    return -1;
}

double binaryDivision(int dvnd, int dvsr) {
    int s = 0, e = dvnd;
    double ans = 0;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (m * dvsr == dvnd) return m;

        if (m * dvsr > dvnd) {
            e = m - 1;
        } else {
            ans = m;
            s = m + 1;
        }
    }

    int precision = 10;
    double step = 0.1;

    for (int i = 0; i < precision; i++) {
        for (double num = ans + step; num * dvsr <= dvnd; num += step) {
            ans = num;
        }
        step /= 10;
    }
    return ans;
}

int findOddTimesOccNo(vector<int> arr) {
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return mid;
        }

        //* we could see that:
        //
        //* LEFT of target ------------
        //? ● 'even' >> 'odd'
        //* RIGHT of target ------------
        //? ● 'odd' >> 'even'

        if (mid % 2 == 0) {
            // mid is EVEN
            if (arr[mid] == arr[mid - 1]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else {
            // mid is ODD
            if (arr[mid] == arr[mid - 1]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    //! ---------------------------- NEARLY SORTED ARR
    // vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    // int target = 3;
    //
    // int ans = nearlySortedArray(arr, target);
    // cout << "Answer is: " << ans;

    //! ---------------------------- DIVISION
    // int dvnd = 34, dvsr = 7;

    // double ans = binaryDivision(dvnd, dvsr);
    // cout << "Answer is: " << setprecision(10) << ans;

    //! ------------------------------ ODD OCCURING NO
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 60, 60, 4, 4};

    // //? XOR method with O(n) = n - BAD
    // int ans = 0;
    // for (int i = 0; i < arr.size(); i++) {
    //     ans ^= arr[i];
    // }
    // cout << ans << endl;

    // //? binary search method
    int ans = findOddTimesOccNo(arr);
    cout << "Index is: " << ans << endl;
    cout << "Answer is: " << arr[ans] << endl;
}