#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5, M = 1e9 + 7;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int mx = -1;
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++) {
        int inv = 0;
        for (int j = i; j < n; j++) {
            if (v[j] < v[i])
                inv++;
            else if (v[j] > v[i])
                inv--;
            if (inv > mx) mx = inv, ans = {i, j};
        }
    }
    cout << ans.first + 1 << " " << ans.second + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}