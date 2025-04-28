#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, long long>>> g;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int n, m;
long long dist[N][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0, a, b; i < m; i++) {
        long long c;
        cin >> a >> b >> c;
        g[a].emplace_back(make_pair(b, c));
    }
    priority_queue<tuple<long long, bool, int>> pq;
    memset(dist, 63, sizeof(dist));
    dist[1][0] = dist[1][1] = 0;
    pq.emplace(0, 0, 1);
    while (!pq.empty()) {
        auto [d, used, u] = pq.top();
        pq.pop();
        if (-d > dist[u][used]) continue;
        for (auto &[e, c] : g[u]) {
            if (!used && dist[u][0] + c / 2 < dist[e][1]) {
                dist[e][1] = dist[u][0] + c / 2;
                pq.emplace(dist[e][1], 1, e);
            }
            if (dist[u][used] + c < dist[e][used]) {
                dist[e][used] = dist[u][used] + c;
                pq.emplace(-dist[e][used], used, e);
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << "\n";
    return 0;
}