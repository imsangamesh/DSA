//*
//* ◉ ● ⇒
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(char first, char second) { return first > second; }

int main() {
    //! --------------------- CUSTOM COMPARATOR
    string str = "saninepinklin";
    sort(str.begin(), str.end());
    cout << str << endl;

    sort(str.begin(), str.end(), cmp);
    cout << str << endl;
}