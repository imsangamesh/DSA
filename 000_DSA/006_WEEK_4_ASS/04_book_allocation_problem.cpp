//* GFG. Allocate minimum number of pages
//* ◉ ● ⇒
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool isAllocationPossible(int A[], int N, int M, int guessedSol) {
    //! guessedSol is guessed no of pages.
    int pageSum = 0;
    int studCount = 1;  // start allocating from 1st stud.

    for (int i = 0; i < N; i++) {
        //* if no_of_pages in curr book exceed guessed_sol
        if (A[i] > guessedSol) return false;

        if (pageSum + A[i] > guessedSol) {
            //* if pageSum exceed for 1 stud, move to allocate for next stud.
            studCount++;  // next stud.

            //* starting the new_page_sum for next stud.
            pageSum = A[i];

            //* after moving to next stud, we shd check whether
            //* we've exceeded the given_stud_count
            if (studCount > M) return false;

        }

        // everything is fine.
        else {
            pageSum += A[i];
        }
    }
    // all pages are assigned successfully.
    return true;
}

int findMinimumNoOfPages(int A[], int N, int M) {
    // if num of studs > num of books
    if (M > N) return -1;

    // accumulate is used to find sum of elms_of_array
    int start = 0, end = accumulate(A, A + N, 0);
    //*s we're assuming that, "what if we give all planks to one painter?"
    //*s where he'll take 'end' time.
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isAllocationPossible(A, N, M, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int N = 4;  // no of books.
    int M = 2;  // no of students.
    //
    int ans = findMinimumNoOfPages(arr, N, M);
    cout << "Answer is: " << ans;
}