#include <cassert>
#include <iostream>
using namespace std;

int main() {
  // ********1********
  // *******2*2*******
  // ******3*3*3******
  // *****4*4*4*4*****
  // ****5*5*5*5*5****
  // ***6*6*6*6*6*6***

  int n;
  cin >> n;

  assert(n <= 9);

  for (int row = 0; row < n; row++) {
    int start_index = 8 - row;
    int number = row + 1;
    int print_count = row + 1;
    for (int col = 0; col < 17; col++) {
      if (start_index == col && print_count > 0) {
        cout << number;
        start_index += 2;
        print_count--;
      } else {
        cout << "*";
      }
    }
    cout << endl;
  }
}