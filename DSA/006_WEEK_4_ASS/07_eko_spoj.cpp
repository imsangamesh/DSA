//*
//* ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int trees[], int n, int M, int sawHeight) {
    long long int totalMeters = 0;

    for (long long int i = 0; i < n; i++) {
        if (trees[i] > sawHeight) {
            // height_of_tree - saw_blade_height
            long long int wood = trees[i] - sawHeight;
            totalMeters += wood;
        }
    }

    return totalMeters >= M;
}

long long int findMax(int trees[], int n) {
    long long int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (trees[i] > maxi) maxi = trees[i];
    }
    return maxi;
}

long long int findHeight(int trees[], int n, int M) {
    //* suppose, we set the height of blade as 0,
    //* then we'll cut the trees from bottom, which is not ecological.
    long long int start = 0;
    long long int end = findMax(trees, n);
    // end = *max_element(trees.begin(), trees.end());
    //* end is, what is the max height of saw_blade we can set to cut 0 wood.
    //* which is, if we set it to height_of_tallest_tree, no wood will be cut.
    long long int ans = -1;

    while (start <= end) {
        long long int mid = start + (end - start) / 2;

        if (isPossible(trees, n, M, mid)) {
            // taking blade higher, to see for any optimisation
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int trees[] = {20, 15, 10, 17};
    int n = 4;  // no of trees.
    int M = 7;  // meters of wood needed.
    //
    int ans = findHeight(trees, n, M);
    cout << "Answer is: " << ans;
}