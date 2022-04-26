#include <bits/stdc++.h>

using namespace std;

/*

Encontrar os possíveis nós que possam compor o diâmetro. Sabe-se que para esses, a resposta será o diâmetro + 1.
Caso não seja parte do diâmetro, a resposta será somente o diâmetro. Dessa vez, fiz com bfs.

Complexidade do Código: O(3 * (2 * n - 1));

*/

vector<vector<int>> adj;
vector<int> dist;
vector<bool> vis;

int bfs(int x) {
    int ans = 0, mx = 0;
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto e : adj[u]) {
            if (!vis[e]) {
                dist[e] = dist[u] + 1;
                if (dist[e] > mx) {
                    mx = dist[e];
                    ans = e;
                }
                vis[e] = true;
                q.push(e);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n); vis.resize(n); dist.resize(n);
    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    int node = bfs(0);
    dist.clear(); dist.resize(n);
    vis.clear(); vis.resize(n);
    node = bfs(node);
    int mx = *max_element(dist.begin(), dist.end());
    for (int i = 0; i < n; i++) {
        ans[i] = mx + (mx == dist[i]);
    }
    dist.clear(); dist.resize(n);
    vis.clear(); vis.resize(n);
    bfs(node);
    mx = *max_element(dist.begin(), dist.end());
    for (int i = 0; i < n; i++) {
        ans[i] = max(ans[i], mx + (mx == dist[i]));
    }
    for (auto e : ans) {
        cout << e << "\n";
    }
    return 0;
}
