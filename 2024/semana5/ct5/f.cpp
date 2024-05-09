// complexidade: O((n + m) logn)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, f;
    cin >> n >> m >> f;
    map<int, long long> adj[n + 1];
    for(int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(adj[a].count(b)) {
            adj[a][b] = min(adj[a][b], c);
            adj[b][a] = min(adj[b][a], c);
        } else {
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }
    vector<vector<long long>> cost(n + 1, vector<long long>(2, 0x3f3f3f3f3f3f));
    vector<vector<bool>> vis(n + 1, vector<bool>(2, false));
    cost[1][0] = 0;
    vis[1][1] = true;
    typedef pair<long long, pair<int, bool>> plib;
    priority_queue<plib, vector<plib>, greater<plib>> pq;
    // plib = pair<long long, pair<int, bool>>
    // plib.first = long long -> custo
    // plib.second.first = int -> cidade
    // plib.second.second = bool -> já usei a tarifa fixa ou não
    pq.push({0, {1, 0}});

    // cost[i][0] guarda o menor custo sem usar a tarifa fixa em algum momento
    // e cost[i][1] guarda o menor custo usando a tarifa fixa em algum momento
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        int cidade = x.second.first;
        bool usei = x.second.second;
        if(vis[cidade][usei])
            continue;
        vis[cidade][usei] = true;
        for(auto e : adj[cidade]) {
            if(cost[e.first][usei] > cost[cidade][usei] + e.second) {
                cost[e.first][usei] = cost[cidade][usei] + e.second;
                pq.push({cost[e.first][usei], {e.first, usei}});
            }
            // se não usei e o preço dessa passagem é maior que a tarifa fixa, então posso usar essa tarifa fixa
            if(!usei and e.second > f) {
                if(cost[e.first][1] > cost[cidade][0] + f) {
                    cost[e.first][1] = cost[cidade][0] + f;
                    pq.push({cost[e.first][1], {e.first, 1}});
                }
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        long long o = min(cost[i][1], cost[i][0]);
        cout << (o == 0x3f3f3f3f3f3f ? -1 : o) << endl;
    }
    return 0;
}
