#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

//? ------------------------- METHOD 1
void dutchNationalFlag(vector<int>& arr) {
    /*
    !TC:  n
    * you've to traverse the whole array to sort it
    !SC:  constant
    */
    int s = 0, e = arr.size() - 1;

    while (s < e) {
        if (arr[s] < 0) {
            s++;
        } else if (arr[e] > 0) {
            e--;
        } else {
            swap(arr[s], arr[e]);
        }
    }
}

//? ------------------------- METHOD 2

int main() {
    vector<int> arr = {-1, 5, 6, -2, -5, 10, -20};
    //
    dutchNationalFlag(arr);
    printVector(arr);
}