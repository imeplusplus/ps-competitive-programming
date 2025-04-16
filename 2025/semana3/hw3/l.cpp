// é fácil ver que a resposta acaba sendo a quantidade de folhas que os nós podem chegar, multiplicados.
// basta fazer um dfs antes para precalcular esses valores

// Complexidade: O(n)

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

vector<int> adj[N];

int leaves[N];

void dfs(int u, int p = 0) {
    if(u != 1 and adj[u].size() == 1) {
        leaves[u]++;
    }
    for(auto e : adj[u]) {
        if(e != p) {
            dfs(e, u);
            leaves[u] += leaves[e];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            leaves[i] = 0;
        }
        for(int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1);
        int q;
        cin >> q;
        while(q--) {
            int a, b;
            cin >> a >> b;
            cout << 1ll * leaves[a] * leaves[b] << "\n";
        }
    }
    return 0; 
}
