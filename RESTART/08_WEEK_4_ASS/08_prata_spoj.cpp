//?
//* -------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//* -------------------------------------------

bool canCooksCookAllPratasInGivenTime(vector<int> ranks, int pratas,
                                      int limit) {
  for (int rank : ranks) {
    int totalTime = 0;
    int c = 1;  // Iterator

    while (totalTime + c * rank <= limit) {
      totalTime += c * rank;
      c++;
      pratas--;

      if (pratas == 0) return true;
    }
  }

  cout << limit << "  Pratas left: " << pratas << endl;
  return pratas <= 0;
}

int main() {
  cout << endl;
  vector<int> ranks = {1, 2, 3, 4};
  int pratas = 10;
  int ans = -1;

  int s = 0;
  int e = (pratas * (pratas + 1) / 2) * ranks[ranks.size() - 1];

  while (s <= e) {
    int m = s + ((e - s) >> 1);

    if (canCooksCookAllPratasInGivenTime(ranks, pratas, m)) {
      ans = m;
      e = m - 1;
    } else {
      s = m + 1;
    }
  }

  cout << "\nAnswer is: " << ans;
  cout << endl << endl;
}