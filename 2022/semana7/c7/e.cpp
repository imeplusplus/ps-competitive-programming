/*
    Key idea: basically calculate the diameter of both trees and sum
*/

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n[2], vis[2][N], dist[2][N];
vector<int> adj[2][N];

void dfs(int u, int id){
    vis[id][u] = 1;  
    for(auto v : adj[id][u]){
        if(!vis[id][v]){
            dist[id][v] = dist[id][u] + 1;
            dfs(v, id);
        }
    }
}

int diameter_of_tree(int id){
    //first dfs
    dfs(1, id);
    
    //retrieve longest path
    pair<int, int> max_dist = {0, 0};
    for(int i = 1; i <= n[id]; i++){
        pair<int, int> current_dist = {dist[id][i], i};
        max_dist = max(max_dist, current_dist);
    }

    //dfs from the most distant vertex
    //reset vis and dist
    for(int i = 1; i <= n[id]; i++) vis[id][i] = dist[id][i] = 0;
    dfs(max_dist.nd, id);

    //save last path
    max_dist = {0, 0};
    //retrieve longest path
    for(int i = 1; i <= n[id]; i++){
        pair<int, int> current_dist = {dist[id][i], i};
        max_dist = max(max_dist, current_dist);
    }
    return max_dist.st;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    for(int i = 0; i < 2; i++){
        cin >> n[i];
        for(int j = 1; j < n[i]; j++){
            int u, v;
            cin >> u >> v;
            adj[i][u].push_back(v);
            adj[i][v].push_back(u);
        }
        //number of nodes is diameter + 1
        ans += diameter_of_tree(i) + 1;
    }
    cout << ans << "\n";
    return 0;
}