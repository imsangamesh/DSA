//*
//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

void negativeMarking(vector<int>& arr) {
    //? negative marking & tracing which is not -ve
    //* here we're marking the respective indexed no.s -ve and after marking all
    //* no.s check which no. is not marked as negative. then that index is
    //* missing, coz in case if we had that 'index' in array, we'd be marking
    //* that index as 'visited'. so now it's not marked--which indicates, it is
    //* missing.

    for (int i = 0; i < arr.size(); i++) {
        int index = abs(arr[i]) - 1;

        if (arr[index] > 0) {
            arr[index] *= -1;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            cout << i + 1 << " ";
        }
    }
}

void sendingToTheirIndexes(vector<int>& arr) {
    //? sending no.s to their indexes & tracing
    //* here we're sending all the no.s to their respective indexes.
    //* we're also looping till a particular no has reached it's respective
    //* 'index'. soo we're using 'while' loop and only incrementing 'i' value
    //* only when a particular no. is it's respective index.
    int i = 0;
    while (i < arr.size()) {
        int index = arr[i] - 1;

        if (arr[index] != arr[i]) {
            swap(arr[index], arr[i]);
        } else {
            i++;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != i + 1) cout << i + 1 << " ";
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 3, 4};
    arr = {3, 3, 3, 3, 3};
    //
    // negativeMarking(arr);
    sendingToTheirIndexes(arr);
}