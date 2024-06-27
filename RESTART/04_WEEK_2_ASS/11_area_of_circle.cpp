#include <iostream>
using namespace std;

int areaOfCircle(int r) { return 3.142 * r * r; }

int main() {
  int n;
  cin >> n;

  cout << "Area of circle is: " << areaOfCircle(n);
}