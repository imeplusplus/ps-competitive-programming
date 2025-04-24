#include <bits/stdc++.h>

using namespace std;
const int N = 3e4+5, INF = 0x3f3f3f3f;
bool vis[N];
vector<int> adj[N];

bool dfs(int s, int d){
    if(s == d) return true;
    if(vis[s]) return false;
    vis[s] = 1;
    bool ans = false;
    for(auto e : adj[s]){
        ans |= dfs(e, d);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t, x;
    cin >> n >> t;
    for(int i=1;i<=n-1;i++){
        cin >> x;
        adj[i].push_back(x+i);
    }
    if(dfs(1,t)) cout<< "YES\n";
    else cout << "NO\n";
    return 0;
}