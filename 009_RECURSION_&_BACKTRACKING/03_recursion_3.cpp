#include <iostream>
#include <vector>
using namespace std;

bool isArraySorted(int arr[], int& n, int i) {
    if (i == n - 1) return true;  //* all are sorted
    if (arr[i + 1] < arr[i]) return false;
    return isArraySorted(arr, n, i + 1);
}

int binarySearch(vector<int>& arr, int s, int e, int& key) {
    if (s > e) return -1;  //* coz it should be (s <= e)

    int mid = s + (e - s) / 2;
    if (key == arr[mid]) {
        return mid;
    } else if (key > arr[mid]) {
        return binarySearch(arr, mid + 1, e, key);
    } else {
        return binarySearch(arr, s, mid - 1, key);
    }
}

void sequenceOfString(string& str, string& output, int i,
                      vector<string>& store) {
    if (i == str.length()) {
        store.push_back(output);  //* storing
        cout << output << ", ";   //* printing
        return;
    }

    //* here we're not doing anything as part of -> PROCESSING

    //? INCLUDING
    string newOutput = output + str[i];
    sequenceOfString(str, newOutput, i + 1, store);

    //? EXCLUDING
    sequenceOfString(str, output, i + 1, store);
}

int main() {
    //! -------------------------- is ARRAY SORTED
    // int arr[] = {10, 20, 30, 40, 50};
    // int n = 5, i = 0;

    // bool res = isArraySorted(arr, n, i);
    // cout << "Is sorted?: " << res;

    //! -------------------------- BINARY SEARCH
    // vector<int> arr = {10, 20, 30, 40, 50, 60};
    // int s = 0, e = arr.size() - 1;
    // int key = 200;

    // int res = binarySearch(arr, s, e, key);
    // cout << "Found at index: " << res;

    //! ---------------- SEQUENCE of STRING | INCLUDE or EXCLUDE
    // string str = "abcd";
    // string output = "";
    // vector<string> store;
    // int i = 0, n = str.length();

    // sequenceOfString(str, output, i, store);
    // cout << endl;
    // for (auto val : store) {
    //     cout << val << ", ";
    // }
}