#include <bits/stdc++.h>

using namespace std;

/*

O objetivo do dfs nesse caso será encontrar quais pontos você pode chegar partido de cada um que não foi ainda visitado.
A quantidade de vezes que você terá que fazer será a quantidade de conjuntos disjuntos que existem de pontos, assim a resposta
será esse valor - 1;

Complexidade do código: O(n^2)

*/

const int N = 107;

bool vis[N];
pair<int, int> v[N];
int n;

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < n; i++) {
        if(!vis[i] and (v[u].first == v[i].first or v[u].second == v[i].second)) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans - 1 << "\n";
    return 0;
}
