#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int n, sz[N], lk[N], vis[N];
set<int> adj[N], cnt[N];
long long ans;

int find(int x) {
    while (x != lk[x]) x = lk[x];
    return x;
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    lk[y] = x;
    sz[x] += sz[y];
}

void dfs(int u, int p = -1) {
    vis[u] = 1;
    int x = find(u);
    vector<int> rm;
    for (auto e : adj[u]) {
        int y = find(e);
        if (x != y) {
            ans++;
            adj[e].erase(u);
            rm.push_back(e);
            continue;
        }
        if (!vis[e]) dfs(e, u);
    }
    for (auto e : rm) adj[u].erase(e);
}

void dfs2(int u, int i) {
    vis[u] = 1;
    int x = find(u);
    cnt[x].insert(i);
    for (auto e : adj[u]) {
        if (!vis[e]) dfs2(e, i);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m1, m2;
        cin >> n >> m1 >> m2;
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            lk[i] = i;
            vis[i] = 0;
            cnt[i].clear();
            adj[i].clear();
        }
        for (int i = 0, x, y; i < m1; i++) {
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        for (int i = 0, x, y; i < m2; i++) {
            cin >> x >> y;
            unite(x, y);
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        int comp = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs2(i, ++comp);
        }
        for (int i = 1; i <= n; i++) {
            ans += max(0ll, (long long)cnt[i].size() - 1ll);
        }
        cout << ans << "\n";
    }
}