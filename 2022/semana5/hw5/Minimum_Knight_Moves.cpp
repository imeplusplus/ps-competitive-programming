#include <bits/stdc++.h>

using namespace std;

/*

Fazer um bfs, no sentido de que da peça original, você vai procurando as posições possíveis de chegar e está mexendo toda peça
possível ao mesmo tempo, assim na primeira vez que chegar no lugar que se quer, já sabe que a quantidade que precisou para chegar
será a resposta. Caso usasse dfs, teria que passar por tudo e depois ficar comparando os valores encontrados.

Complexidade do código: O(t * 64);

*/

//o dx e dy representam os 8 movimentos possíveis que o cavalo pode fazer
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
bool vis[9][9];

int bfs(pair<int, int> a, pair<int, int> b) {
    //o primero número do pair representa a quantidade de passos andados
    queue<pair<int, pair<int, int>>> q;
    memset(vis, false, sizeof(vis));
    int ans = 0;
    vis[a.first][a.second] = true;
    q.push({0, a});
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        if(p.second == b) {
            ans = p.first;
            break;
        }
        for(int i = 0; i < 8; i++) {
            //nesse if, estou conferindo se efetuar o movimento no cavalo vai ainda deixar ele dentro do board
            if(p.second.first + dx[i] >= 1 and p.second.first + dx[i] <= 8 and p.second.second + dy[i] >= 1
             and p.second.second + dy[i] <= 8 and !vis[p.second.first + dx[i]][p.second.second + dy[i]]) {
                vis[p.second.first + dx[i]][p.second.second + dy[i]] = true;
                q.push({p.first + 1, {p.second.first + dx[i], p.second.second + dy[i]}});
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        pair<int, int> start = {a[0] - 'a' + 1, a[1] - '0'};
        pair<int, int> finish = {b[0] - 'a' + 1, b[1] - '0'};
        cout << bfs(start, finish) << "\n";
    }
    return 0;
}
