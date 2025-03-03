#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s = {1, 2, 3, 4, 5};
    for (int i = 0, x; i < 4; i++) {
        cin >> x;
        s.erase(x);
    }
    cout << *s.begin();
}