//* ⍟ ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int negativeMarking(vector<int>& arr) {
    //? making the elements -ve  |  arr MODIFIED
    //* here we're to their respective 'index' and making it -ve - which
    //* indicates as 'visited', soo for the duplicate no. we'll go to same index
    //* twice to mark it as 'visited' & there we'll get the duplicate no.

    for (int i = 0; i < arr.size(); i++) {
        int index = abs(arr[i]);

        if (arr[index] < 0) {
            return index;
        } else {
            arr[index] *= -1;
        }
    }
    return -1;
}

int sendingToTheirIndexes(vector<int>& arr) {
    //? sending the no.s to their indexes  |  arr MODIFIED
    //* here we're sending the no.s to their respective 'indexes', only till we
    //* encounter the situation -- where we see the respective no. in it's
    //* position already. so this only means, we're visiting this for 2nd time.
    //* so this is the answer, soo we've found the answer, so we stop. and
    //* answer is at 1st index.

    while (arr[arr[0]] != arr[0]) {
        swap(arr[arr[0]], arr[0]);
    }
    return arr[0];
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 4};
    //
    int ans = negativeMarking(arr);
    // int ans = sendingToTheirIndexes(arr);
    cout << "\nAnswer is: " << ans;
}