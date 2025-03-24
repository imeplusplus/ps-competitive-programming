#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        multiset<pair<long long, vector<long long>>> s;
        for (int i = 0; i < n; i++) {
            vector<long long> v(m);
            long long sm = 0;
            for (int i = 0; i < m; i++) {
                cin >> v[i];
                sm += v[i];
                v[i] = -v[i];
            }
            s.emplace(-sm, v);
        }
        vector<long long> v;
        for (auto [k, val] : s) v.insert(v.end(), val.begin(), val.end());
        long long ans = 0, prev = -1;
        for (int i = 0; i < n * m; i++) {
            ans += -v[i];
            if (prev == -1) {
                prev = -v[i];
            } else {
                ans += prev;
                prev += -v[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}