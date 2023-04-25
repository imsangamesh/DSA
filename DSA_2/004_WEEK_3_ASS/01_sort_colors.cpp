//* LEET_CODE - DONE

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

//? ------------------------------ FIRST METHOD
void countAndSpread(vector<int>& nums) {
    /*
    !TC:  n+n  >>  n
    * n : first 'for' loop
    * n : no_of_0 + no_of_1 + no_of_2  >>  n
    !SC:  000
    */
    int zeroes = 0, ones = 0, twos = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            zeroes++;
        } else if (nums[i] == 1) {
            ones++;
        } else {
            twos++;
        }
    }

    int i = 0;
    while (zeroes--) {
        nums[i] = 0;
        i++;
    }
    while (ones--) {
        nums[i] = 1;
        i++;
    }
    while (twos--) {
        nums[i] = 2;
        i++;
    }

    printVector(nums);
}

void sortColors(vector<int> nums) {
    int s = 0, e = nums.size() - 1, m = 0;

    while (m <= e) {
        if (nums[m] == 0) {
            swap(nums[s], nums[m]);
            s++;
            m++;
        } else if (nums[m] == 2) {
            swap(nums[m], nums[e]);
            e--;
        } else {
            m++;
        }
    }
    printVector(nums);
}

void sortColorsFor4Nums(vector<int> nums) {
    int a = 0, b = 0, c = 0;
    int d = nums.size() - 1;

    while (c <= d) {
        if (nums[c] == 0) {
            swap(nums[c], nums[a]);
            a++;
            b++;
            c++;
        } else if (nums[c] == 1) {
            swap(nums[c], nums[b]);
            b++;
        } else if (nums[c] == 3) {
            swap(nums[c], nums[d]);
            d--;
        } else {
            c++;
        }
    }
    printVector(nums);
}

int main() {
    // vector<int> arr{2, 0, 2, 0, 2, 1, 0, 1, 1, 2, 0, 0, 2};
    vector<int> brr{3, 3, 1, 3, 2, 3, 1, 1, 0, 0, 0, 0, 3, 2};
    //
    // sortColors(arr);
    // cout << "\n\n";
    sortColorsFor4Nums(brr);
}