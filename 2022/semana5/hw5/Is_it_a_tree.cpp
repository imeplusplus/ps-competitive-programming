#include <bits/stdc++.h>

using namespace std;

/*

Se lembrar das condições necessárias para a existência de uma árvore:
acíclica
todos os nós conectados

Complexidade do Código: O(n + m);

*/

const int N = 1e5 + 7;

vector<int> adj[N];
bool vis[N], pode = true;

void dfs(int x, int par = -1) {
    vis[x] = true;
    for (auto e : adj[x]) {
        if (!vis[e]) {
            dfs(e, x);
        }
        else if (e != par) {
            pode = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            pode = false;
        }
    }
    cout << (pode ? "YES\n" : "NO\n");
    return 0;
}
