#include <bits/stdc++.h>

using namespace std;

/*

Somente fazer o dfs e ver se a partir do nó 1, é possível chegar no nó t;

Complexidade do código: O(n)

*/

const int N = 3e4 + 7;
int v[N];
bool vis[N];
vector<int> adj[N];

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        if(!vis[adj[u][i]]) {
            dfs(adj[u][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    for(int i = 1; i < n; i++) {
        cin >> v[i];
        adj[i].push_back(i + v[i]);
    }
    dfs(1);
    cout << (vis[t] ? "YES\n" : "NO\n");
    return 0;
}
