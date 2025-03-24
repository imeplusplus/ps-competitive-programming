#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a4, a5, a3;
        cin >> a1 >> a2 >> a4 >> a5;
        map<int, int> m;
        m[a1 + a2]++;
        m[a4 - a2]++;
        m[a5 - a4]++;
        a3 = 0;
        for (auto [k, v] : m) a3 = max(a3, v);
        cout << a3 << "\n";
    }
}