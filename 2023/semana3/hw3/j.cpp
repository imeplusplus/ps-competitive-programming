#include <bits/stdc++.h>

using namespace std;

/*

Fazer a ordenação topológica, porém, a pedido da questão, tem que priorizar as bebidas com índices menores.
Uma maneira de fazer isso: em vez do queue, colocar um set e sempre pegar da frente
Outra maneira: usar uma priority queue, e colocar o menor elemento na frente sempre
Essas duas maneiras estão no código.

Complexidade do código: O(n + m)

*/

vector<int> ans;

void topo_sort(int& n, vector<vector<int>>& adj) {
    ans.clear(); ans.resize(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        for (auto e : adj[i]) {
            in[e]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    int cur = 0;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ans[cur++] = u;
        for (auto e : adj[u]) {
            in[e]--;
            if (!in[e]) {
                q.push(e);
            }
        }
    }
}

void topo_sort(int& n, vector<vector<int>>& adj) {
    ans.clear(); ans.resize(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        for (auto e : adj[i]) {
            in[e]++;
        }
    }
    multiset<int> q;
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            q.insert(i);
        }
    }
    int cur = 0;
    while (!q.empty()) {
        int u = *q.begin();
        q.erase(q.begin());
        ans[cur++] = u;
        for (auto e : adj[u]) {
            in[e]--;
            if (!in[e]) {
                q.insert(e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ii = 1, n;
    while (cin >> n) {
        cout << "Case #" << ii++ << ": Dilbert should drink beverages in this order: ";
        map<string, int> id;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            id[s] = i;
            v[i] = s;
        }
        int m;
        cin >> m;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            adj[id[a]].push_back(id[b]);
        }
        topo_sort(n, adj);
        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                cout << v[ans[i]] << " ";
            }
            else {
                cout << v[ans[i]] << ".\n\n";
            }
        }
    }
    return 0;
}