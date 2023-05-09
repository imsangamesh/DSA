//*
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

// int findPivotElmInRotated(vector<int> arr) {
//     int s = 0, e = arr.size() - 1;

//     if (arr.size() == 1) return 0;

//     while (s <= e) {
//         int m = s + (e - s) / 2;

//         if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
//             return m;
//         }

//         if (arr[m] > arr[s]) {
//             s = m + 1;
//         } else {
//             e = m;
//         }
//     }
//     return -1;
// }

int findPivotElmInRotated(vector<int> arr) {
    int s = 0, e = arr.size() - 1;

    //* [9, 10, 2, 4, 6, 8]
    //* in this array, we'll handle
    //? ⍟ 2 special cases where the monotomy is breaking >> 10 & 2
    //! that is, where it's previous_elm > next_elm
    //* ● 10 case | when mid is at 10:
    //  here if (mid > mid + 1) return mid
    //* ● 2 case | when mid is at 2:
    //  here if (mid - 1 > mid) return mid - 1
    //? ⍟ and rest is same

    while (s <= e) {
        //* when at the end, if s & e are pointing to same elm
        if (s == e) return s;

        int m = s + (e - s) / 2;

        //* we're checking other cases, so that we won't go out of range
        if (arr[m] > arr[m + 1] && m <= e) return m;
        if (arr[m - 1] > arr[m] && m - 1 >= s) return m - 1;

        // here, if (mid > start), then wkt, we're on the 2nd line
        // soo move to left side--near mid.
        // else the other way around.
        if (arr[m] < arr[s]) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

int main() {
    //! ------------------------------ PIVOT in ROTATED arr
    vector<int> arr = {1, 3};

    int ans = findPivotElmInRotated(arr);
    cout << "Index is: " << ans << endl;
    cout << "Answer is: " << arr[ans] << endl;
}
