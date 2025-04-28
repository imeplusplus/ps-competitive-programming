#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n;

void solve() {
    cin >> n;
    set<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.insert(x);
    }
    cout << v.size() << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}