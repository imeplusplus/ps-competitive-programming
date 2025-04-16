#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, double>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, log(c)});
        adj[b].push_back({a, log(c)});
    }
    vector<double> dist(n + 1, 1e9);
    dist[1] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        if(dist[p.second] != p.first) continue;
        for(auto e : adj[p.second]) {
            if(dist[e.first] > p.first + e.second) {
                dist[e.first] = p.first + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }
    cout << dist[n] / log(7) << "\n";
    return 0;
}
