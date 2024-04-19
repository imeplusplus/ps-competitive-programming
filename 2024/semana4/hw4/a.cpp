#include <bits/stdc++.h>
 
using namespace std;
 
bool ispr(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}
 
bool pode(string a, string b) {
    int diff = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            diff++;
        }
    }
    return diff == 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> pr;
    for(int i = 1000; i < 10000; i++) {
        if(ispr(i)) {
            pr.push_back(i);
        }
    }
    vector<vector<int>> adj(pr.size() + 1);
    // precalculo todas as adjacencias possiveis entre números
    for(int i = 0; i < pr.size(); i++) {
        for(int j = i + 1; j < pr.size(); j++) {
            if(pode(to_string(pr[i]), to_string(pr[j]))) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << "\n";
            continue;
        }
        int inda = lower_bound(pr.begin(), pr.end(), a) - pr.begin();
        int indb = lower_bound(pr.begin(), pr.end(), b) - pr.begin();
        vector<int> vis(pr.size() + 1);
        vis[inda] = true;
        queue<pair<int, int>> q;
        q.push({0, inda});
        int ans = 0;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.second == indb) {
                ans = p.first;
                break;
            }
            for(auto e : adj[p.second]) {
                if(!vis[e]) {
                    vis[e] = true;
                    q.push({p.first + 1, e});
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
} 
