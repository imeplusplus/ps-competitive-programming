//Слава Україні, Героям слава 

#include <bits/stdc++.h>

using namespace std;

// djikstra from the exit node

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, e, t;
        cin >> n >> e >> t;
        int m;
        cin >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        while(m--) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[v].push_back({u, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[e] = 0;
        q.push({0, e});
        while(!q.empty()) {
            auto p = q.top(); q.pop();
            for(auto x : adj[p.second]) {
                if(dist[x.first] > dist[p.second] + x.second) {
                    dist[x.first] = dist[p.second] + x.second;
                    q.push({dist[x.first], x.first});
                }
            }
        }
        int ans = 0;
        for(auto e : dist) {
            if(e <= t) {
                ans++;
            }
        }
        cout << ans << "\n";
        if(tt) {
            cout << "\n";
        }
    }
    return 0;
}