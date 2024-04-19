#include <bits/stdc++.h>

using namespace std;

// try to color the nodes of the graph in black or white so that no two adjacent nodes have the same color

// complexidade: O(n + m)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int tst = 1; tst <= t; tst++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool foi = true;
        vector<int> color(n + 1, -1);
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                color[i] = 1;
                q.push(i);
                // bfs, if the node isn't currently colored
                while(!q.empty()) {
                    int x = q.front(); q.pop();
                    for(auto e : adj[x]) {
                        if(color[e] != -1) {
                            if(color[e] != color[x] ^ 1) {
                                foi = false;
                            }
                        } else {
                            color[e] = color[x] ^ 1;
                            q.push(e);
                        }
                    }
                }
            }
        }
        cout << "Scenario #" << tst << ":\n";
        if(foi) {
            cout << "No suspicious bugs found!\n";
        } else {
            cout << "Suspicious bugs found!\n";
        }
    }
    return 0;
}
