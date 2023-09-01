//* GFG. Add two no.s represented by arrays
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

void addTwoArrays() {
    vector<int> arr = {0, 0, 9, 5, 4, 9};
    vector<int> brr = {0, 0, 2, 1, 4};
    vector<int> ans;

    int a = arr.size() - 1, b = brr.size() - 1;
    int carry = 0;

    while (a >= 0 && b >= 0) {
        int sum = arr[a] + brr[b] + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
        a--;
        b--;
    }

    while (a >= 0) {
        int sum = arr[a] + 0 + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
        a--;
    }

    while (b >= 0) {
        int sum = 0 + brr[b] + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
        b--;
    }

    while (carry) {
        ans.insert(ans.begin(), carry);
        carry /= 10;
    }

    int i = 0;
    while (ans[i] == 0) {
        ans.erase(ans.begin());
    }

    printVector(ans);
}

void factorialOfLargeNo() {
    int number = 6;
    int carry = 0;

    vector<int> ans;
    ans.push_back(1);

    for (int num = 2; num <= number; num++) {
        //
        int i = ans.size() - 1;
        while (i >= 0) {
            int prod = ans[i] * num + carry;
            ans[i] = prod % 10;
            carry = prod / 10;
            i--;
        }

        while (carry) {
            ans.insert(ans.begin(), carry % 10);
            carry /= 10;
        }
    }
    printVector(ans);
}

int main() {
    //
    // addTwoArrays();
    factorialOfLargeNo();
}