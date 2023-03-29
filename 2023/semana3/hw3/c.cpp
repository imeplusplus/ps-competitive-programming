#include <bits/stdc++.h>

using namespace std;

/*

Veja que é necessário contar quantas vezes consecutivamente os gatos aparecem no meio do dfs.
Para fazer isso, basta passar um contador no dfs, e quando não houver um gato, resetar para zero.
No final, verificar se chegou em uma folha, caso sim, adicionar +1 na resposta.

Complexidade do código: O(n + m);

*/

const int N = 1e5 + 7;

vector<int> adj[N];
int v[N];
bool vis[N];
int ans = 0, n, m;

//o par aqui é curto para "parent". já que estamos descendo a árvore, sabemos que o nó não poderá voltar para o pai, então somente arrastar quem é durante o dfs.
void dfs(int x, int par = -1, int cnt = 0) {
    vis[x] = true;
    if(v[x]) {
        cnt++;
    } else {
        cnt = 0;
    }
    //caso o contador passe do limite, pode parar o dfs aqui
    if(cnt > m) {
        return;
    }
    for(int i = 0; i < adj[x].size(); i++) {
        if(!vis[adj[x][i]]) {
            dfs(adj[x][i], x, cnt);
        }
    }
    //verificação de se é uma folha, a outra condição é para não haver confusão com a origem
    if(adj[x].size() == 1 and x) {
        ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        //nesse caso acabei querendo usar os nós 0-indexado, assim eu subtraio um de cada vez
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}