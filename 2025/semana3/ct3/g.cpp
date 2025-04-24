#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c, n;
    cin >> c >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    multiset<int> s;
    int l = 0, ans = 1e9;
    for (int r = 0; r < n; r++) {
        s.insert(v[r]);
        if (r - l == c) {
            int mx = *s.rbegin();
            ans = min(ans, mx);
            while (v[l] != mx) s.erase(s.find(v[l])), l++;
            s.erase(s.find(v[l])), l++;
        }
    }
    cout << ans << "\n";
    return 0;
}