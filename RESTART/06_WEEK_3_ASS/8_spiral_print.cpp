//? https://leetcode.com/problems/spiral-matrix/description/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> arr = {
      {1, 2, 3, 4, 5},       //
      {6, 7, 8, 9, 10},      //
      {11, 12, 13, 14, 15},  //
      {16, 17, 18, 19, 20},  //
      {21, 22, 23, 24, 25},  //
  };

  int n = arr.size() * arr[0].size();
  int sr = 0, sc = 0;
  int er = arr.size() - 1, ec = arr[0].size() - 1;

  cout << "sr " << sr << endl;
  cout << "sc " << sc << endl;
  cout << "er " << er << endl;
  cout << "ec " << ec << endl;

  while (n > 0) {
    cout << "---";

    if (n > 0) {
      for (int col = sc; col <= ec; col++) {
        cout << arr[sr][col] << " ";
        n--;
      }
    }
    sr++;

    if (n > 0) {
      for (int row = sr; row <= er; row++) {
        cout << arr[row][ec] << " ";
        n--;
      }
    }
    ec--;

    if (n > 0) {
      for (int col = ec; col >= sc; col--) {
        cout << arr[er][col] << " ";
        n--;
      }
    }
    er--;

    if (n > 0) {
      for (int row = er; row >= sr; row--) {
        cout << arr[row][sc] << " ";
        n--;
      }
    }
    sc++;
  }
}