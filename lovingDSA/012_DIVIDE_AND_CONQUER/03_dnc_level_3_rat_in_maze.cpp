//*
//* ◉ ● ⇒
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

//! /////// /////// /////// /////// /////// /////// /////// RAT IN A MAZE

bool isSafe(int i, int j, int row, int col, int arr[][3],
            vector<vector<bool>>& visited) {
    if (                                                 //
        ((i >= 0 && i < row) && (j >= 0 && j < col)) &&  // stay in bound
        (arr[i][j] == 1) &&                              // traversal allowed
        (visited[i][j] == false)                         // not visited
    ) {
        return true;
    }
    return false;
}

void solveMaze(int arr[][3], int row, int col, int i, int j,
               vector<vector<bool>>& visited, vector<string>& path,
               string output) {
    //? base case
    if (i == row - 1 && j == col - 1) {
        path.push_back(output);  //* answer found
        return;
    }

    //? Down  ->  i+1, j
    if (isSafe(i + 1, j, row, col, arr, visited)) {
        // mark visited & goto next step
        visited[i + 1][j] = true;
        solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D');

        //* backtracking  ->  to restore originality
        visited[i + 1][j] = false;
    }

    //? Left  ->  i, j-1
    if (isSafe(i, j - 1, row, col, arr, visited)) {
        // mark visited & goto next step
        visited[i][j - 1] = true;
        solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');

        //* backtracking  ->  to restore originality
        visited[i][j - 1] = false;
    }

    //? Right ->  i, j+1
    if (isSafe(i, j + 1, row, col, arr, visited)) {
        // mark visited & goto next step
        visited[i][j + 1] = true;
        solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');

        //* backtracking  ->  to restore originality
        visited[i][j + 1] = false;
    }

    //? Up    ->  i-1, j
    if (isSafe(i - 1, j, row, col, arr, visited)) {
        // mark visited & goto next step
        visited[i - 1][j] = true;
        solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');

        //* backtracking  ->  to restore originality
        visited[i - 1][j] = false;
    }
}
//! TC:  4 ^ N
//* we're choosing 4 directions from each node
//! SC:  N  ( max_depth )

//* /////// /////// /////// /////// /////// /////// /////// reduced

void solveMazeReduced(int arr[][3], int row, int col, int i, int j,
                      vector<vector<bool>>& visited, vector<string>& path,
                      string output) {
    //? base case
    if (i == row - 1 && j == col - 1) {
        path.push_back(output);  //* answer found
        return;
    }

    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char direction[] = {'D', 'L', 'R', 'U'};

    //? this does the work for DOWN, LEFT, RIGHT, UP
    for (int k = 0; k < 4; k++) {
        int newx = i + dx[k];
        int newy = j + dy[k];
        char dir = direction[k];

        if (isSafe(newx, newy, row, col, arr, visited)) {
            // mark visited & goto next step
            visited[newx][newy] = true;
            solveMaze(arr, row, col, newx, newy, visited, path, output + dir);

            //* backtracking  ->  to restore originality
            visited[newx][newy] = false;
        }
    }
}

//* /////// /////// /////// /////// /////// /////// /////// /////// ///////
//? /////// /////// /////// /////// /////// /////// /////// /////// ///////
//! /////// /////// /////// /////// /////// /////// /////// /////// ///////

int main() {
    int maze[3][3] = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1},
    };
    int row = 3, col = 3;

    //* edge_case_1: when src = 0
    if (maze[0][0] == 0) {
        cout << "No path exists";
        return 0;
    }

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[0][0] = true;  // marking src = true;

    vector<string> path;
    string output = "";

    solveMaze(maze, row, col, 0, 0, visited, path, output);

    //* edge_case_2: when no paths pushed
    if (path.size() == 0) {
        cout << "No path found!";
        return 0;
    }

    cout << "\nprinting the results:\n";
    for (auto val : path) {
        cout << val << " ";
    }

    cout << endl << endl;
}