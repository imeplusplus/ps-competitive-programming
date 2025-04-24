#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
vector<int> adj[N];
int v[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        adj[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    if (m & 1) {
        ans = INF;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() & 1)
                ans = min(ans, v[i]);
            else {
                for (auto e : adj[i]) {
                    if (!(adj[e].size() & 1)) ans = min(ans, v[i] + v[e]);
                }
            }
        }
    }
    cout << ans << "\n";
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