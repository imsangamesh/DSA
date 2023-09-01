//*
//* ◉ ● ⇒
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
}

int main() {
    //! ---------------------------------- SELECTION SORT
    // vector<int> arr = {10, 4, 6, 7, 9, 1, 2, 5, 11};

    // for (int i = 0; i < arr.size() - 1; i++) {
    //     int min = i;
    //     for (int j = i; j < arr.size(); j++) {
    //         if (arr[min] > arr[j]) min = j;
    //     }
    //     swap(arr[i], arr[min]);
    // }
    // printVector(arr);
    // //! TC:  n^2
    // //! UNSTABLE
    // //! you're placing shortest elm to it's place for each round
    // //* here we've got 2 loops:
    // //? ◉ 1st: outer loop
    // //* this loop iterates through all N elms  >>  N
    // //? ◉ 2nd: inner loop
    // //* this loop iterates for N-i times >> N
    // //* soo, totally = n + (n-1) + (n-2) + ... + 2 + 1 >> N(N+1) / 2   >> N^2
    // //? ⇒ finally  N^2 + N  >>>  N^2
    // //! SC:  constant

    //! ---------------------------------- BUBBLE SORT
    // vector<int> arr = {100, 40, 6, 7, 9, 1, 2, 5, 11};

    // for (int i = 0; i < arr.size(); i++) {
    //     for (int j = 0; j < arr.size() - i; j++) {
    //         if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    //     }
    // }
    // printVector(arr);
    // //! TC:  n^2
    // //! STABLE
    // //! for sorted array:  N  (best_case)
    // //! you're placing largest elm to it's place for each round
    // //* here we've got 2 loops:
    // //? ◉ 1st: outer loop
    // //* this loop iterates through all N elms  >>  N
    // //? ◉ 2nd: inner loop
    // //* this loop iterates from  0  to  N-i
    // //* soo, totally = n + (n-1) + (n-2) + ... + 2 + 1 >> N(N+1) / 2   >> N^2
    // //? ⇒ finally  N^2 + N  >>>  N^2
    // //! SC:  constant

    //! ---------------------------------- INSERTION SORT
    // //! FCFS:
    // //* ◉ 1. fetch curr_elm
    // //* ◉ 2. compare elm with previously sorted elms
    // //* ◉ 3. shift the elms once correct elm pos is found
    // //* ◉ 4. insert the curr_elm in the correct pos

    // vector<int> arr = {10, 9, 7, 1, 2, 5, 11};

    // for (int round = 1; round < arr.size(); round++) {
    //     //? 1. fetching
    //     int val = arr[round];

    //     //? 2. comparing & find pos
    //     int j = round - 1;
    //     while (arr[j] > val) {
    //         //? 3. shifting elms
    //         arr[j + 1] = arr[j];
    //         j--;
    //     }

    //     //? 4. inserting the curr_elm
    //     arr[j + 1] = val;
    // }
    // printVector(arr);
    // //! TC:  N^2
    // //! STABLE
    // //! for sorted array:  N  (best_case)
    // //? ◉ 1st: outer loop
    // //* it is iterating for every elm
    // //? ◉ 1st: outer loop
    // //* it is iterating till it finds, previous_no < itself,
    // //* which means, previous elms are sorted.
    // //* and after finding the position where (previous_no < itself),
    // //* it stops & it loops to shift the elms forward & insert curr elm.
    // //! SC:  constant
}