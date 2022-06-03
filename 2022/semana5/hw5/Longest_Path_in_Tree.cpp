//Слава Україні, Героям слава 🇺🇦

#include <bits/stdc++.h>

using namespace std;

/*

Encontrar o diâmetro da árvore: faça o dfs em um nó qualquer, e pegue o nó mais longe deste. Faça novamente o dfs, mas
dessa vez a partir do nó encontrado, a maior distância encontrada será o diâmetro.

Complexidade do Código: O(n + m);

*/

const int N = 1e4 + 7;

vector<int> adj[N];
int dist[N];

void dfs(int x, int par = -1) {
    for(auto e : adj[x]) {
        if(e != par) {
            dist[e] = dist[x] + 1;
            dfs(e, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int node = -1, mx = *max_element(dist, dist + n + 1);
    for(int i = 1; i <= n; i++) {
        if(dist[i] == mx) {
            node = i;
            break;
        }
    }
    memset(dist, 0, sizeof(dist));
    dfs(node);
    cout << *max_element(dist, dist + n + 1) << "\n";
    return 0;
}
