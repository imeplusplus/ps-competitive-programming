#include <bits/stdc++.h>
 
using namespace std;

// do a topological sort and then check if it succeded
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1), ans;
    queue<int> q;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in[b]++;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {
        if(!in[i]) {
            q.push(i);
        }
    }
    int ord = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        ans.push_back(x);
        ord++;
        for(auto e : adj[x]) {
            in[e]--;
            if(!in[e]) {
                q.push(e);
            }
        }
    }
    if(ord != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
