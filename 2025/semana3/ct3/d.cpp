#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n;

void solve() {
    string a, b;
    cin >> a >> b;
    int na = a.size(), nb = b.size();
    int ia = 0, ib = 0;
    bool f = 1;
    f &= a[0] == b[0];
    while (ia < na && ib < nb) {
        int ra = ia, rb = ib;
        while (a[ra + 1] == a[ra]) ra++;
        while (b[rb + 1] == b[rb]) rb++;
        int ca = ra - ia + 1, cb = rb - ib + 1;
        f &= (2 * ca >= cb && cb >= ca);
        ia = ra + 1;
        ib = rb + 1;
    }
    f &= ia >= na && ib >= nb;
    cout << (f ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}