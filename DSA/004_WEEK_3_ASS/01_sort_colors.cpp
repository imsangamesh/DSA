//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------
//! /////// /////// /////// /////// /////// /////// ///////

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

//? ------------------------------- COUNT METHOD
// void sortColors(vector<int>& nums) {
//     int zeroes = 0, ones = 0, twos = 0;

//     // counting
//     for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] == 0) {
//             zeroes++;
//         } else if (nums[i] == 1) {
//             ones++;
//         } else if (nums[i] == 2) {
//             twos++;
//         }
//     }

//     // spreading
//     int i = 0;
//     while (zeroes--) {
//         nums[i] = 0;
//         i++;
//     }
//     while (ones--) {
//         nums[i] = 1;
//         i++;
//     }
//     while (twos--) {
//         nums[i] = 2;
//         i++;
//     }
// }

//? ------------------------------- IN_PLACE | 3 POINTER
void sortColors(vector<int>& nums) {
    int l = 0, m = 0, h = nums.size() - 1;

    while (m < h) {
        if (nums[m] == 0) {
            swap(nums[l], nums[m]);
            l++, m++;
        } else if (nums[m] == 1) {
            m++;
        } else {
            swap(nums[m], nums[h]);
            h--;
        }
    }
}

int main() {
    cout << endl;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    printVector(nums);
}