#include <bits/stdc++.h>

using namespace std;

/*

Fazer a ordenação topológica

Complexidade do código: O(n + m)

*/

vector<int> ans;

void topo_sort(int &n, vector<vector<int>> &adj) {
    ans.clear(); ans.resize(n);
    vector<int> in(n);
    for(int i = 0; i < n; i++) {
        for(auto e : adj[i]) {
            in[e]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(!in[i]) {
            q.push(i);
        }
    }
    int cur = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans[cur++] = u;
        for(auto e : adj[u]) {
            in[e]--;
            if(!in[e]) {
                q.push(e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        if(!n and !m) {
            break;
        }
        vector<vector<int>> adj(n);
        while(m--) {
            int u, v;
            cin >> u >> v;
            adj[--u].push_back(--v);
        }
        topo_sort(n, adj);
        for(auto e : ans) {
            cout << e + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}